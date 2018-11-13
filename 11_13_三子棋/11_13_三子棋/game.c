#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void test()
{
	srand((unsigned)time(NULL));//���������
	int input = 0;
	menu();
	do
	{
		printf("ѡ��1��0��ʼ�������Ϸ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("����������������룡\n");
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
	InitBoard(board, ROW, COL);//��ʼ��һ��ROW*COL������
	DisplayBoard(board, ROW, COL);//��ӡ����
	while (1)
	{
		PlayerMove(board, ROW, COL);//�����һ��
		DisplayBoard(board, ROW, COL);//��ӡ����

		ret = IsWin(board, ROW, COL);//IsWin�����ж��Ƿ���Ӯ��
		if (ret == 'X')
		{
			printf("���Ӯ��\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("ƽ�֣�\n");
			break;
		}
	/*	else if (ret == ' ')
		{
			printf("����->\n");
		}*/
		ComputerMove(board, ROW, COL);//�����û��Ӯ�����Խ�����һ��
		DisplayBoard(board, ROW, COL);//��ӡ������һ���������
		ret = IsWin(board, ROW, COL);//�жϵ����Ƿ�Ӯ��
		if (ret == '*')
		{
			printf("����Ӯ�ˣ�\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("ƽ�֣�\n");
			break;
		}
	/*	else if (ret == ' ')
		{
			printf("����->\n");//���ؿո�ò��û�ã�ʡ�ԣ�
		}*/
	}

}
void InitBoard(char board[ROW][COL], int row, int col)
{
	memset(&board[0][0], ' ', row*col*sizeof(board[0][0]));//����ROW*COL���ַ��ĳ�ʼ��
}
void DisplayBoard(char board[ROW][COL], int row, int col)//��ӡ����
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < row; i++)
	{
		for ( j = 0; j < col; j++)//iÿѭ��һ�Σ���ӡ���У���һ���ǡ� %c | %c | %c ��
		{
			printf(" %c ", board[i][j]);
			if (j<col-1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i<row-1)//��ӡ�ڶ��У���---|---|---��
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
	printf("�����:(һ���������������м��Կո����)->");
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
				printf("�ø����Ѿ���ռ�ã���������������->");
			}
		}
		else
		{
			printf("��������������룡");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row,int col)
{
	int x = 0;
	int y = 0;
	printf("������->\n");
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
	if (IsFull(board,ROW,COL)==1)//IsFull�����ж������Ƿ��Ѿ�����
	{
		return 'Q';//ƽ�ֵĻ������ַ���Q��
	}
	else
	{
		return ' ';//���򷵻ؿո�' '�� 
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