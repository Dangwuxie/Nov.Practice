#define _CRT_SECURE_NO_WARNINGS 1
//题目：将一个数组逆序输出。   
//分析：用第一个与最后一个交换。
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int left = 0;//定义左下标
	int right = sizeof(arr)/sizeof(arr[0])-1;//定义一个右下标
	while (left<right)
	{
		int tmp = 0;
		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;//左下标右移
		right--;//右下标左移；直到两个坐标相同，就不用发生交换了
	}
	int i = 0;
	for ( i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
	{
		printf("  %d  ", arr[i]);
	}
	system("pause");
	return 0;

}