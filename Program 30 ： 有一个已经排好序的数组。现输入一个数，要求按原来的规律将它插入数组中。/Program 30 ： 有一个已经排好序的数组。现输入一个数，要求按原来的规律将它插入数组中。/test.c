#define _CRT_SECURE_NO_WARNINGS 1
//��Ŀ����һ���Ѿ��ź�������顣
//������һ������Ҫ��ԭ���Ĺ��ɽ������������С�   
//�����������жϴ����Ƿ�������һ������Ȼ���ٿ��ǲ����м���������
//������Ԫ��֮����������κ���һ��λ�á�
#include <stdio.h>
#include <stdlib.h>
int main()
{
	//�ȳ�ʼ��һ���Ѿ��������е�����;��ʼ���������к���10������
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