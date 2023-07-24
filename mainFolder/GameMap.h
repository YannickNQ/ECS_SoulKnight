#pragma once
#include "EntityManager.h"
#include "Map.h"
//#include "../winbgim.h"

class GameMap
{
    Map map;
    int m_cellSize;

public:
    GameMap();
    void setMapSize(int rows, int columns);
    void drawMap(EntityManager& m_entities);
};