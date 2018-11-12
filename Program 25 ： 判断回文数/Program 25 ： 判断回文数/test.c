#define _CRT_SECURE_NO_WARNINGS 1
//题目：一个5位数，判断它是不是回文数。
//即12321是回文数，个位与万位相同，十位与千位相同。
//英文：回文数：palindromic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int pal = 0;
	int count = 0;
	printf("please input a intger:\n");
	scanf("%d", &pal);
	int i = pal;
	int j = pal;//定义两个临时变量i、j接受pal的值，不能改变pal的值；
	while (j)
	{
		count++;
		j = j / 10;
	}
	printf("位数为%d\n", count);
	int num = 0;
	while (i)
	{
		num += (i % 10) * pow(10,count-1);
		i = i / 10;
		count--;
	}
	if (num == pal)
	{
		printf("是个回文数，是%d\n",num);
	}
	else
	{
		printf("不是个回文数！");
	}
	system("pause");
	return 0;
}