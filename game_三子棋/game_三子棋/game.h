#ifndef _GAME_H_
#define _GAME_H_

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#define ROW 3
#define COL 3

void Print(char board[ROW][COL], int row, int col);//��ӡ����
void InitBoard(char board[ROW][COL], int row, int col);//��ʼ������
void PlayerMove(char board[ROW][COL], int row, int col);//�����
void ComputerMove(char board[ROW][COL], int row, int col);//������
int JudgeWiner(char board[ROW][COL], int row, int col);//�ж���Ӯ
int FullBoard(char board[ROW][COL], int row, int col);//�ж�ƽ�ֻ����

#endif //_GAME_H_