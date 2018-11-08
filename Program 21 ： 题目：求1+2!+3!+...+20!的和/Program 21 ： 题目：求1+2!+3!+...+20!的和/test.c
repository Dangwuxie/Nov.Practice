#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//题目：题目：求1+2!+3!+...+20!的和   
int main()
{
	int i = 0;
	int x = 0;
	printf("请输入要求的项数");
	scanf("%d", &x);
	int sum = 1;
	int num = 0;
	for ( i = 1; i <= x; i++)
	{
		sum *= i;//直接从1开始乘，每一次循环都是当前的sum乘以i，所以直接乘就行
		num += sum;
	}
	printf("前%d项的和为%d\n", x, num);
	system("pause");
	return 0;
}