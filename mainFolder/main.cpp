#include <iostream>
#include <cmath>
#include "..\winbgim.h"
//#include "Game.h"
#include "Vec2.h"
#include "Components.h"
#include "EntityManager.h"
#include "Matrix.h"

#include <iostream>

int main()
{	
	//CShape* drawingShape = new CShape(5);
	//Vec2* vector = new Vec2(100, 100);
	initwindow(1200,800, "SoulKnight");
	setfillstyle(SOLID_FILL,8);
	bar(0,0,1200,800);

	EntityManager entityManager;

    // Agregar entidades al EntityManager
    auto entity1 = entityManager.addEntity("tag1");
    
	Juego j;
    j.setFilas(10);
    j.setColumnas(20);
    j.setPosJuego(10,10);
    j.crearMatriz();
    j.mostrarJuego();

	getch();
	closegraph();

	return 0;
}