#include "game.h"
void menu2()
{
	printf("请选择难度：  1.简单*****\n");
	printf("************  2.困难*****\n");
}
void menu()
{
	printf("*************************\n");
	printf("*******   1.play   ******\n");
	printf("*******   0.exit   ******\n");
	printf("*************************\n");
}
void game()
{
	char ret = '0';
	int row = ROW;
	int col = COL;
	char board[ROW][COL];
	InitBoard(board, row, col);//初始化棋盘
	Print(board, row, col);//打印棋盘
	do
	{
		PlayerMove(board, row ,col);//玩家走
		
		Print(board, row, col);
		ret = JudgeWiner(board, row, col);
		if(ret !='x')
		{
			break;
		}
		ComputerMove(board, row, col);//电脑走
		system("cls");
		Print(board, row, col);//再次打印
		ret = JudgeWiner(board, row, col);
		if(ret!='x')
		{
			break;
		}
	}while(1);
	ret = JudgeWiner(board, row, col);
	if(ret == '+')
	{
		printf("恭喜你获胜了\n");
	}
	else if(ret == '-')
	{
		printf("很遗憾，电脑获胜\n");
	}
	else if(ret == 'p')
	{
		printf("平局\n");
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//让每次产生的随机数都不一样
	do
	{
		menu();
		printf("请选择：\n");
		scanf("%d", &input);
		switch(input)
		{
		case 0:
			printf("游戏结束\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("选择错误，请重新选择：\n");
			break;
		}

	}while(input);

	return 0;
}