#define _CRT_SECURE_NO_WARNINGS 1
//��Ŀ�����������ڼ��ĵ�һ����ĸ���ж�һ�������ڼ���
//�����һ����ĸһ����������жϵڶ�����ĸ��   
//��������������ȽϺã������һ����ĸһ�������ж����������if����жϵڶ�����ĸ��
//1.Monday 2.Tuesday 3.Wednesday 4.Thursday 5.Friday 6.Saturday 7.Sunday
#include <stdio.h>
#include <stdlib.h>
//ע�⣺�и����⣺getchar()��������Ƕ��ʹ�ã���������
int main()
{
	char week;
	printf("Please input the first character :");
	week = getchar();
	if (week=='M' || week=='m')
	{
		printf("The day is Monday!\n");
	}
	else if (week == 'T' || week== 't')
	{
		printf("Please input no.2 character:");
		char weeks;
		scanf("%s", &weeks);
		if (weeks=='U' || weeks=='u' )
		{
			printf("The day is Tuesday!\n");
		}
		else if (weeks=='H' || weeks=='h')
		{
			printf("The day is Thursday!\n");
		}
		else
		{
			printf("error!\n");
		}
	}
	else if (week=='W' || week == 'w')
	{
		printf("The day is Wenesday !\n");
	}
	else if (week=='F' || week=='f')
	{
		printf("The day is Friday !\n");
	}
	else if (week=='S' || week=='s')
	{
		printf("Please input no.2 character:");
		char weeks = getchar();
		if (weeks == 'A' || weeks == 'a')
		{
			printf("The day is Saturday!\n");
		}
		else if (weeks == 'U' || weeks == 'u')
		{
			printf("The day is Sunday!\n");
		}
		else
		{
			printf("error!\n");
		}
	}
	system("pause");
	return 0;
}