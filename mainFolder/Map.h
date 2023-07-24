#pragma once
#include <random>

#define M 100
#define P 200
#define C 300
#define T 400
#define E 500

class Map
{
	int** game;
	int rows;
	int columns;
public:
	Map();
	void setMap(int r, int c);
	int getRows();
	int getColumns();
	int getValue(int i, int j);
};