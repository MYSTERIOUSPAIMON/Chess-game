#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

int IsFull(char table[ROW][COL], int row, int col)
{
	int i = 0;
	for ( i = 0; i < row; i++)
	{
		int j = 0;
		for ( j = 0; j < col; j++)
		{
			if (table[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

void Inittable(char table[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			table[i][j] = ' ';
		}
	}
}

void Printtable(char table[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", table[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");

		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void Player(char table[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("轮到玩家\n");
	while (1)
	{
		printf("请输入坐标:");
		scanf("%d %d", &x, &y);
		if (x >= 1 && y >= 1 && x <= row && y <= col)
		{
			if (table[x - 1][y - 1] == ' ')
			{
				table[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("已有棋子，请重选\n");
		}
		else
			printf("错误，请重试\n");
	}
}

void Computer(char table[ROW][COL], int row, int col)
{
	printf("轮到电脑\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;

		if (table[x][y] == ' ')
		{
			table[x][y] = '#';
			break;
		}
	}
}

char WhoWin(char table[ROW][COL], int row, int col)
{
	int i = 0;
	for ( i = 0; i < row; i++)//判断行
	{
		if (table[i][0] == table[i][1] && table[i][2] == table[i][1] && table[i][0] != ' ')
			return table[i][0];
	}
	for (i = 0; i < row; i++)//判断列
	{
		if (table[0][i] == table[1][i] && table[2][i] == table[1][i] && table[0][i] != ' ')
			return table[0][i];
	}

	//判断对角线
	if (table[0][0] == table[1][1] && table[1][1] == table[2][2] && table[1][1] != ' ')
	{
		return table[1][1];
	}

	if (table[0][2] == table[1][1] && table[1][1] == table[2][0] && table[1][1] != ' ')
	{
		return table[1][1];
	}

	int ret = IsFull(table, row, col);
	if (ret == 1)
	{
		return 'Q';//棋盘满，退出
	}
	return 'C';    //继续
}