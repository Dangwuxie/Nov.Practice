#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//题目，输出9*9乘法口诀表
int main()
{
	int i = 1;
	int j = 1;
	for ( i = 1; i <= 9; i++)//第一层循环，控制行数
	{
		for ( j = 1; j <= i; j++)//第二层循环，控制列数
		{
			printf("%d*%d=%-3d", j, i, i*j);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}