#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//3*3��������Ϸ
void menu()
{
	printf("-----------------------------------\n");
	printf("----------- 1.��ʼ��Ϸ ------------\n");
	printf("----------- 2.�˳���Ϸ ------------\n");
	printf("-----------------------------------\n");
}

void game()
{
	char table[ROW][COL];       //��ά����洢����

	Inittable(table, ROW, COL); //��ʼ������

	Printtable(table, ROW, COL);//��ӡ����

	char ret = 0;

	while (1)
	{
		Player(table, ROW, COL);    //��ҳ���
		Printtable(table, ROW, COL);//��ӡ����
		ret = WhoWin(table, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

		Computer(table, ROW, COL);  //���Գ���
		Printtable(table, ROW, COL);//��ӡ����
		ret = WhoWin(table, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���ʤ��\n");

	}
	else if (ret == '#')
	{
		printf("����ʤ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}
	Printtable(table, ROW, COL);//��ӡ����

}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			//printf("��Ϸ��ʼ\n");
			game();
			break;
		case 2:
			printf("��Ϸ�˳�\n");
			break;
		default:
			printf("���������ԣ�\n");
			break;
		}
	} while (input != 2);

	return 0;
}