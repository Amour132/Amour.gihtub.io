#include "game.h"
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void Print(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for(i=0; i<row; i++)
	{
		printf(" %c | %c | %c \n",board[i][0], board[i][1], board[i][2]);
		if(i<row-1)
		{
			 printf("---|---|---\n");
		}
	}
}	
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走\n");
	do
	{
	    printf("请输入坐标：\n");
	    scanf("%d%d", &x, &y);
		if(x>=1 && x<=row && y>=1 && y<=col)
		{
			if(board[x-1][y-1] == ' ')
			{
				board[x-1][y-1] = '+';
				break;
			}
			else
			{
				printf("当前位置已有棋,请重新输入\n");
			}
		}
		else
		{
			printf("输入错误，请重新输入：\n");
		}
	}while(1);
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走\n");
	do
	{
		x = rand() %3;
	    y = rand() %3;
		if(board[x][y] == ' ')
		{
			board[x][y] = '-';
			break;
		}
	}while(1);
}
int FullBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			if(board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
int JudgeWiner(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for(i=0; i<row; i++)
	{
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')  
		{
			return board[i][0];
		}
		else if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
		else if (board[0][0] == board[1][1]&&board[1][1] == board[2][2]&&board[1][1]!=' ')  
		{  
			return board[1][1];  
		}  
		else if (board[0][2] == board[1][1]&&board[1][1] == board[2][0] &&board[1][1]!= ' ')  
		{  
			return board[1][1];  
		}  
	}
			if(FullBoard(board, row , col) == 0)
			{
				return 'x';
			}
			else if(FullBoard(board, row , col) == 1)
			{
				return 'p';
			}	
	return 0;
}
