#define _CRT_SECURE_NO_WARNINGS 1
//��Ŀ����һ���������������   
//�������õ�һ�������һ��������
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int left = 0;//�������±�
	int right = sizeof(arr)/sizeof(arr[0])-1;//����һ�����±�
	while (left<right)
	{
		int tmp = 0;
		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;//���±�����
		right--;//���±����ƣ�ֱ������������ͬ���Ͳ��÷���������
	}
	int i = 0;
	for ( i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
	{
		printf("  %d  ", arr[i]);
	}
	system("pause");
	return 0;

}