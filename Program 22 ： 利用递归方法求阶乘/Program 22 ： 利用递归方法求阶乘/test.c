#define _CRT_SECURE_NO_WARNINGS 1
//题目：利用递归方法求阶乘。  
#include <stdio.h>
#include <stdlib.h>
int Mult(int i);
int main()
{
	int i = 0;
	int sum = 0;
	printf("请输入要求阶乘的数字：");
	scanf("%d", &i);
	sum += Mult(i - 1)*i;
	printf("%d的阶乘是%d\n", i, sum);
	system("pause");
	return 0;
}
int Mult(int i)
{
	if (i == 1)//当最后一次i=1的时候，返回1；相当于从1乘到当前所要求的数
	{
		return 1;
	}
	else
	{
		return i*Mult(i - 1);
	}
}