#define _CRT_SECURE_NO_WARNINGS 1
//��Ŀ�����õݹ鷽����׳ˡ�  
#include <stdio.h>
#include <stdlib.h>
int Mult(int i);
int main()
{
	int i = 0;
	int sum = 0;
	printf("������Ҫ��׳˵����֣�");
	scanf("%d", &i);
	sum += Mult(i - 1)*i;
	printf("%d�Ľ׳���%d\n", i, sum);
	system("pause");
	return 0;
}
int Mult(int i)
{
	if (i == 1)//�����һ��i=1��ʱ�򣬷���1���൱�ڴ�1�˵���ǰ��Ҫ�����
	{
		return 1;
	}
	else
	{
		return i*Mult(i - 1);
	}
}