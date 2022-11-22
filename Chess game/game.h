#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//符号定义
#define ROW 3
#define COL 3

//函数声明
void Inittable(char table[ROW][COL], int row, int col);

void Printtable(char table[ROW][COL], int row, int col);

void Player(char table[ROW][COL], int row, int col);

void Computer(char table[ROW][COL], int row, int col);

char WhoWin(char table[ROW][COL], int row, int col);