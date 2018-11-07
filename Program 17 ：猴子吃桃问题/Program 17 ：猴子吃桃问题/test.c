#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//题目：猴子吃桃问题：猴子第一天摘下若干个桃子，当即吃了一半，还不过瘾，又多吃了一个
//第二天早上又将剩下的桃子吃了一半，又多吃了一个。以后每天早上都吃前一天剩下的一半零一个
//到第十天早上想吃时，只见剩下一个桃子了。求第一天摘了多少个桃子？
//分析：采用逆向思维的方法，从后往前推断
int main()
{
//第十天剩一个了，可以判断出第九天有(1+1)*2个桃子，
//第八天同样是第九天的桃子个数加一然后乘以2；
	int i = 0;
	int num = 1;
	int sum = 1;
	for ( i = 1; i < 10; i++)
	{
		num = (num + 1) * 2;
		sum += num;
	}
	printf("桃子的总数为%d\n", sum);
	system("pause");
	return 0;
}