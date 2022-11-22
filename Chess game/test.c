#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//3*3井字棋游戏
void menu()
{
	printf("-----------------------------------\n");
	printf("----------- 1.开始游戏 ------------\n");
	printf("----------- 2.退出游戏 ------------\n");
	printf("-----------------------------------\n");
}

void game()
{
	char table[ROW][COL];       //二维数组存储数据

	Inittable(table, ROW, COL); //初始化棋盘

	Printtable(table, ROW, COL);//打印棋盘

	char ret = 0;

	while (1)
	{
		Player(table, ROW, COL);    //玩家出手
		Printtable(table, ROW, COL);//打印棋盘
		ret = WhoWin(table, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

		Computer(table, ROW, COL);  //电脑出手
		Printtable(table, ROW, COL);//打印棋盘
		ret = WhoWin(table, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家胜利\n");

	}
	else if (ret == '#')
	{
		printf("电脑胜利\n");
	}
	else
	{
		printf("平局\n");
	}
	Printtable(table, ROW, COL);//打印棋盘

}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			//printf("游戏开始\n");
			game();
			break;
		case 2:
			printf("游戏退出\n");
			break;
		default:
			printf("错误，请重试！\n");
			break;
		}
	} while (input != 2);

	return 0;
}