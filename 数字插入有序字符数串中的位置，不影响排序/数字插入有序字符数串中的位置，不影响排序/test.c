#define _CRT_SECURE_NO_WARNINGS 1
//有一个整数n，其从左到右各个位上的数字按照升序排列，现在有一个数字target(0-9的整数)，
//判断target应该插入的到数字n的哪个位置才能使n继续保持升序，并且返回target返回的位置
//注意：target与数字串中的数字不重复。
//【输入格式】任意一个各个位呈升序排序的数字n    数字target（二者用空格隔开）
//【输出格式】target在字符串中的位置
//【输入样例】12689  7
//【输出样例】4
#include <stdio.h>
#include <string.h>
int main()
{
	int i = 0;
	char n[10] = "0";
	int target = 0;
	scanf("%s  %c", &n, &target);
	for ( i = 0; i < strlen(n); i++)
	{
		int t = 0;
		if (target > n[i] && target < n[i + 1])
		{
			printf("%d\n", i + 2);
		}
	}
	system("pause");
	return 0;
}