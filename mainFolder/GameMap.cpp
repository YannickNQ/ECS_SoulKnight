#include "GameMap.h"
#include "EntityManager.h"

GameMap::GameMap()
{

}

void GameMap::setMapSize(int rows, int columns)
{
    map.setMap(rows, columns);
}

void GameMap::drawMap(EntityManager& m_entities)
{
    for (int i = 0; i < map.getRows(); i++) {
        for (int j = 0; j < map.getColumns(); j++)
        {
            //m_entities->V(xini + j * escala, yini + i * escala, escala);
            auto base = m_entities.addEntity("base");
            base->cShape = std::make_shared<CShape>(j * 40, i * 40, 50, "base");
            if (map.getValue(i, j) == M) {
                //m_entities->StoneWall(j * 40, yini + i * 40);
                auto wall = m_entities.addEntity("wall");
                wall->cShape = std::make_shared<CShape>(j * 40, i * 40, 50, "wall");
            }
            if (map.getValue(i, j) == P) {
                auto player = m_entities.addEntity("player");
                player->cShape = std::make_shared<CShape>(j * 40, i * 40, 50, "player");
            }
            if (map.getValue(i, j) == E) {
                auto player = m_entities.addEntity("enemy");
                player->cShape = std::make_shared<CShape>(j * 40, i * 40, 50, "enemy");
            }

        }
    }
};