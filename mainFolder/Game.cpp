#include "Game.h"

#include <iostream>

Game::Game(const std::string& config)
{
	init(config);
}

void Game::run()
{
	//while (m_running)
	//{
	//	m_entities.update();

	//	if (!m_paused)
	//	{
	//		sEnemySpawner();
	//		sMovement();
	//		sCollision();
	//		sUserInput();
	//	}
	//	
	//	sRender();

	//	//increment the current frame
	//	//may need to be moved when pause implemented
	//	m_currentFrame++;
	//}


}

void Game::init(const std::string & path)
{
	//m_window = initwindow(600, 600, "SoulKnight");
}

void Game::setPaused(bool paused)
{
	m_paused = paused;
}

void Game::sMovement()
{
	/*m_player->cTransform->pos.x += m_player->cTransform->velocity.x;
	m_player->cTransform->pos.y += m_player->cTransform->velocity.y;*/
}

void Game::sUserInput()
{

	//if (key == 'd' || key == 'D') {
	//	if (j == 2) {
	//		j = 0;
	//	}
	//	else {
	//		j++;
	//	}
	//}
	//if (key == 'a' || key == 'A') {
	//	if (j == 0) {
	//		j = 2;
	//	}
	//	else {
	//		j--;
	//	}
	//}
	//if (key == 's' || key == 'S') {
	//	if (i == 2) {
	//		i = 0;
	//	}
	//	else {
	//		i++;
	//	}
	//}
	//if (key == 'w' || key == 'W') {
	//	if (i == 0) {
	//		i = 2;
	//	}
	//	else {
	//		i--;
	//	}
	//}
}

void Game::sLifeSpan(int total)
{

}

void Game::sRender()
{
	cleardevice();

	/*for (auto e : m_entities.getEntities())
	{
		e->cShape->Player.setPosition(e->cTransform->pos.x, e->cTransform->pos.y);
		e->cTransform->angle += 1.0f;
		e->cShape->drawPlayer.setRotation(m_player->cTransform->angle);
		draw(e->cShape->shape);
	}*/

}

void Game::sEnemySpawner()
{
	spawnEnemy();
}

void Game::sCollision()
{
	/*for (auto b : m_entities.getEntities("bullet"))
	{
		for (auto e : m_entities.getEntities("enemy"))
		{

			if()

		}
	}*/
}

void Game::spawnPlayer()
{
	/*auto entity = m_entities.addEntity("player");

	entity->cTransform = std::make_shared<CTransform>(Vec2(200.0f, 200.0f), Vec2(1.0f, 1.0f), 0.0f);

	entity->cShape = std::make_shared<CShape>(32.0f, 8, COLOR(10, 10, 10), COLOR(255, 0, 0), 4.0f);

	entity->cInput = std::make_shared<CInput>();

	m_player = entity;*/
}

void Game::spawnEnemy()
{
	//auto entity = m_entities.addEntity("enemy");

	////float ex = rand() % m_window.getwindowwidth();
	////float ey = rand() % m_window.getwindowheight();

	//entity->cTransform = std::make_shared<CTransform>(Vec2(ex, ey), Vec2(0.0f, 0.0f), 0.0f);

	//entity->cShape = std::make_shared<CShape>();
	// 
	//m_lastEnemySpawnTime = m_currentFrame;
}

void Game::spawnBullet(std::shared_ptr<Entity> entity, const Vec2& mousePos)
{

}

void Game::spawnSpecialWeapon(std::shared_ptr<Entity> entity)
{

}

