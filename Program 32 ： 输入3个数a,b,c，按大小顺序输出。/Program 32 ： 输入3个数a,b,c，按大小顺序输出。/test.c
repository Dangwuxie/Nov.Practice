#define _CRT_SECURE_NO_WARNINGS 1
//��Ŀ������3����a, b, c������С˳�������
//����������ָ�뷽����
//����дһ��������ʵ���������Ľ�����ͨ��ָ�뽻�����������������
#include <stdio.h>
#include <stdlib.h>
void swap(int* x, int* y)
{
	int tmp = 0;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d %d %d", &a, &b, &c);
	if (a<b)
	{
		swap(&a, &b);
	}
	if (a<c)
	{
		swap(&a, &c);
	}
	if (b<c)
	{
		swap(&b, &c);
	}
	printf("%d %d %d", a, b, c);

	system("pause");
	return 0;
}
