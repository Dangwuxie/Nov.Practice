#define _CRT_SECURE_NO_WARNINGS 1
//【程序27】   题目：求100之内的素数
//分析：素数的除数只有1和他本身；而且素数都是奇数；
//11.16号凌晨：没想到这道题还把我难住了，还是查了以前敲过的代码才敲对了......
//还是基础不行啊，继续加油！
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i = 1;
	int j = 0;
	for ( i = 1; i <= 100; i++)
	{
		for ( j = 2; j <= i; j++)
		{
			if (i%j == 0)
			{
				break;
			}		  
		}
		if (j >= i)
		{
			printf("  %d\n", i);
		}
	}
	system("pause");
	return 0;
}