#define _CRT_SECURE_NO_WARNINGS 1
//��Ŀ��һ��5λ�����ж����ǲ��ǻ�������
//��12321�ǻ���������λ����λ��ͬ��ʮλ��ǧλ��ͬ��
//Ӣ�ģ���������palindromic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int pal = 0;
	int count = 0;
	printf("please input a intger:\n");
	scanf("%d", &pal);
	int i = pal;
	int j = pal;//����������ʱ����i��j����pal��ֵ�����ܸı�pal��ֵ��
	while (j)
	{
		count++;
		j = j / 10;
	}
	printf("λ��Ϊ%d\n", count);
	int num = 0;
	while (i)
	{
		num += (i % 10) * pow(10,count-1);
		i = i / 10;
		count--;
	}
	if (num == pal)
	{
		printf("�Ǹ�����������%d\n",num);
	}
	else
	{
		printf("���Ǹ���������");
	}
	system("pause");
	return 0;
}