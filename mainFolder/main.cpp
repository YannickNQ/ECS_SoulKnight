#include <cmath>
#include "..\winbgim.h"
//#include "Game.h"
#include "Vec2.h"
#include "Components.h"

#include <iostream>

int main()
{	
	CShape* drawingShape = new CShape(5);
	//Vec2* vector = new Vec2(100, 100);

	
	initwindow(600, 680, "Pruebas");
	setfillstyle(SOLID_FILL, 8);
	bar(0, 0, 600, 680);

	drawingShape->knightRight(100, 100);
	drawingShape->knightLeft(221, 100);
	drawingShape->grandSlimeRight(342, 100);
	drawingShape->grandSlimeLeft(463, 100);
	drawingShape->witchRight(200,300);
	drawingShape->witchLeft(250,300);

	drawingShape->StoneWall(10, 10);

	getch();
	closegraph();

	return 0;
}