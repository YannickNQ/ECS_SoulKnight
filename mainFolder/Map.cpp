#include "Map.h";

Map::Map()
{

}

void Map::setMap(int r, int c)
{
    rows = r;
    columns = c;
    game = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        game[i] = new int[columns];
    };

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            game[i][j] = 0;
        }
    };

    for (int i = 0; i < columns; i++)
    {
        game[0][i] = M;
        game[rows - 1][i] = M;
    };

    for (int i = 0; i < rows; i++)
    {
        game[i][0] = M;
        game[i][columns - 1] = M;
    };
}

int Map::getRows() 
{
    return rows;
}

int Map::getColumns() 
{
    return columns;
}

int Map::getValue(int i, int j) 
{
    return game[i][j];

}