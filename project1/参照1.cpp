#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define ROW 10                               // 行数
#define COL 10                               // 列数
#define BLOCK_SIZE 40                         // 方块大小
#define MINE_NUM 10                           // 地雷数量
#define WINDOW_WIDTH (COL * BLOCK_SIZE)       // 窗口宽度
#define WINDOW_HEIGHT (ROW * BLOCK_SIZE)      // 窗口高度

int mineMap[ROW][COL] = {0};                  // 地图数组
bool isClicked[ROW][COL] = {false};           // 是否被点击
int clickCount = 0;                           // 点击次数

IMAGE block_0, block_1, block_2, block_3, block_4, block_5, block_6, block_7, block_8, block_9, block_flag, block_mine, block_boom;

void init();                                  // 初始化函数
void generateMines();                         // 随机生成地雷
void drawMap();                               // 绘制地图
void gameOver(int win);                       // 游戏结束
bool isWin();                                 // 判断是否胜利
int getMineCount(int x, int y);               // 获取周围地雷数量
void click(int x, int y);                     // 点击事件处理函数
void showBlock(int x, int y);                 // 显示方块
void markFlag(int x, int y);                  // 标记旗帜

int main()
{
    init();
    generateMines();
    drawMap();

    while (true)
    {
        if (_kbhit())                           // 判断是否有按键按下
        {
            char c = _getch();
            if (c == 'q' || c == 'Q')            // 按下 q 键结束游戏
                break;
        }

        if (clickCount == ROW * COL - MINE_NUM)  // 如果所有方块都被点击了，则游戏胜利
        {
            gameOver(1);
            break;
        }

        if (isWin())                            // 如果所有地雷都被标记了，则游戏胜利
        {
            gameOver(1);
            break;
        }

        if (MouseHit())                         // 判断是否有鼠标事件
        {
            MOUSEMSG msg = GetMouseMsg();
            if (msg.uMsg == WM_LBUTTONDOWN)     // 鼠标左键按下
            {
                int x = msg.x / BLOCK_SIZE;
                int y = msg.y / BLOCK_SIZE;
                if (!isClicked[y][x])           // 如果方块没有被点击过
                {
                    click(x, y);
                    clickCount++;
                }
            }
            else if (msg.uMsg == WM_RBUTTONDOWN) // 鼠标右键按下
            {
                int x = msg.x / BLOCK_SIZE;
                int y = msg.y / BLOCK_SIZE;
                if (!isClicked[y][x])           // 如果方块没有被点击过
                    markFlag(x, y);
            }
        }
    }

    closegraph();
    return 0;
}

void init()
{
    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
    setbkcolor(WHITE);

    // 加载图片
    loadimage(&block_0, "block_0.png");
    loadimage(&block_1, "block_1.png");
    loadimage(&block_2, "block_2.png");
    loadimage(&block_3, "block_3.png");
    loadimage(&block_4, "block_4.png");
    loadimage(&block_5, "block_5.png");
    loadimage(&block_6, "block_6.png");
    loadimage(&block_7, "block_7.png");
    loadimage(&block_8, "block_8.png");
    loadimage(&block_9, "block_9.png");
    loadimage(&block_flag, "block_flag.png");
    loadimage(&block_mine, "block_mine.png");
    loadimage(&block_boom, "block_boom.png");
}

void generateMines()
{
    srand(time(NULL));                         // 用当前时间作为随机数种子
    int count = 0;
    while (count < MINE_NUM)
    {
        int x = rand() % COL;
        int y = rand() % ROW;
        if (mineMap[y][x] == 0)                 // 如果该位置没有地雷，则放置地雷
        {
            mineMap[y][x] = 9;
            count++;
        }
    }
}

void drawMap()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            int x = j * BLOCK_SIZE;
            int y = i * BLOCK_SIZE;
            putimage(x, y, &block_0);           // 绘制空白方块
        }
    }
}

void gameOver(int win)
{
    char message[20];
    if (win)
        sprintf(message, "You Win!");
    else
        sprintf(message, "Game Over");

    settextcolor(RED);
    settextstyle(60, 0, "Consolas");
    outtextxy(WINDOW_WIDTH / 2 - 150, WINDOW_HEIGHT / 2 - 30, message);
}

bool isWin()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (mineMap[i][j] == 9 && !isClicked[i][j])  // 如果有地雷没有被标记，则游戏未胜利
                return false;
        }
    }
    return true;
}

int getMineCount(int x, int y)
{
    int count = 0;
    for (int i = y - 1; i <= y + 1; i++)
    {
        for (int j = x - 1; j <= x + 1; j++)
        {
            if (i >= 0 && i < ROW && j >= 0 && j < COL && mineMap[i][j] == 9) // 如果该位置有地雷
                count++;
        }
    }
    return count;
}

void click(int x, int y)
{
    if (mineMap[y][x] == 9)                     // 如果点击的方块是地雷
    {
        putimage(x * BLOCK_SIZE, y * BLOCK_SIZE, &block_boom);  // 显示地雷爆炸的图片
        gameOver(0);
    }
    else if (mineMap[y][x] == 0)                // 如果点击的方块周围没有地雷
    {
        showBlock(x, y);
    }
    else                                        // 如果点击的方块周围有地雷
    {
        switch (getMineCount(x, y))
        {
        case 0:
            putimage(x * BLOCK_SIZE, y * BLOCK_SIZE, &block_0);
            break;
        case 1:
            putimage(x * BLOCK_SIZE, y * BLOCK_SIZE, &block_1);
            break;
        case 2:
            putimage(x * BLOCK_SIZE, y * BLOCK_SIZE, &block_2);
            break;
        case 3:
            putimage(x * BLOCK_SIZE, y * BLOCK_SIZE, &block_3);
            break;
        case 4:
            putimage(x * BLOCK_SIZE, y * BLOCK_SIZE, &block_4);
            break;
        case 5:
            putimage(x * BLOCK_SIZE, y * BLOCK_SIZE, &block_5);
            break;
        case 6:
            putimage(x * BLOCK_SIZE, y * BLOCK_SIZE, &block_6);
            break;
        case 7:
            putimage(x * BLOCK_SIZE, y * BLOCK_SIZE, &block_7);
            break;
        case 8:
            putimage(x * BLOCK_SIZE, y * BLOCK_SIZE, &block_8);
            break;
        }
    }
    isClicked[y][x] = true;
}

void showBlock(int x, int y)
{
    if (x < 0 || x >= COL || y < 0 || y >= ROW || isClicked[y][x])
        return;

    switch (getMineCount(x, y))
    {
    case 0:
        putimage(x * BLOCK_SIZE, y * BLOCK_SIZE, &block_0);
        break;
    case 1:
        putimage(x * BLOCK_SIZE, y * BLOCK_SIZE, &block_1);
        break;
    case 2:
        putimage(x * BLOCK_SIZE, y * BLOCK_SIZE, &block_2);
        break;
    case 3:
        putimage(x * BLOCK_SIZE, y * BLOCK_SIZE, &block_3);
        break;
    case 4:
        putimage(x * BLOCK_SIZE, y * BLOCK_SIZE, &block_4);
        break;
    case 5:
        putimage(x * BLOCK_SIZE, y * BLOCK_SIZE, &block_5);
        break;
    case 6:
        putimage(x * BLOCK_SIZE, y * BLOCK_SIZE, &block_6);
        break;
    case 7:
        putimage(x * BLOCK_SIZE, y * BLOCK_SIZE, &block_7);
        break;
    case 8:
        putimage(x * BLOCK_SIZE, y * BLOCK_SIZE, &block_8);
        break;
    }
    isClicked[y][x] = true;

    if (getMineCount(x, y) == 0)
    {
        showBlock(x - 1, y - 1);
        showBlock(x - 1, y);
        showBlock(x - 1, y + 1);
        showBlock(x, y - 1);
        showBlock(x, y + 1);
        showBlock(x + 1, y - 1);
        showBlock(x + 1, y);
        showBlock(x + 1, y + 1);
    }
}

void markFlag(int x, int y)
{
    putimage(x * BLOCK_SIZE, y * BLOCK_SIZE, &block_flag);
    isClicked[y][x] = true;
}
