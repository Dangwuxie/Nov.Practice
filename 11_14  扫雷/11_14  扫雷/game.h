#ifndef _GAME_H
#define _GAME_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define ROW 9//小棋盘行数
#define COL 9//小棋盘列数
#define ROWS ROW+2 //大棋盘行数
#define COLS COL+2 //大棋盘列数
#define COUNT 10  //每次游戏开始前需要布置的雷的个数；

void InitBoard(char board[ROWS][COLS], int rows, int cols, char ret);//初始化棋盘
void DisplayBoard(char board[ROWS][COLS], int rows, int cols);//打印棋盘
void SetMine(char board[ROWS][COLS], int row, int col);//布雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//扫雷
int GetMine(char a[ROWS][COLS], int x, int y);//获得周围八个格子雷的个数
void SpreadBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y);//展开函数
void RemarkBoard(char show[ROWS][COLS], int row, int col);//标记函数

void test();
void game();
void menu();

#endif //_GAME_H