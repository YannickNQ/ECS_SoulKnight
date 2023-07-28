#pragma once
#include "../winbgim.h"
#include "Entity.h"
#include "EntityManager.h"
#include <iostream>
#include <fstream>
#include "Map.h"

struct PlayerConfig { int CR; };
struct EnemyConfig { int CR; };
struct BulletConfig { int CR; };
struct WeaponConfig { int CR; };

class Game
{
	EntityManager m_entities;
	EntityManager map_static;
	int m_score = 0;
	int m_window;
	int m_currentFrame = 0;
	int m_lastEnemySpawnTime = 0;
	bool m_paused = false;
	bool m_running = true;
	int m_rows;
	int m_columns;
	int m_x;
	int m_y;
	Map m_map;
	const float ENEMY_SPAWN_INTERVAL = 60;
	const float BULLET_SPEED = 5.0f;

	PlayerConfig m_playerConfig;
	EnemyConfig m_enemyConfig;
	BulletConfig m_bulletConfig;
	WeaponConfig m_weaponConfig;

	std::shared_ptr<Entity> m_player;

	void init(const std::string& config);
	void setPaused(bool paused);

	void sMovement();
	void sUserInput();
	void sLifeSpan(int total);
	void sAnimation();
	void sRender();
	void sEnemySpawner();
	void sCollision();
	void sBulletMovement();

	void spawnPlayer();
	void spawnWall(int i, int j);
	void spawnBox(int i, int j);
	void spawnEnemy(int i, int j);
	void spawnBase(int i, int j);
	void spawnBullet(std::shared_ptr<Entity> entity, const Vec2& mousePos);
	void spawnSpecialWeapon(std::shared_ptr<Entity> entity);
	void setPosGame(int x, int y);
	void createMap(int r, int c);
	void showMap();
	int getAleatorio(int minimo, int maximo);

public:
	Game(const std::string& config);

	void run();
};