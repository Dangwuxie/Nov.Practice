#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#ifndef _GAME_H
#define _GAME_H
#define ROW 3
#define COL 3
void test();//������Ϸ�˵�
void menu();//�˵�
void game();//��Ϸ����
void InitBoard(char board[ROW][COL], int row, int col);//��ʼ������
void DisplayBoard(char board[ROW][COL], int row, int col);//��ӡ����
void ComputerMove(char board[ROW][COL], int row, int col);//������һ��
char IsWin(char board[ROW][COL], int row, int col);//�ж��Ƿ�ֳ�ʤ��
void PlayerMove(char board[ROW][COL], int row, int col);//������һ��
int IsFull(char board[ROW][COL], int row, int col);//�ж������Ƿ����������˻�û�ֳ�ʤ���Ļ�����ƽ��

#endif //_GAME_H