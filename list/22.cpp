#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

//#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

const int W = 4;
const int H = 4;
int board[H][W];  //H:高  W：宽   board[2][1] 表示第二行第二个
int score;
const int keymap[4] = {72,80,75,77}; //依次为上下左右
const int dx[4] = { -1,1,0,0 };  //依次对应上下左右
const int dy[4] = {  0,0,-1,1 };
                                        
                    //2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384  (超过这个数字的从头开始)
const int color[] = {15,8,6,14, 4, 2,12 ,5,  13, 3,   10,  11,  1,   9, };

/*  颜色说明：
 * 0 = 黑色       8 = 灰色
 * 1 = 蓝色       9 = 淡蓝色
 * 2 = 绿色       10 = 淡绿色
 * 3 = 浅绿色     11 = 淡浅绿色
 * 4 = 红色       12 = 淡红色
 * 5 = 紫色       13 = 淡紫色
 * 6 = 黄色       14 = 淡黄色
 * 7 = 白色       15 = 亮白色
 */
bool judge()   //0:ok  1:gameover
{
   
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
        {
            if (board[i][j] == 0)
                return false;
            
            else if(i<3 && j<3)
                if (board[i][j] == board[i + 1][j] || board[i][j]==board[i][j+1])
                    return false;
               
        }
    return true;
}

void Set_Color(int color)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
}

void display()
{
    system("cls");
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (board[i][j] == 0) printf("     ");
            else {
                Set_Color(color[ (int)log2(board[i][j])-1 ]); //根据数字设置颜色
                printf("%-5d", board[i][j]);
                Set_Color(7);
            }if (j < 3) putchar('|');
        }
        putchar('\n');
        for (int r = 0; r < 23; r++) putchar('-');
        putchar('\n');
    }
    printf("score: %d",score);
}


void move(int dir)
{
    int x=0,y=0;
    if (dy[dir]) //水平移动
    {
        for (int i = 0; i < H; i++) //遍历每一行
        {
            y = (dy[dir] == 1) ? 3 : 0;
            int j = y;
            int top = y;
            while (abs(j - y) < 3) {
                j -= dy[dir];
                if (board[i][top] == 0 &&board[i][j]!=0)
                {
                    board[i][top] = board[i][j];
                    board[i][j] = 0;
                }
                else if (board[i][top]!=0 && board[i][j]==board[i][top])
                {
                    board[i][top] *= 2;
                    score += board[i][top];
                    board[i][j] = 0;
                }
                else if (board[i][top] * board[i][j] != 0 && board[i][top] != board[i][j])
                {
                    top -= dy[dir];
                    if (j != top)
                    {
                        board[i][top] = board[i][j];
                        board[i][j] = 0;
                    }
                }
            }

        }
    
    }
    else if (dx[dir]) //垂直移动
    {
        for (int j = 0; j < W; j++) //遍历每一列
        {
            x = (dx[dir] == 1) ? 3 : 0;
            int i = x;
            int top = x;
            while (abs(i - x) < 3) {
                i -= dx[dir];
                if (board[top][j] == 0 && board[i][j] != 0)
                {
                    board[top][j] = board[i][j];
                    board[i][j] = 0;
                }
                else if (board[top][j] != 0 && board[i][j] == board[top][j])
                {
                    board[top][j] *= 2;
                    score += board[top][j];
                    board[i][j] = 0;
                }
                else if (board[top][j] * board[i][j] != 0 && board[top][j] != board[i][j])
                {
                    top -= dx[dir];
                    if (i != top)
                    {
                        board[top][j] = board[i][j];
                        board[i][j] = 0;
                    }
                }
            }

        }

    }
        
}

void newNum()
{
    int flag = 0;
    int n = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j] == 0)
                n++;

    srand((unsigned)time(NULL));
    if (n == 0) return;
    int end = rand() % n;
    int t = 0;
    for (int i = 0; i < 4 && !flag; i++)
        for (int j = 0; j < 4 && !flag; j++)
        {
            if (board[i][j] == 0)
            {
                if (t == end) {
                    board[i][j] += 2;
                    flag = 1;
                }
                else t++;
                
            }
        }
}

void play()
{
    newNum();
    display();
    while (true)
    {
        
        int ch = _getch();
        for (int i = 0; i < 4; i++)
            if (ch == keymap[i]) {
            move(i);
            if (judge())
                return;
            newNum();
            display();
        }
        Sleep(10);     //防止连按
    }

}

void init()
{
    system("mode con:cols=24 lines=10");
    memset(board, 0, sizeof(board));
    score = 0;
}

int main()
{
    init();
    play();
    system("cls");
    printf("\n\n\tGAME OVER!");
    printf("\n\n\tSCORE:%d", score);
    getchar();
}

