#define _CRT_SECURE_NO_WARNINGS 1
//������27��   ��Ŀ����100֮�ڵ�����
//�����������ĳ���ֻ��1��������������������������
//11.16���賿��û�뵽����⻹������ס�ˣ����ǲ�����ǰ�ù��Ĵ�����ö���......
//���ǻ������а����������ͣ�
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i = 1;
	int j = 0;
	for ( i = 1; i <= 100; i++)
	{
		for ( j = 2; j <= i; j++)
		{
			if (i%j == 0)
			{
				break;
			}		  
		}
		if (j >= i)
		{
			printf("  %d\n", i);
		}
	}
	system("pause");
	return 0;
}