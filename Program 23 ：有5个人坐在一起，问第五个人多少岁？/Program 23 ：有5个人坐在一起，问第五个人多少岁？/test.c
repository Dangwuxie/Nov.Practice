#define _CRT_SECURE_NO_WARNINGS 1
//��Ŀ����5��������һ��
//�ʵ�����˶����ꣿ��˵�ȵ�4���˴�2�ꡣ
//�ʵ�4������������˵�ȵ�3���˴�2�ꡣ
//�ʵ������ˣ���˵�ȵ�2�˴����ꡣ
//�ʵ�2���ˣ�˵�ȵ�һ���˴����ꡣ
//����ʵ�һ���ˣ���˵��10�ꡣ���ʵ�����˶��   
//���������õݹ�ķ������ݹ��Ϊ���ƺ͵��������׶Ρ�
//Ҫ��֪�����������������֪�������˵��������������ƣ��Ƶ���һ�ˣ�10�꣩���������ơ�
#include <stdio.h>
#include <stdlib.h>
int Recursion(int i);
int main()
{
	int i = 0;
	//int j = 0;
	int age = 0;
	printf("Please input number :");
	scanf("%d", &i);
	age = Recursion(i);
	printf("��%d���˵�������%d\n",i,age);
	system("pause");
	return 0;
}
int Recursion(int i)
{
	if (i == 1)
	{
		return 10;
	}
	else
	{
		return 2 + Recursion(i-1);
	}
}
