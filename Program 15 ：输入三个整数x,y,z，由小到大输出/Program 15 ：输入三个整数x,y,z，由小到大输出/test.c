#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//��Ŀ��������������x,y,z����С�������
//����������С�����ŵ�x��ȥ��Ȼ��Ƚ�ʣ�µ���������С�ķŵ�y�ϣ���ķŵ�z��
int main()
{
	int x = 0;
	int y = 0;
	int z = 0;
	printf("��ֱ���������������");
	scanf("%d %d %d", &x, &y, &z);
	int t = 0;
	if (x>y)
	{
		t = x;
		x = y;
		y = t;
	}
	else if (x>z)
	{
		t = x;
		x = z;
		z = t;
	}
	if (y>z)
	{
		t = y;
		y = z;
		z = t;
	}
	printf("%d %d %d", x, y, z);
	system("pause");
	return 0;
}