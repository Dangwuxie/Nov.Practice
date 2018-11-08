#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//19、题目：打印一个可以随意控制大小的菱形。
//  *
// ***
//*****
// ***
//  *
//分析：先把图形分成两部分来看待，前四行一个规律，后三行一个规律，
//利用双重for循环，第一层控制行，第二层控制列。 
int main()
{
	int i = 0;//临时循环变量
	int n = 0;//获取要打印的菱形的行数
	printf("请输入要打印的菱形的上半部分行数：");
	scanf("%d", &n);
//先打印上半部分，
	for ( i = 1; i <= n; i++)
	{
		int j = 0;//打印空格
		int k = 0;//打印图案
		for ( j = 1; j <= (n-i) ; j++)
		{
			printf(" ");
		}
		for ( k = 1; k <= (2*i-1); k++)
		{
			printf("*");
		}
		printf("\n");
	}
//然后打印下半部分的，下半部分比上半部分少了一行，打印的话跟上部分差不多一样；
	for ( i = 1; i <= n-1; i++)
	{
		int j = 0;
		int k = 0;
		for ( j = 1; j <= i; j++)
		{
			printf(" ");
		}
		for ( k = 1; k <= 2*(n-i)-1 ; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}