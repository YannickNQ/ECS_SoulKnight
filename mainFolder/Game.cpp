#include "Game.h"

Game::Game(const std::string& config)
{
	init(config);
}


void Game::init(const std::string& path)
{
	//std::ifstream fin(path);

	m_window = initwindow(1080, 600, "SoulKnight");

	spawnPlayer();
}

void Game::run()
{
	setcurrentwindow(m_window);
	while (m_running)
	{
		m_entities.update();

		sEnemySpawner();
		sMovement();
		sCollision();
		sUserInput();
		sRender();

		m_currentFrame++;
	};
	closegraph();
}

void Game::setPaused(bool paused)
{
	m_paused = paused;
}


void Game::sMovement()
{
	if (m_player->cInput->up == true)
	{
		m_player->cTransform->pos.y -= 25.0f;
		m_player->cInput->up = false;
	}
	else if (m_player->cInput->down == true)
	{
		m_player->cTransform->pos.y += 25.0f;
		m_player->cInput->down = false;
	}
	else if (m_player->cInput->left == true)
	{
		m_player->cTransform->pos.x -= 25.0f;
		m_player->cInput->left = false;
	}
	else if (m_player->cInput->right == true)
	{
		m_player->cTransform->pos.x += 25.0f;
		m_player->cInput->right = false;
	}
}
void Game::sUserInput()
{
	int key = 0;
	while (key != 13)
	{
		key = getch();
		if (key == 77)
		{
			m_player->cInput->right = true;
			std::cout << "Presionaste derecha" << std::endl;
			break;
		}
		if (key == 75)
		{
			m_player->cInput->left = true;
			std::cout << "Presionaste izquierda" << std::endl;
			break;
		}
		if (key == 72)
		{
			m_player->cInput->up = true;
			std::cout << "Presionaste arriba" << std::endl;
			break;
		}
		if (key == 80)
		{
			m_player->cInput->down = true;
			std::cout << "Presionaste abajo" << std::endl;
			break;
		}
	}
}
void Game::sLifeSpan(int total)
{

}
void Game::sAnimation()
{

}
void Game::sRender()
{
	cleardevice();

	for (auto e : m_entities.getEntities())
	{
		e->cShape->draw(e->cTransform->pos.x, e->cTransform->pos.y, 1.0f, e->tag());
	}
	getch();
}
void Game::sEnemySpawner()
{
	spawnEnemy();
}
void Game::sCollision()
{

}

void Game::spawnPlayer()
{
	auto entity = m_entities.addEntity("player");

	float mx = getwindowwidth() / 2.0f;
	float my = getwindowheight() / 2.0f;

	entity->cTransform = std::make_shared<CTransform>(Vec2(mx, my), Vec2(2.0f, 2.0f), 0.0f);

	entity->cShape = std::make_shared<CShape>(entity->cTransform->pos.x, entity->cTransform->pos.y, 50, entity->tag());

	entity->cInput = std::make_shared<CInput>();

	m_player = entity;

}
void Game::spawnEnemy()
{
	auto entity = m_entities.addEntity("enemy");

	float ex = rand() % getwindowwidth();
	float ey = rand() % getwindowheight();

	entity->cTransform = std::make_shared<CTransform>(Vec2(ex, ey), Vec2(0.0f, 0.0f), 0.0f);

	entity->cShape = std::make_shared<CShape>(entity->cTransform->pos.x, entity->cTransform->pos.y, 50, entity->tag());

	m_lastEnemySpawnTime = m_currentFrame;

}
void Game::spawnBullet(std::shared_ptr<Entity> entity, const Vec2& mousePos)
{

}
void Game::spawnSpecialWeapon(std::shared_ptr<Entity> entity)
{

}