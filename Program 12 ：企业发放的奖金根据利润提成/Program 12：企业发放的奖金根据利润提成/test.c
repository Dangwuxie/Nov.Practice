#define _CRT_SECURE_NO_WARNINGS 1
//题目：企业发放的奖金根据利润提成。利润l低于或等于10万时，奖金可提10%；
//高于10万，低于20万时，低于10万的部分提成10%，10-20万的部分提成7.5%；
//20万到40万之间时，高于20万的提成5%；
//40-60万之间时，高于40万的部分提成3%；
//60-100万之间时，高于60万的部分提成1.5%；
//高于100万时，超过100万的部分提成1%；
//从键盘输入当月利润l，求应该发放奖金总数？
//分析：请利用数轴来分界。注意定义时需要把奖金定义成成长型。
#include <stdio.h>
#include <stdlib.h>
//自己做的：直接用if...else...语句实现其功能；还需改进；
int main()
{
	double i = 0;
	double num = 0;
	printf("请输入当月利润：");
	scanf("%lf", &i);	
		if (i <= 10.0)
		{
			num = i*0.1;
		}
		else if (i>10.0 && i<=20.0)
		{
			num = 10*0.1 + (i-10)*0.075;
		}
		else if (i>20.0 && i<=40.0)
		{
			num = 10*0.1 + 10*0.075 + (i-20)*0.05;
		}
		else if (i>40.0 && i<=60.0)
		{
			num = 10*0.1 + 10*0.075 + 20*0.05 + (i-40)*0.03;
		}
		else if (i>60.0 && i<=100.0)
		{
			num = 10*0.1 + 10*0.075 + 20*0.05 + 20*0.03 + (i-60)*0.015;
		}
		else
		{
			num = 10*0.1 + 10*0.075 + 20*0.05 + 20*0.03 + 40*0.015 + (i-100)*0.01;
		}
		printf("应该发放的奖金为%f万", num);
	system("pause");
	return 0;
}