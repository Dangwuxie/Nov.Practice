#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//��Ŀ����Ŀ����һ��������5λ����������
//Ҫ��һ�������Ǽ�λ�������������ӡ����λ���֡� 
int main()
{
	int i = 0;
	int j = 0;
	printf("Please input a inter :\n");
	/*for ( i = 0; i < 100; i++)
	{
		scanf("%d", a[i]);
	}*/
	scanf("%d", &i);
	int x = i;
	while (x)
	{
		x = x / 10;
		j++;
	}
	int y = i;//����һ����ʱ��������i��ֵ����Ȼ��ı�i��ֵ
	printf("The integer's bit is %d\n", j);
	printf("The reverse is :");
	while (y)
	{
		printf("%d", y % 10);
		y = y / 10;
	}
	printf("\n");
	system("pause");
	return 0;
}