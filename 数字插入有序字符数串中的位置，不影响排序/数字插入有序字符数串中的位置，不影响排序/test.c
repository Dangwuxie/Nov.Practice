#define _CRT_SECURE_NO_WARNINGS 1
//��һ������n��������Ҹ���λ�ϵ����ְ����������У�������һ������target(0-9������)��
//�ж�targetӦ�ò���ĵ�����n���ĸ�λ�ò���ʹn�����������򣬲��ҷ���target���ص�λ��
//ע�⣺target�����ִ��е����ֲ��ظ���
//�������ʽ������һ������λ���������������n    ����target�������ÿո������
//�������ʽ��target���ַ����е�λ��
//������������12689  7
//�����������4
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