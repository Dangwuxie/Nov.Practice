#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void test()
{
	srand((unsigned int)time(NULL));//����rand()����֮ǰ���õģ�srand��һ��������������ӵĺ���
	int input = 0;///////////////////time(NULL)����˼�������ڵ�ϵͳʱ����Ϊ��������������������
	menu();/////////////////////////����NULL���������ֻ�����ó�NULL���ܻ��ϵͳ��ʱ��
	printf("��ѡ��1����0��ʼ���߽�����Ϸ��->  ");
	do
	{
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
			printf("����������������룡 ->");
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
	char mine[ROWS][COLS] = { 0 };//��������׵���Ϣ
	char show[ROWS][COLS] = { 0 };//���������չʾ������
	InitBoard(mine, ROWS, COLS, '0');//mine����81���ַ�ȫ����ʼ��Ϊ�ַ�0��
	InitBoard(show, ROWS, COLS, '*');//show����ȫ����ʼ��Ϊ�ַ���*������ҿ�����ֻ��*��
	SetMine(mine, ROW, COL);//�����׵���Ϣ����ֻ������mine�����У�
	//DisplayBoard(mine, ROW, COL);////��ʽ��Ϸ���ش�ӡ����׵���Ϣ��������䲻�ô�ӡ
	DisplayBoard(show, ROW, COL);
	printf("--------------------------------\n");
	FindMine(mine, show, ROW, COL);//��ʼɨ��
//	printf("--------------------------------\n");
//	DisplayBoard(mine, ROW, COL);
//	DisplayBoard(show, ROW, COL);
//	printf("--------------------------------\n");
}
void InitBoard(char board[ROWS][COLS], int rows, int cols, char ret)//������β�rows\cols,����
//��ʼ���ǳ�ʼ��11*11�����̣�ȫ����ʼ��Ϊ���յ����ַ�
{
	memset(&(board[0][0]),ret, rows*cols*sizeof(board[0][0]));//memset()������Ҫ#include<stdlib.h>���ͷ�ļ�
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)//��ӡ���̣�row��col������ȷ����ӡ���ַ����������м�
//9*9�����̴�ӡ�ַ��������������9��row��col;
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
void SetMine(char board[ROWS][COLS], int row, int col)//����
{
	int x = 0;
	int y = 0;
	int count = COUNT;
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (board[x][y] == '0')//ÿ�ɹ�����һ���ף�count���Լ�һ
		{
			board[x][y] = '1';
			count--;
		}
	}
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//��ʼ����
{
	int x = 0;
	int y = 0;
	int win = 0;
	int input = 0;
	printf("������Ҫ�ߵĵ�һ�����꣺");
	while (win<row*col-COUNT)//ѭ����ֹ������ɨ�����׵��ڲ��µ��ף�
	{
		scanf("%d%d", &x, &y);
		printf("--------------------------------\n");
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1'&& win == 0)//�����ֻ��һ�����ܣ���һ�β���ը����
				//��һ��������ף�����������̱�ĵط���һ���ף��ѵ�ǰ������׸�Ϊ����
				//�����׵�����û�䣬����ֲ�Ҳû�䣬��һ��Ҳû��ը��
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
				//DisplayBoard(mine, ROW, COL);//��ʽ��Ϸ���ش�ӡ����׵���Ϣ��������䲻�ô�ӡ
				printf("--------------------------------\n");
				do
				{
					printf("��ѡ��1����0ѡ�����׵���߽�������һ��->\n");
					scanf("%d", &input);
						switch (input)
					{
						case 1:
							RemarkBoard(show, row, col);
							DisplayBoard(show, ROW, COL);
							break;
						case 0:
							printf("��ѡ������һ�� --> ");
							break;
						default:
							printf("����������������룡 ->");
							break;
					}	
				} while (input);	
				win++;
			}
		    else if (mine[x][y] == '1')
			{
				printf("You was died !!!!\n");
				DisplayBoard(mine, ROW, COL);
				printf("������ѡ��1����0��ʼ���߽�����Ϸ��->  ");
				break;
			}
			else
			{
				//���û�в����ף��Ų��������Χ����
				int count = GetMine(mine, x, y);
				show[x][y] = count + '0';
				SpreadBoard(mine, show,row,col,x,y);
				DisplayBoard(show, ROW, COL);
				//DisplayBoard(mine, ROW, COL); ��ʽ��Ϸ���ش�ӡ����׵���Ϣ��������䲻�ô�ӡ
				printf("--------------------------------\n");
				//printf("��ѡ������һ�� --> ");
				do
				{
					printf("��ѡ��1����0ѡ�����׵���߽�������һ��->\n");
					scanf("%d", &input);
					switch (input)
					{
					case 1:
						RemarkBoard(show, row, col);
						DisplayBoard(show, ROW, COL);
						break;
					case 0:
						printf("��ѡ������һ�� --> ");
						break;
					default:
						printf("����������������룡 ->");
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
		printf("������ѡ��1����0��ʼ���߽�����Ϸ��->  ");
	}
}
int GetMine(char a[ROWS][COLS], int x, int y)//����GetMine()ͳ�Ƹ�������Χ���׵ĸ���
{
	return
		a[x - 1][y - 1] + a[x - 1][y] + a[x - 1][y + 1]
		+ a[x][y - 1] + a[x][y + 1]
		+ a[x + 1][y - 1] + a[x + 1][y] + a[x + 1][y + 1] - 8*'0';//�����ַ���ȥ�����ַ���0���͵��ڶ�Ӧ������
}
//չ������SpreadBoard(),���ĳ��������Χû���ף���չ���������������ڵľŸ�����
//Ȼ�󣬼����Ը�������Χ�İ˸�û���׵�����Ϊ�������Ų飬�����Χ�˸������У�
//���״��ڣ���ô��չ����ֱ������׵ĸ������������ƣ�
//����˼��Ϊ�ݹ��˼�룬һ��һ���չ����
//�ݹ����ֹ��������count!=0����׵ĸ������Ͳ�������ˣ�
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
//��Ǻ���RamarkBoard()�������������ֻ��Ҫ��ӡ����ҵ��Ǹ����̾���
//Ҳ���ǳ�ʼ��ȫ���ַ�'*'���Ǹ����̣�����Լ�����˺�������ɸ�̾��
void RemarkBoard(char show[ROWS][COLS], int row, int col)//��Ǻ�����
{
	int x = 0;
	int y = 0;
	int flag = 1;
	printf("��������Ҫ��ǵ����꣺-> ");
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
			printf("��������������룡");
		}
	}
}
//���������и�bug��������ҿ��Լ������Ѿ���ǵ���һ���壬��Ϸ���ɻ��ж��Ƿ����
//��Ϸ���ɰ���mine���̣�Ҳ���Ǵ洢�׵���Ϣ���Ǹ����̣�
//���bug......��Ϸδ�����......