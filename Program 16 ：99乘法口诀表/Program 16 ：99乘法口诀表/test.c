#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//��Ŀ�����9*9�˷��ھ���
int main()
{
	int i = 1;
	int j = 1;
	for ( i = 1; i <= 9; i++)//��һ��ѭ������������
	{
		for ( j = 1; j <= i; j++)//�ڶ���ѭ������������
		{
			printf("%d*%d=%-3d", j, i, i*j);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}