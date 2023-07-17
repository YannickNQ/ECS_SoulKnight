#include <cmath>
#include "..\winbgim.h"
//#include "Game.h"
#include "Vec2.h"
#include "Matrix.h"
#include "Components.h"
#include "EntityManager.h"


#include <iostream>

int main()
{	
    CShape* drawingShape = new CShape(5);
	//Vec2* vector = new Vec2(100, 100);

	//Vec2 v3(200, 200);

	//std::cin.get();
	initwindow(600, 680, "Pruebas");

	Juego j;
    j.setFilas(10);
    j.setColumnas(20);
    j.setPosJuego(10,10);
    j.setEscala(5);
    j.crearMatriz();
    j.mostrarJuego();
	
	getch();
	closegraph();

	return 0;
}