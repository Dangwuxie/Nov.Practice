#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//题目：输入三个整数x,y,z，由小到大输出
//分析：把最小的数放到x上去，然后比较剩下的两个数，小的放到y上，大的放到z上
int main()
{
	int x = 0;
	int y = 0;
	int z = 0;
	printf("请分别输入三个整数：");
	scanf("%d %d %d", &x, &y, &z);
	int t = 0;
	if (x>y)
	{
		t = x;
		x = y;
		y = t;
	}
	else if (x>z)
	{
		t = x;
		x = z;
		z = t;
	}
	if (y>z)
	{
		t = y;
		y = z;
		z = t;
	}
	printf("%d %d %d", x, y, z);
	system("pause");
	return 0;
}