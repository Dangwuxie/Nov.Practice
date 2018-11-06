#define _CRT_SECURE_NO_WARNINGS 1
//题目：输入某年某月某日，判断这一天是这一年的第几天？
//程序分析：以3月5日为例，应该先把前两个月的加起来，
//然后再加上5天即本年的第几天，
//特殊情况，闰年并且输入月份大于3时需要考虑多加一天。
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//定义一个数组用来存储每个月的天数
	int year = 0;//定义变量存取年份
	int month = 0;//存取月份
	int day = 0;//存取某日
	int num = 0;//所要求的日子在这一年的天数
	int i = 0;
	printf("请输入要求的某年某月某日：\n");
	scanf("%d  %d  %d", &year, &month, &day);//输入年份
	//printf("%d  %d  %d", year, a[month - 1], day);
	for ( i = 0; i < month-1; i++)//用循环来求前面的月份总和
	{
		num += a[i];
	}
	num += day;//然后加上当月的天数
	if ((year%4==0 && year%100!=0 || year%400==0) && (month>=3))
	{
		num += 1;//如果是闰年，而且月份大于3时应该多加一天，二月为29天
	}
	printf("这一天是这一年的第%d天\n",num);
	system("pause");
	return 0;
}