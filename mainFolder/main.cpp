#include <iostream>
#include <cmath>
#include "..\winbgim.h"
//#include "Game.h"
#include "Vec2.h"
#include "Components.h"
#include "EntityManager.h"

#include <iostream>

int main()
{	
	CShape* drawingShape = new CShape(5);
	//Vec2* vector = new Vec2(100, 100);
	initwindow(600,600, "Soul");

	EntityManager entityManager;

    // Agregar entidades al EntityManager
    std::shared_ptr<Entity> entity1 = entityManager.addEntity("tag1");
    std::shared_ptr<Entity> entity2 = entityManager.addEntity("tag2");
    std::shared_ptr<Entity> entity3 = entityManager.addEntity("tag1");

    // Obtener todas las entidades del EntityManager
    const EntityVec& allEntities = entityManager.getEntities();
    std::cout << "Todas las entidades:\n";
    for (const auto& entity : allEntities)
    {
        std::cout << "ID: " << entity->id() << ", Tag: " << entity->tag() << std::endl;
    }

	getch();
	closegraph();

	return 0;
}