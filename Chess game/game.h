#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//���Ŷ���
#define ROW 3
#define COL 3

//��������
void Inittable(char table[ROW][COL], int row, int col);

void Printtable(char table[ROW][COL], int row, int col);

void Player(char table[ROW][COL], int row, int col);

void Computer(char table[ROW][COL], int row, int col);

char WhoWin(char table[ROW][COL], int row, int col);