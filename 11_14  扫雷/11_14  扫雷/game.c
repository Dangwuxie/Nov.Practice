#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void test()
{
	srand((unsigned int)time(NULL));//调用rand()函数之前调用的，srand是一个产生随机数种子的函数
	int input = 0;///////////////////time(NULL)的意思是以现在的系统时间作为随机的种子来产生随机数
	menu();/////////////////////////至于NULL这个参数，只有设置成NULL才能获得系统的时间
	printf("请选择1或者0开始或者结束游戏：->  ");
	do
	{
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("输入错误，请重新输入！ ->");
			break;
		}
	} while (input);
}
void menu()
{
	printf("*****************************************\n");
	printf("***************    1.play   *************\n");
	printf("***************    0.exit   *************\n");
	printf("*****************************************\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };//用来存放雷的信息
	char show[ROWS][COLS] = { 0 };//用来向玩家展示的棋盘
	InitBoard(mine, ROWS, COLS, '0');//mine棋盘81个字符全部初始化为字符0；
	InitBoard(show, ROWS, COLS, '*');//show棋盘全部初始化为字符‘*’（玩家看到的只有*）
	SetMine(mine, ROW, COL);//放入雷的信息，雷只保存在mine棋盘中；
	//DisplayBoard(mine, ROW, COL);////正式游戏不必打印存放雷的信息；此条语句不用打印
	DisplayBoard(show, ROW, COL);
	printf("--------------------------------\n");
	FindMine(mine, show, ROW, COL);//开始扫雷
//	printf("--------------------------------\n");
//	DisplayBoard(mine, ROW, COL);
//	DisplayBoard(show, ROW, COL);
//	printf("--------------------------------\n");
}
void InitBoard(char board[ROWS][COLS], int rows, int cols, char ret)//这里的形参rows\cols,区别：
//初始化是初始化11*11的棋盘，全部初始化为接收到的字符
{
	memset(&(board[0][0]),ret, rows*cols*sizeof(board[0][0]));//memset()函数需要#include<stdlib.h>这个头文件
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)//打印棋盘，row和col，用来确定打印的字符，仅仅在中间
//9*9的棋盘打印字符，所以这里接受9用row和col;
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for ( i = 1; i <= row; i++)
	{
		printf("%d", i);
		for ( j = 1; j <= col; j++)
		{
			printf(" %c", board[i][j]);
		}
		printf("\n");
	}	
}
void SetMine(char board[ROWS][COLS], int row, int col)//布雷
{
	int x = 0;
	int y = 0;
	int count = COUNT;
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (board[x][y] == '0')//每成功布下一个雷，count就自减一
		{
			board[x][y] = '1';
			count--;
		}
	}
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//开始排雷
{
	int x = 0;
	int y = 0;
	int win = 0;
	int input = 0;
	printf("请输入要走的第一个坐标：");
	while (win<row*col-COUNT)//循环终止条件：扫出的雷等于布下的雷；
	{
		scanf("%d%d", &x, &y);
		printf("--------------------------------\n");
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1'&& win == 0)//此入口只有一个功能：第一次不被炸死；
				//第一次如果是雷，就随机在棋盘别的地方加一个雷，把当前坐标的雷改为无雷
				//这样雷的总数没变，随机分布也没变，第一次也没有炸死
			{
				int num = 1;
				while (num)
				{
					int i = rand() % row + 1;
					int j = rand() % col + 1;
					if (mine[i][j] == '0')
					{
						mine[i][j] = '1';
						num--;
					}
				}
				mine[x][y] = '0';
				SpreadBoard(mine, show,row,col,x,y);
				int count = GetMine(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, ROW, COL);
				//DisplayBoard(mine, ROW, COL);//正式游戏不必打印存放雷的信息；此条语句不用打印
				printf("--------------------------------\n");
				do
				{
					printf("请选择1或者0选择标记雷点或者接着走下一步->\n");
					scanf("%d", &input);
						switch (input)
					{
						case 1:
							RemarkBoard(show, row, col);
							DisplayBoard(show, ROW, COL);
							break;
						case 0:
							printf("请选择走下一步 --> ");
							break;
						default:
							printf("输入错误，请重新输入！ ->");
							break;
					}	
				} while (input);	
				win++;
			}
		    else if (mine[x][y] == '1')
			{
				printf("You was died !!!!\n");
				DisplayBoard(mine, ROW, COL);
				printf("请重新选择1或者0开始或者结束游戏：->  ");
				break;
			}
			else
			{
				//如果没有踩中雷，排查该坐标周围的雷
				int count = GetMine(mine, x, y);
				show[x][y] = count + '0';
				SpreadBoard(mine, show,row,col,x,y);
				DisplayBoard(show, ROW, COL);
				//DisplayBoard(mine, ROW, COL); 正式游戏不必打印存放雷的信息；此条语句不用打印
				printf("--------------------------------\n");
				//printf("请选择走下一步 --> ");
				do
				{
					printf("请选择1或者0选择标记雷点或者接着走下一步->\n");
					scanf("%d", &input);
					switch (input)
					{
					case 1:
						RemarkBoard(show, row, col);
						DisplayBoard(show, ROW, COL);
						break;
					case 0:
						printf("请选择走下一步 --> ");
						break;
					default:
						printf("输入错误，请重新输入！ ->");
						break;
					}
				} while (input);
				win++;
			}
		}
	}
	if (win == row*col - COUNT)
	{
		printf("You are Winner!!!!!\n");
		DisplayBoard(show, ROW, COL);
		DisplayBoard(mine, ROW, COL);
		printf("--------------------------------\n");
		printf("请重新选择1或者0开始或者结束游戏：->  ");
	}
}
int GetMine(char a[ROWS][COLS], int x, int y)//函数GetMine()统计改坐标周围的雷的个数
{
	return
		a[x - 1][y - 1] + a[x - 1][y] + a[x - 1][y + 1]
		+ a[x][y - 1] + a[x][y + 1]
		+ a[x + 1][y - 1] + a[x + 1][y] + a[x + 1][y + 1] - 8*'0';//数字字符减去数字字符‘0’就等于对应的数字
}
//展开函数SpreadBoard(),如果某个坐标周围没有雷，则展开包括改坐标在内的九个坐标
//然后，继续以该座标周围的八个没有雷的坐标为起点继续排查，如果周围八个坐标中，
//有雷存在，那么不展开，直接输出雷的个数；依次类推；
//这种思想为递归的思想，一层一层的展开；
//递归的终止条件就是count!=0输出雷的个数，就不会调用了；
void SpreadBoard(char mine[ROWS][COLS], char show[ROWS][COLS],int row,int col, int x, int y)
{
	int count = 0;
	count = GetMine(mine, x, y);
	int i = 0;
	int j = 0;
	if (count == 0)
	{
		show[x][y] = ' ';
		if (x + 1 <= row && y - 1 > 0 && show[x + 1][y - 1] == '*')
		{
			SpreadBoard(mine, show, row, col, x + 1, y - 1);
		}
		if (x + 1 <= row && show[x + 1][y] == '*')
		{
			SpreadBoard(mine, show, row, col, x + 1, y);
		}
		if (x + 1 <= row && y + 1 <= col && show[x + 1][y + 1] == '*')
		{
			SpreadBoard(mine, show, row, col, x + 1, y + 1);
		}
		if (y - 1 > 0 && show[x][y - 1] == '*')
		{
			SpreadBoard(mine, show, row, col, x, y - 1);
		}
		if (y + 1 <= col &&show[x][y + 1] == '*')
		{
			SpreadBoard(mine, show, row, col, x, y + 1);
		}
		if (x - 1 > 0 && y - 1 > 0 && show[x - 1][y - 1] == '*')
		{
			SpreadBoard(mine, show, row, col, x - 1, y - 1);
		}
		if (x - 1 > 0 && show[x - 1][y] == '*')
		{
			SpreadBoard(mine, show, row, col, x - 1, y);
		}
		if (x - 1 > 0 && y + 1 <= col && show[x - 1][y + 1] == '*')
		{
			SpreadBoard(mine, show, row, col, x - 1, y + 1);
		}
	}
	else
	{
		show[x][y] = count + '0';
	}
}
//标记函数RamarkBoard()，这个函数传参只传要打印给玩家的那个棋盘就行
//也就是初始化全是字符'*'的那个棋盘，玩家自己标记了后该坐标变成感叹号
void RemarkBoard(char show[ROWS][COLS], int row, int col)//标记函数；
{
	int x = 0;
	int y = 0;
	int flag = 1;
	printf("请输入您要标记的坐标：-> ");
	scanf("%d %d", &x, &y);
	while (flag)
	{
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if (show[x][y] == '*')
			{
				show[x][y] = '!';
				flag = 0;
			}
		}
		else
		{
			printf("输入错误，重新输入！");
		}
	}
}
//本程序还是有个bug：就是玩家可以继续走已经标记的那一步棋，游戏依旧会判断是否踩雷
//游戏依旧按照mine棋盘，也就是存储雷的信息的那个棋盘；
//这个bug......游戏未完待续......