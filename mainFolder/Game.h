#pragma once
#include "Entity.h"
#include "EntityManager.h"

#include "../winbgim.h"

class Game
{
	EntityManager m_entities;
	int m_score = 0;
	int m_currentFrame = 0;
	int m_lastEnemySpawnTime = 0;
	bool m_paused = false;
	bool m_running = true;

	std::shared_ptr<Entity> m_player;

	void init(const std::string& config);
	void setPaused(bool paused);

	void sMovement();
	void sUserInput();
	void sLifeSpan();
	void sRender();
	void SEnemySpawner();
	void sCollision();

	void spawnPlayer();
	void spawnEnemy();
	void spawnBullet(std::shared_ptr<Entity> entity, const Vec2& mousePos);
	void spawnSpecialWeapon(std::shared_ptr<Entity> entity);

public:
	Game(const std::string& config);

	void run();
};