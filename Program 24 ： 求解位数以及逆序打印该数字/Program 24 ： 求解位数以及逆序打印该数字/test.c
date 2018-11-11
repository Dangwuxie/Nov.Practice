#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//题目：题目：给一个不多于5位的正整数。
//要求：一、求它是几位数，二、逆序打印出各位数字。 
int main()
{
	int i = 0;
	int j = 0;
	printf("Please input a inter :\n");
	/*for ( i = 0; i < 100; i++)
	{
		scanf("%d", a[i]);
	}*/
	scanf("%d", &i);
	int x = i;
	while (x)
	{
		x = x / 10;
		j++;
	}
	int y = i;//定义一个临时变量接受i的值，不然会改变i的值
	printf("The integer's bit is %d\n", j);
	printf("The reverse is :");
	while (y)
	{
		printf("%d", y % 10);
		y = y / 10;
	}
	printf("\n");
	system("pause");
	return 0;
}