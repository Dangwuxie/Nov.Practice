#define _CRT_SECURE_NO_WARNINGS 1
//��Ŀ����1��2��3��4�ĸ����֣�����ɶ��ٸ�������ͬ��û���ظ����ֵ���λ�������Ƕ��٣�
//��Ŀ������һ���ĸ����֣���ɲ�ͬ����λ������λ������λ��ʮλ����λ��
//�ֱ����ȥ��ͬ�����֣������ظ������Կ���ֱ��������Ƕ��ѭ��ʵ�֣�
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int g = 0;
	int s = 0;
	int b = 0;
	int count = 0;
	for ( b = 1; b <= 4; b++)
	{
		for ( s = 1; s <= 4; s++)
		{
			for ( g = 1; g <= 4; g++)
			{
				if (b != s && s != g && b!= g)
				{
					printf("%d%d%d\n", b, s, g);
					count++;
				}
			}
		}
	}
	printf("������ɵ���λ��һ����%d��",count);
	system("pause");
	return 0;
}