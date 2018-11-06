#define _CRT_SECURE_NO_WARNINGS 1
//题目：一个整数，它加上100后是一个完全平方数，再加上168后还是一个完全平方数
//请问该数是多少？
//分析：在10万以内判断，先将该数加上100后再平方，再将该数加上268开方，
//如果开方后的的结果依旧满足如下条件，即是结果。
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int i = 0;
	for ( i = 1; i < 100000; i++)
	{
		if (sqrt(i+100) == (int)(sqrt(i+100)))
		{
			if (sqrt(i + 268) == (int)(sqrt(i + 268)))
			{
				printf("这个整数是%d\n", i);
			}
		}
	}
	system("pause");
	return 0;
}
//运行结果
//--------------------------------------------------------
//这个整数是21
//这个整数是261
//这个整数是1581