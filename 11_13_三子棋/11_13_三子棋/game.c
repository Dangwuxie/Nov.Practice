#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void test()
{
	srand((unsigned)time(NULL));//随机生成数
	int input = 0;
	menu();
	do
	{
		printf("选择1或0开始或结束游戏！\n");
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
			printf("输入错误！请重新输入！\n");
			break;
		}
	} while (input);
}
void menu()
{
	printf("*****************************\n");
	printf("*********  1.play  **********\n");
	printf("*********  0.exit  **********\n");
	printf("*****************************\n");
}
void game()
{
	char ret;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);//初始化一个ROW*COL的棋盘
	DisplayBoard(board, ROW, COL);//打印棋盘
	while (1)
	{
		PlayerMove(board, ROW, COL);//玩家走一步
		DisplayBoard(board, ROW, COL);//打印棋盘

		ret = IsWin(board, ROW, COL);//IsWin函数判断是否人赢了
		if (ret == 'X')
		{
			printf("玩家赢！\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("平局！\n");
			break;
		}
	/*	else if (ret == ' ')
		{
			printf("继续->\n");
		}*/
		ComputerMove(board, ROW, COL);//人如果没有赢，电脑接着走一步
		DisplayBoard(board, ROW, COL);//打印电脑走一步后的棋盘
		ret = IsWin(board, ROW, COL);//判断电脑是否赢了
		if (ret == '*')
		{
			printf("电脑赢了！\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("平局！\n");
			break;
		}
	/*	else if (ret == ' ')
		{
			printf("继续->\n");//返回空格貌似没用，省略；
		}*/
	}

}
void InitBoard(char board[ROW][COL], int row, int col)
{
	memset(&board[0][0], ' ', row*col*sizeof(board[0][0]));//数组ROW*COL个字符的初始化
}
void DisplayBoard(char board[ROW][COL], int row, int col)//打印棋盘
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < row; i++)
	{
		for ( j = 0; j < col; j++)//i每循环一次，打印两行；第一行是“ %c | %c | %c ”
		{
			printf(" %c ", board[i][j]);
			if (j<col-1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i<row-1)//打印第二行：“---|---|---”
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j<col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走:(一次输入两个数，中间以空格隔开)->");
	while (1)
	{
		scanf("%d%d",&x,&y);
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'X';
				break;
			}
			else
			{
				printf("该格子已经被占用，请重新输入坐标->");
			}
		}
		else
		{
			printf("输入错误！重新输入！");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row,int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走->\n");
	while (1)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = '*';
			break;
		}
	}
}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for ( i = 0; i < row; i++)
	{
		if (board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][0]!=' ')
		{
			return board[i][0];
		}
		else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	if (board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[2][2]!=' ')
	{
		return board[2][2];
	}
	else if (board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[2][0]!=' ')
	{
		return board[2][0];
	}
	if (IsFull(board,ROW,COL)==1)//IsFull函数判断棋盘是否已经满了
	{
		return 'Q';//平局的话返回字符‘Q’
	}
	else
	{
		return ' ';//否则返回空格' '； 
	}
}
int IsFull(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	for ( x = 0; x < row; x++)
	{
		for ( y = 0; y < col; y++)
		{
			if (board[x][y]==' ')
			{
				return 0;
			}
		}
	}
	return 1;
}