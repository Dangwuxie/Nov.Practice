#define _CRT_SECURE_NO_WARNINGS 1
//题目：求一个3*3矩阵对角线元素之和   
//程序分析：利用双重for循环控制输入二维数组，再将a[i][i]累加后输出。
//运行之后，输入的时候，可以连续输入九个数，中间以空格隔开；
//或者每输入一个数按一次回车键，直到输入九个数；
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int arr[3][3] = { 0 };
	int i = 0;
	int j = 0;
	printf("Please input 3*3 's intger:\n");
	for ( i = 0; i < 3; i++)
	{
		for ( j = 0; j < 3; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	int tmp = 0;
	tmp = arr[0][0] + arr[1][1] + arr[2][2] + arr[2][0] + arr[1][1] + arr[0][2];
	printf("对角线之和为%d\n", tmp);
	system("pause");
	return 0;
}