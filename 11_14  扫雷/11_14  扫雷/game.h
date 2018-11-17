#ifndef _GAME_H
#define _GAME_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define ROW 9//С��������
#define COL 9//С��������
#define ROWS ROW+2 //����������
#define COLS COL+2 //����������
#define COUNT 10  //ÿ����Ϸ��ʼǰ��Ҫ���õ��׵ĸ�����

void InitBoard(char board[ROWS][COLS], int rows, int cols, char ret);//��ʼ������
void DisplayBoard(char board[ROWS][COLS], int rows, int cols);//��ӡ����
void SetMine(char board[ROWS][COLS], int row, int col);//����
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//ɨ��
int GetMine(char a[ROWS][COLS], int x, int y);//�����Χ�˸������׵ĸ���
void SpreadBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y);//չ������
void RemarkBoard(char show[ROWS][COLS], int row, int col);//��Ǻ���

void test();
void game();
void menu();

#endif //_GAME_H