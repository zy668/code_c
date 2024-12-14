#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#define BUFFER_SIZE 5 // 缓冲区大小

int buffer[BUFFER_SIZE];
int in = 0;  // 指向下一个插入位置
int out = 0; // 指向下一个取出位置

sem_t empty;           // 表示空缓冲区单元的信号量
sem_t full;            // 表示已占用缓冲区单元的信号量
pthread_mutex_t mutex; // 保护缓冲区的互斥量
void insert_item(int item)
{
  buffer[in] = item;
  in = (in + 1) % BUFFER_SIZE;
}

int remove_item()
{
  int item = buffer[out];
  out = (out + 1) % BUFFER_SIZE;
  return item;
}
void *producer(void *param)
{
  int id = *((int *)param); // 转换参数为整数ID
  int item;
  unsigned int seed = time(NULL) ^ pthread_self();
  srand(seed);
  while (1)
  {
    sleep(rand() % 3);

    item = rand() % 1000;

    sem_wait(&empty);
    pthread_mutex_lock(&mutex);

    insert_item(item);
    printf("Producer %d produced +++ %d\n", id, item);

    pthread_mutex_unlock(&mutex);
    sem_post(&full);
  }
  return NULL;
}
void *consumer(void *param)
{
  int id = *((int *)param); // 转换参数为整数ID
  int item;
  while (1)
  {
    sleep(rand() % 3); // 随机睡眠0-2秒

    sem_wait(&full);
    pthread_mutex_lock(&mutex);

    item = remove_item();
    printf("Consumer %ld consumed --- %d\n", id, item);

    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
  }
  return NULL;
}
int main(int argc, char *argv[])
{
  srand(time(NULL));
  if (argc != 4)
  {
    fprintf(stderr, "Usage: %s <sleep_time> <producer_count> <consumer_count>\n", argv[0]);
    return -1;
  }
  int sleep_time = atoi(argv[1]);
  int producer_count = atoi(argv[2]);
  int consumer_count = atoi(argv[3]);

  pthread_t producers[producer_count];
  pthread_t consumers[consumer_count];

  // 初始化信号量和互斥量，检查返回值
  if (sem_init(&empty, 0, BUFFER_SIZE) == -1 ||
      sem_init(&full, 0, 0) == -1 ||
      pthread_mutex_init(&mutex, NULL) != 0)
  {
    perror("Init failed");
    return -1;
  }

  // 创建生产者线程
  // 在main函数中创建线程时
  int producer_ids[producer_count];
  for (int i = 0; i < producer_count; i++)
  {
    producer_ids[i] = i + 1; // 生成1~n的编号
    if (pthread_create(&producers[i], NULL, producer, &producer_ids[i]) != 0)
    {
      perror("Failed to create producer thread");
      return -1;
    }
  }

  // 创建消费者线程
  int consumer_ids[consumer_count];
  for (int i = 0; i < consumer_count; i++)
  {
    consumer_ids[i] = i + 1; // 生成1~n的编号
    if (pthread_create(&consumers[i], NULL, consumer, &consumer_ids[i]) != 0)
    {
      perror("Failed to create consumer thread");
      return -1;
    }
  }

  // 主线程睡眠指定时间
  sleep(sleep_time);

  // 清理资源
  for (int i = 0; i < producer_count; i++)
  {
    pthread_cancel(producers[i]);
    pthread_join(producers[i], NULL);
  }

  for (int i = 0; i < consumer_count; i++)
  {
    pthread_cancel(consumers[i]);
    pthread_join(consumers[i], NULL);
  }

  // 销毁信号量和互斥量
  sem_destroy(&empty);
  sem_destroy(&full);
  pthread_mutex_destroy(&mutex);

  printf("Main thread exiting.\n");
  return 0;
}
