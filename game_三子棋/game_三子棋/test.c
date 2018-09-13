#include "game.h"
void menu2()
{
	printf("��ѡ���Ѷȣ�  1.��*****\n");
	printf("************  2.����*****\n");
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
	InitBoard(board, row, col);//��ʼ������
	Print(board, row, col);//��ӡ����
	do
	{
		PlayerMove(board, row ,col);//�����
		
		Print(board, row, col);
		ret = JudgeWiner(board, row, col);
		if(ret !='x')
		{
			break;
		}
		ComputerMove(board, row, col);//������
		system("cls");
		Print(board, row, col);//�ٴδ�ӡ
		ret = JudgeWiner(board, row, col);
		if(ret!='x')
		{
			break;
		}
	}while(1);
	ret = JudgeWiner(board, row, col);
	if(ret == '+')
	{
		printf("��ϲ���ʤ��\n");
	}
	else if(ret == '-')
	{
		printf("���ź������Ի�ʤ\n");
	}
	else if(ret == 'p')
	{
		printf("ƽ��\n");
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//��ÿ�β��������������һ��
	do
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch(input)
		{
		case 0:
			printf("��Ϸ����\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}

	}while(input);

	return 0;
}