#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//��Ŀ����Ŀ����1+2!+3!+...+20!�ĺ�   
int main()
{
	int i = 0;
	int x = 0;
	printf("������Ҫ�������");
	scanf("%d", &x);
	int sum = 1;
	int num = 0;
	for ( i = 1; i <= x; i++)
	{
		sum *= i;//ֱ�Ӵ�1��ʼ�ˣ�ÿһ��ѭ�����ǵ�ǰ��sum����i������ֱ�ӳ˾���
		num += sum;
	}
	printf("ǰ%d��ĺ�Ϊ%d\n", x, num);
	system("pause");
	return 0;
}