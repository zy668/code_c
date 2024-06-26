#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 1000       // 最大天数
#define MAX_TRANSACTIONS 11 // 最多交易次数（0-10）
#define MAX_STOCKS 21       // 最多股票数（0-20）

int consume(int prices[], int fee, int n)
{
  // int n = sizeof(prices) / sizeof(prices[0]);
  // int n = 4;
  if (n < 2)
  {
    return 0;
  }
  if (n == 2)
  {
    return (prices[1] - prices[0] - 2 * fee) > 0 ? (prices[1] - prices[0] - 2 * fee) : 0;
  }
  // if (n == 3)
  // {
  //   int min = prices[0];
  //   int max = prices[1];
  //   int profit = max - min - 2 * fee;
  //   if (profit < 0)
  //   {
  //     min = prices[1];
  //     max = prices[2];
  //     profit = max - min - 2 * fee;
  //   }
  //   return profit > 0 ? profit : 0;
  // }
  int buy[2] = {prices[0] + 2 * fee, prices[1] + 2 * fee};
  int profit = 0;
  for (int i = 2; i < n; i++)
  {
    if (prices[i] + 2 * fee < buy[1])
    {
      if (buy[0] > buy[1])
      {
        buy[0] = buy[1];
      }
      else
      {
        if (buy[1] - buy[0] > 2 * fee)
        {
          profit += buy[1] - buy[0] - 2 * fee;
          buy[0] = buy[1]; // ？
        }
      }
      buy[1] = prices[i] + 2 * fee;
    }
    else if (prices[i] + 2 * fee < buy[0])
    {
      buy[0] = buy[1];
      buy[1] = prices[i] + 2 * fee;
    }
    else if (prices[i] > buy[1] || prices[i] > buy[0])
    {
      if (buy[0] < buy[1])
      {
        profit += prices[i] - buy[0];
        buy[0] = prices[i];
      }
      else
      {
        profit += prices[i] - buy[1];
        buy[1] = prices[i];
      }
    }
  }
  // if (profit == 0)
  // {
  //   return prices[1] - prices[0] - 2 * fee > 0 ? prices[1] - prices[0] - 2 * fee : 0;
  // }
  return profit;
}

int main()
{
  srand(time(NULL)); // 随机种子

  int max_profit = 0;
  int fee = 0;
  //[79, 70, 7, 48, 0, 60]
  int prices[] = {3, 6, 1, 7, 9};
  max_profit = 10 * consume(prices, fee, 5);
  printf("Maximum profit: %d\n", max_profit);
  // printf("First 10 days prices:");
  // for (int i = 0; i < 10 && i < 6; i++)
  // {
  //   printf(" %d", prices[i]);
  // }
  // printf("\n");
  // printf("Transaction fee: %d\n", fee);

  return 0;
}