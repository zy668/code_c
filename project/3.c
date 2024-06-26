#include <stdio.h>
#include <stdlib.h>

//全局变量定义
int mine_num, row, col, flag = 0, count = 0, times = 0; //地雷数量，行数，列数，旗帜数量，已点击的方格数量，操作次数 
int map[26][32] = {0}; //地图存储数组
int click[26][32] = {0}; //记录点击状态的数组

typedef struct position { //定义一个位置结构体
    int x;
    int y;
} pos;

typedef struct queue { //定义一个队列结构体
    pos p[720];
    int front;
    int rear;
} queue;

//函数定义
void push(queue *q, pos *t); //将位置推入队列
pos pop(queue *q); //从队列中弹出位置
void createMine(void); //创建地雷
int init(int n); //初始化游戏
void print(int n); //打印游戏状态
int leftClick(int x, int y); //左键点击
void rightClick(int n, int x, int y); //右键点击
int doubleClick(int x, int y); //双键点击
void open(int x, int y); //打开一个位置
int game(void); //进行一次游戏操作

//主函数
int main(void) {
    int n;
    scanf("%d", &n); //读取游戏难度级别

    if (init(n) == 0) {//初始化游戏
        return 0;
    }

    createMine();//创建地雷

    while (1) {
        if (game() || count == row * col - mine_num) { //进行一次游戏操作，或者已点击的方格数量等于所有方格数量减去地雷数量
            break;
        }
    }

    return 0;
}

//将位置推入队列
void push(queue *q, pos *t) {
    q->p[q->rear].x = t->x;
    q->p[q->rear].y = t->y;
    q->rear++;
}

//从队列中弹出位置
pos pop(queue *q) {
    pos temp = q->p[q->front];
    q->front++;
    return temp;
}

//创建地雷
void createMine(void) {
    int i, j, k, x, y;

    for (i = 1; i <= row; i++) {
        for (j = 1; j <= col; j++) {
            k = getchar();

            if (k == '*') { //如果读取到'*'，则设置地雷
                map[i][j] = -15;

                for (x = i - 1; x <= i + 1; x++) {
                    for (y = j - 1; y <= j + 1; y++) {
                        map[x][y]++;
                    }
                }
            }
        }
        getchar();
    }
}

//初始化游戏
int init(int n) {
	//根据游戏难度级别设置地雷数量和地图大小
    if (n == 1) {
        mine_num = 10;
        row = 9;
        col = 9;
    } else if (n == 2) {
        mine_num = 40;
        row = 16;
        col = 16;
    } else if (n == 3) {
        mine_num = 99;
        row = 16;
        col = 30;
    } else if (n == 4) {
        scanf("%d %d %d", &row, &col, &mine_num);

        if (row > 24 || col > 30 || mine_num < 10 || 10 * mine_num > 9 * row * col || row <= 0 || col <= 0) {
            return 0;
        }
    }

    getchar();
    return 1;
}

//打印游戏状态
void print(int n) {
    int i, j;
    times++;

    if (count == row * col - mine_num || n == 1) {
        for (i = 1; i <= row; i++) {
            for (j = 1; j <= col; j++) {
                if (map[i][j] < 0) {
                    click[i][j] = 1;
                }
            }
        }

        if (n == 1) {
            printf("Hit mine, you lose\n");
        } else {
            printf("Game over, you win\n");
        }
    } else {
        printf("Game in progress\n");
    }

    printf("%d %d\n", times, mine_num - flag);

    for (i = 1; i <= row; i++) {
        for (j = 1; j <= col; j++) {
            if (click[i][j] == 0) {
                putchar('.');
            } else if (click[i][j] > 0) {
                if (map[i][j] >= 0) {
                    printf("%d", map[i][j]);
                } else {
                    putchar('*');
                }
            } else if (click[i][j] == -1) {
                putchar('!');
            } else {
                putchar('?');
            }
        }
        putchar('\n');
    }
}

//左键点击
int leftClick(int x, int y) {
    if (x < 1 || x > row || y < 1 || y > col || click[x][y] == 1 || click[x][y] == -1) {
        print(0);
        return 0;
    }

    if (map[x][y] < 0) {
        print(1);
        return 1;
    }

    open(x, y);
    print(0);
    return 0;
}

//右键点击
void rightClick(int n, int x, int y) {
    if (x < 1 || x > row || y < 1 || y > col || click[x][y] == 1) {
        print(0);
        return;
    }

    if (n == 2) {
        if (click[x][y] != -1) {
            flag++;
            click[x][y] = -1;
        }
    } else {
        if (click[x][y] == -1) {
            flag--;
        }
        if (n == 3) {
            click[x][y] = -2;
        } else {
            click[x][y] = 0;
        }
    }

    print(0);
}

//双键点击
int doubleClick(int x, int y) {
    if (x < 1 || x > row || y < 1 || y > col || click[x][y] != 1) {
        print(0);
        return 0;
    }

    int i, j, k = 0, c = 0;

    for (i = x - 1; i <= x + 1; i++) {
        for (j = y - 1; j <= y + 1; j++) {
            if (click[i][j] == -1) {
                k++;
            }
            if (click[i][j] != 1 && click[i][j] != -1 && map[i][j] < 0) {
                c = 1;
            }
        }
    }

    if (k == map[x][y] && k > 0) {
        if (c == 1) {
            print(1);
            return 1;
        }

        for (i = x - 1; i <= x + 1; i++) {
            for (j = y - 1; j <= y + 1; j++) {
                if (i < 1 || i > row || j < 1 || j > col) {
                    continue;
                }
                if (click[i][j] != 1 && click[i][j] != -1) {
                    open(i, j);
                }
            }
        }
    }

    print(0);
    return 0;
}

// 打开一个位置
void open(int x, int y) {
    int i;
    int dir[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
        {0, 1}, {1, -1}, {1, 0}, {1, 1}
    };
    queue q;
    q.front = q.rear = 0;
    pos t = {x, y};
    push(&q, &t);
    click[x][y] = 1;

    while (q.front != q.rear) {
        t = pop(&q);
        count++;

        if (map[t.x][t.y] == 0) {
            for (i = 0; i < 8; i++) {
                pos temp = {t.x + dir[i][0], t.y + dir[i][1]};

                if (temp.x < 1 || temp.x > row || temp.y < 1 || temp.y > col || click[temp.x][temp.y] == 1 || click[temp.x][temp.y] == -1) {
                    continue;
                }

                push(&q, &temp);
                click[temp.x][temp.y] = 1;
            }
        }
    }
}

// 游戏主循环
int game(void) {
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);

    if (n == 1) {
        return leftClick(x, y);
    } else if (n == 9) {
        return doubleClick(x, y);
    } else {
        rightClick(n, x, y);
        return 0;
    }
}