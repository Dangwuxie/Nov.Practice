#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//题目：两个乒乓球队进行比赛，各出三人。甲队为a,b,c三人，乙队为x,y,z三人。
//已抽签决定比赛名单。有人向队员打听比赛的名单。
//a说他不和x比，c说他不和x,z比，请编程序找出三队赛手的名单。   
//分析：判断素数的方法：用一个数分别去除2到sqrt(这个数)，
//如果能被整除,则表明此数不是素数，反之是素数。
//int main()
//{
//分析：甲队A、B、C三个人，一对一匹配X、Y、Z三个人（用三个字符表示）
//三层嵌套循环，A逐个匹配XYZ,然后是B，
//两层循环进入后，判断，如果A和B匹配的不是XYZ中同一个人
//难么，由C来逐个匹配，C的循环内，判断，如果前面AB匹配的跟C匹配的不是同一个人
//最后，判断，如果A不跟X匹配，C既不跟X匹配，也不跟Z匹配，那么输出匹配的结果
	//char a, b, c;
	//for ( a = 'x'; a <= 'z'; a++)
	//{
	//	for ( b = 'x'; b <= 'z'; b++)
	//	{
	//		if (a!=b)
	//		{
	//			for ( c = 'x'; c <= 'z'; c++)
	//			{
	//				if (a != c && b != c)
	//				{
	//					if (a!='x'&& c!='x'&& c!='z')
	//					{
	//						printf("a--%c b--%c c--%c\n ", a, b, c);
	//					}
	//				}
	//			}
	//		}
//		}
//	}
//	system("pause");
//	return 0;
//}
//int main()
//{
//	char a[] = "abcdefg";
//	printf("%d\n", sizeof(a) / sizeof(a[0]));
//	printf("%d\n", strlen(a));
//
//	system("pause");
//	return 0;
//}