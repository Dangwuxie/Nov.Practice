#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#ifndef _GAME_H
#define _GAME_H
#define ROW 3
#define COL 3
void test();//进入游戏菜单
void menu();//菜单
void game();//游戏函数
void InitBoard(char board[ROW][COL], int row, int col);//初始化棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);//打印棋盘
void ComputerMove(char board[ROW][COL], int row, int col);//电脑走一步
char IsWin(char board[ROW][COL], int row, int col);//判断是否分出胜负
void PlayerMove(char board[ROW][COL], int row, int col);//电脑走一步
int IsFull(char board[ROW][COL], int row, int col);//判断棋盘是否已满，满了还没分出胜负的话就是平局

#endif //_GAME_H