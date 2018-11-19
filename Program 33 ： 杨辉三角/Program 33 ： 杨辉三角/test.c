#define _CRT_SECURE_NO_WARNINGS 1
//题目：打印出杨辉三角形（要求打印出10行如下图）   
//分析：
//          1
//        1   1
//      1   2   1
//    1   3   3   1
//  1   4   6   4   1
//1   5   10   10   5   1
#include <stdio.h>
#include <stdlib.h>
#define LEN 10
int main()
{
	int i = 0;
	int j = 0;
	int a[LEN][LEN] = { 0 };
	for ( i = 0; i < LEN; i++)
	{
		a[i][0] = 1;
		a[i][i - 1] = 1;
		if (i>1)
		{
			for (j = 1; j < i - 1; j++)
			{
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			}
		}
	}
	for (i = 0; i < LEN; i++)
	{
		///*int k = 0;
		//for ( k = 0; k < LEN-i; k++)
		//{
		//	printf("  ");
		//}*/
		for ( j = 0; j < i; j++)
		{
			if (a[i][j] != 0)
			{
				printf("  %d", a[i][j]);
			}
		}		
		printf("\n");
	}
	system("pause");
	return 0;
}