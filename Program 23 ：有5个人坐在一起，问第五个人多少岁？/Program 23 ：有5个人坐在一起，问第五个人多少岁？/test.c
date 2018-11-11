#define _CRT_SECURE_NO_WARNINGS 1
//题目：有5个人坐在一起，
//问第五个人多少岁？他说比第4个人大2岁。
//问第4个人岁数，他说比第3个人大2岁。
//问第三个人，又说比第2人大两岁。
//问第2个人，说比第一个人大两岁。
//最后问第一个人，他说是10岁。请问第五个人多大？   
//分析：利用递归的方法，递归分为回推和递推两个阶段。
//要想知道第五个人岁数，需知道第四人的岁数，依次类推，推到第一人（10岁），再往回推。
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
	printf("第%d个人的年龄是%d\n",i,age);
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
