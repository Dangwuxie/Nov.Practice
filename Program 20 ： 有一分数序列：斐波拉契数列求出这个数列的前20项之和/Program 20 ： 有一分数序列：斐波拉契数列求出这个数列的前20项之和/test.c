#define _CRT_SECURE_NO_WARNINGS 1
//有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...求出这个数列的前20项之和
//分析：分子跟分母都是斐波拉契数列，分子从2开始，分母从1开始；
#include <stdio.h>
#include <stdlib.h>
int main()
{
	double sum = 0;
	int i = 0;
	double a[30] = {1,2};//创建一个数组，先定义这个数列的前两个数字，后面的数字在循环内计算
	for ( i = 0; i < 20; i++)
	{
		double num = 0;
		num = a[i + 1] / a[i];//double型，注意！，第一次计算2/1，第二次3/2，下来5/3
		sum += num;
		a[i + 2] = a[i + 1] + a[i];//计算出2/1后，计算第三个数字3，第四个5，以此类推
	}
	printf("这个数列的前20项和为%f\n", sum);
	system("pause");
	return 0;
}