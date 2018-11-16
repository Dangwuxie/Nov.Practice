#define _CRT_SECURE_NO_WARNINGS 1
//题目：对10个数进行排序   
//分析：用户输入十个数，对其排序
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[10] = { 0 };
	int i = 0;
	int j = 0;
	int k = 0;
	printf("Please input ten integer :");
	for ( i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	for ( j = 0; j < 10; j++)
	{
		for ( k = j+1; k < 10; k++)
		{
			int t = 0;
			if (a[j]>a[k])
			{
				t = a[j];
				a[j] = a[k];
				a[k] = t;
			}
		}
	}
	for ( i = 0; i < 10; i++)
	{
		printf(" %d ", a[i]);
	}
	system("pause");
	return 0;
}