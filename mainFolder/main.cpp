#include <cmath>
#include "..\winbgim.h"
//#include "Game.h"
#include "Vec2.h"
#include "Components.h"
#include "EntityManager.h"

#include <iostream>

int main()
{	z
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

    // Obtener entidades por etiqueta
    const EntityVec& tag1Entities = entityManager.getEntities("tag1");
    std::cout << "Entidades con etiqueta 'tag1':\n";
    for (const auto& entity : tag1Entities)
    {
        std::cout << "ID: " << entity->id() << ", Tag: " << entity->tag() << std::endl;
    }

    // Eliminar una entidad
    entity2->destroy();

    // Actualizar el EntityManager para eliminar las entidades muertas
    entityManager.update();

    // Obtener todas las entidades actualizadas
    const EntityVec& updatedEntities = entityManager.getEntities();
    std::cout << "Todas las entidades actualizadas:\n";
    for (const auto& entity : updatedEntities)
    {
        std::cout << "ID: " << entity->id() << ", Tag: " << entity->tag() << std::endl;
    }

    return 0;
}