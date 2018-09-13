#ifndef _GAME_H_
#define _GAME_H_

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#define ROW 3
#define COL 3

void Print(char board[ROW][COL], int row, int col);//打印棋盘
void InitBoard(char board[ROW][COL], int row, int col);//初始化棋盘
void PlayerMove(char board[ROW][COL], int row, int col);//玩家走
void ComputerMove(char board[ROW][COL], int row, int col);//电脑走
int JudgeWiner(char board[ROW][COL], int row, int col);//判断输赢
int FullBoard(char board[ROW][COL], int row, int col);//判断平局或继续

#endif //_GAME_H_