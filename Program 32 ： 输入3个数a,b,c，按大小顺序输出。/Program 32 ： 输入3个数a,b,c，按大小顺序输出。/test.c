#define _CRT_SECURE_NO_WARNINGS 1
//题目：输入3个数a, b, c，按大小顺序输出。
//分析：利用指针方法。
//就是写一个函数，实现两个数的交换；通过指针交换主函数里面的数；
#include <stdio.h>
#include <stdlib.h>
void swap(int* x, int* y)
{
	int tmp = 0;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d %d %d", &a, &b, &c);
	if (a<b)
	{
		swap(&a, &b);
	}
	if (a<c)
	{
		swap(&a, &c);
	}
	if (b<c)
	{
		swap(&b, &c);
	}
	printf("%d %d %d", a, b, c);

	system("pause");
	return 0;
}
