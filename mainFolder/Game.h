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
	int m_score = 0;
	int m_window;
	int m_currentFrame = 0;
	int m_lastEnemySpawnTime = 0;
	bool m_paused = false;
	bool m_running = true;
	float m_x;
	float m_y;
	Map m_map;

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

	void spawnPlayer();
	void spawnEnemy();
	void spawnBullet(std::shared_ptr<Entity> entity, const Vec2& mousePos);
	void spawnSpecialWeapon(std::shared_ptr<Entity> entity);
	void setPosGame(Vec2& position);

public:
	Game(const std::string& config);

	void run();
};