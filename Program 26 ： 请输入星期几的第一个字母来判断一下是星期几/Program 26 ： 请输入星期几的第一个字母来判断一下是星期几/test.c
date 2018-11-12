#define _CRT_SECURE_NO_WARNINGS 1
//题目：请输入星期几的第一个字母来判断一下是星期几，
//如果第一个字母一样，则继续判断第二个字母。   
//分析：用情况语句比较好，如果第一个字母一样，则判断用情况语句或if语句判断第二个字母。
//1.Monday 2.Tuesday 3.Wednesday 4.Thursday 5.Friday 6.Saturday 7.Sunday
#include <stdio.h>
#include <stdlib.h>
//注意：有个问题：getchar()函数不能嵌套使用？？？？？
int main()
{
	char week;
	printf("Please input the first character :");
	week = getchar();
	if (week=='M' || week=='m')
	{
		printf("The day is Monday!\n");
	}
	else if (week == 'T' || week== 't')
	{
		printf("Please input no.2 character:");
		char weeks;
		scanf("%s", &weeks);
		if (weeks=='U' || weeks=='u' )
		{
			printf("The day is Tuesday!\n");
		}
		else if (weeks=='H' || weeks=='h')
		{
			printf("The day is Thursday!\n");
		}
		else
		{
			printf("error!\n");
		}
	}
	else if (week=='W' || week == 'w')
	{
		printf("The day is Wenesday !\n");
	}
	else if (week=='F' || week=='f')
	{
		printf("The day is Friday !\n");
	}
	else if (week=='S' || week=='s')
	{
		printf("Please input no.2 character:");
		char weeks = getchar();
		if (weeks == 'A' || weeks == 'a')
		{
			printf("The day is Saturday!\n");
		}
		else if (weeks == 'U' || weeks == 'u')
		{
			printf("The day is Sunday!\n");
		}
		else
		{
			printf("error!\n");
		}
	}
	system("pause");
	return 0;
}