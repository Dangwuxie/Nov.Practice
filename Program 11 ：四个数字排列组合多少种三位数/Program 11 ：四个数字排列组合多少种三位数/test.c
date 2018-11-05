#define _CRT_SECURE_NO_WARNINGS 1
//题目：有1、2、3、4四个数字，能组成多少个互不相同且没有重复数字的三位数？都是多少？
//题目分析：一种四个数字，组成不同的三位数，三位数，百位，十位，个位，
//分别填进去不同的数字，不能重复，所以可以直接用两层嵌套循环实现；
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int g = 0;
	int s = 0;
	int b = 0;
	int count = 0;
	for ( b = 1; b <= 4; b++)
	{
		for ( s = 1; s <= 4; s++)
		{
			for ( g = 1; g <= 4; g++)
			{
				if (b != s && s != g && b!= g)
				{
					printf("%d%d%d\n", b, s, g);
					count++;
				}
			}
		}
	}
	printf("可以组成的三位数一共有%d个",count);
	system("pause");
	return 0;
}