#define _CRT_SECURE_NO_WARNINGS 1
//题目：有一个已经排好序的数组。
//现输入一个数，要求按原来的规律将它插入数组中。   
//分析：首先判断此数是否大于最后一个数，然后再考虑插入中间的数的情况
//插入后此元素之后的数，依次后移一个位置。
#include <stdio.h>
#include <stdlib.h>
int main()
{
	//先初始化一个已经升序排列的数组;初始化的数组中含有10个数；
	int i = 0;
	int arr[20] = { 3, 5, 7, 8, 13, 14, 17, 18, 22, 23 };
	int key = 0;
	printf("Please input a intger :   ");
	scanf("%d", &key);
	for ( i = 0; i < 10; i++)
	{
		if (key <= arr[i])
		{
			int j = 0;
			for ( j = 10; j > i; j--)
			{
				arr[j] = arr[j - 1];
			}
			arr[i] = key;
			break;//
		}
	}
	for ( i = 0; i < 11; i++)
	{
		printf(" %d ", arr[i]);
	}
	system("pause");
	return 0;
}