#define _CRT_SECURE_NO_WARNINGS 1
//��Ŀ����һ��3*3����Խ���Ԫ��֮��   
//�������������˫��forѭ�����������ά���飬�ٽ�a[i][i]�ۼӺ������
//����֮�������ʱ�򣬿�����������Ÿ������м��Կո������
//����ÿ����һ������һ�λس�����ֱ������Ÿ�����
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int arr[3][3] = { 0 };
	int i = 0;
	int j = 0;
	printf("Please input 3*3 's intger:\n");
	for ( i = 0; i < 3; i++)
	{
		for ( j = 0; j < 3; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	int tmp = 0;
	tmp = arr[0][0] + arr[1][1] + arr[2][2] + arr[2][0] + arr[1][1] + arr[0][2];
	printf("�Խ���֮��Ϊ%d\n", tmp);
	system("pause");
	return 0;
}