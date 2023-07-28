#include <ctime>
#include <cmath>
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
	
	const int targetFPS = 60;
	const int targetFrameTime = 1000 / targetFPS;

	int startTime, elapsedTime;
	setPosGame(0, 0);
	createMap(15, 27);
	showMap();
	while (m_running)
	{
		m_entities.update();
		sEnemySpawner();
		sRender(); 
		sUserInput();
		sMovement();
		sBulletMovement();
		sCollision();
		m_entities.removeDeadEntities();
		m_currentFrame++;
		//delay(10);
	};
	closegraph();
}

void Game::setPaused(bool paused)
{
	m_paused = paused;
}

void Game::createMap(int r, int c)
{
	m_rows = r;
	m_columns = c;
	m_map.setMap(m_rows, m_columns);
}
void Game::setPosGame(int x, int y)
{
	m_x = x;
	m_y = y;
}
void Game::sMovement()
{
	
	if (m_player->cInput->up == true && m_player->cTransform->pos.y > 75)
	{
		//clear player
		setfillstyle(SOLID_FILL, BLACK);
		bar(
			m_player->cTransform->pos.x,
			m_player->cTransform->pos.y,
			m_player->cTransform->pos.x+m_player->cShape->width,
			m_player->cTransform->pos.y+m_player->cShape->height);

		m_player->cTransform->pos.y -= 25.0f;
		m_player->cInput->up = false;
	}
	else if (m_player->cInput->down == true && m_player->cTransform->pos.y < (getwindowheight() - 50))
	{
		setfillstyle(SOLID_FILL, BLACK);
		bar(
			m_player->cTransform->pos.x,
			m_player->cTransform->pos.y,
			m_player->cTransform->pos.x+m_player->cShape->width,
			m_player->cTransform->pos.y+m_player->cShape->height);

		m_player->cTransform->pos.y += 25.0f;
		m_player->cInput->down = false;
	}
	else if (m_player->cInput->left == true && m_player->cTransform->pos.x > 50)
	{
		setfillstyle(SOLID_FILL, BLACK);
		bar(
			m_player->cTransform->pos.x,
			m_player->cTransform->pos.y,
			m_player->cTransform->pos.x+m_player->cShape->width,
			m_player->cTransform->pos.y+m_player->cShape->height);

		m_player->cTransform->pos.x -= 25.0f;
		m_player->cInput->left = false;
	}
	else if (m_player->cInput->right == true && m_player->cTransform->pos.x < (getwindowwidth() - 50))
	{
		setfillstyle(SOLID_FILL, BLACK);
		bar(
			m_player->cTransform->pos.x,
			m_player->cTransform->pos.y,
			m_player->cTransform->pos.x+m_player->cShape->width,
			m_player->cTransform->pos.y+m_player->cShape->height);

		m_player->cTransform->pos.x += 25.0f;
		m_player->cInput->right = false;
	}
}
void Game::sUserInput()
{
	int key = 0;
	int x, y;

	if (ismouseclick(WM_LBUTTONDOWN))
	{
		getmouseclick(WM_LBUTTONDOWN, x, y);
		spawnBullet(m_player, Vec2(x, y));
		//std::cout << "Disparo" << x<<","<<y << std::endl;
	}

	if (kbhit())
	{
		key = getch();
		if (key == 77)
		{
			m_player->cInput->right = true;
			std::cout << "Presionaste derecha" << std::endl;
		}
		else if (key == 75)
		{
			m_player->cInput->left = true;
			std::cout << "Presionaste izquierda" << std::endl;
		}
		else if (key == 72)
		{
			m_player->cInput->up = true;
			std::cout << "Presionaste arriba" << std::endl;
		}
		else if (key == 80)
		{
			m_player->cInput->down = true;
			std::cout << "Presionaste abajo" << std::endl;
		}
		else if (key == 13)
		{
			return;
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
	std::vector<std::string> orderToRender = {
		"base", "wall", "box", "enemy", "player", "bullet"
	};

	for (auto t : orderToRender) {
		for (auto e : m_entities.getEntities(t))
		{
			e->cShape->draw(e->cTransform->pos.x, e->cTransform->pos.y, 1.0f, e->tag());
		}
	}
}
void Game::sEnemySpawner()
{
	if (m_currentFrame - m_lastEnemySpawnTime >= ENEMY_SPAWN_INTERVAL)
	{
		spawnEnemy(0, 0);
	}
}
void Game::sBulletMovement()
{
	for (auto& bullet : m_entities.getEntities("bullet"))
	{
		
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, BLACK);
		fillellipse(bullet->cTransform->prevPos.x, bullet->cTransform->prevPos.y, 10, 10);

		float deltaX = bullet->cTransform->pos.x - bullet->cTransform->target.x;
		float deltaY = bullet->cTransform->pos.y - bullet->cTransform->target.y;
		float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
		float velx = deltaX / distance;
		float vely = deltaY / distance;
		bullet->cTransform->prevPos = bullet->cTransform->pos; // Guardar la posici�n anterior

		bullet->cTransform->pos.x += velx * - 15.0f;
		bullet->cTransform->pos.y += vely * - 15.0f;

		if (distance <= 2.0f) // Ajusta el valor (5.0f) seg�n el criterio para determinar que la bala alcanz� el objetivo
		{
			bullet->destroy();
			setcolor(BLACK);
			setfillstyle(SOLID_FILL, BLACK);
			fillellipse(bullet->cTransform->pos.x, bullet->cTransform->pos.y, 20, 20);
			
		}

		m_entities.update();
	}
}
void Game::sCollision()
{
	auto bullets = m_entities.getEntities("bullet");
	auto enemies = m_entities.getEntities("enemy");

	for (auto bullet : bullets)
	{
		for (auto enemy : enemies)
		{
			// Calcular la distancia entre la bala y el enemigo
			float deltaX = bullet->cTransform->pos.x - enemy->cTransform->pos.x;
			float deltaY = bullet->cTransform->pos.y - enemy->cTransform->pos.y;
			float distance = sqrt(deltaX * deltaX + deltaY * deltaY);

			// Si la distancia es menor que el radio de colisi�n (ajusta el valor seg�n tus necesidades)
			if (distance < 20.0f)
			{
				// Eliminar la bala y el enemigo
				bullet->destroy();
				enemy->destroy();
			}
		}
	}
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
void Game::spawnEnemy(int i, int j)
{
	auto entity = m_entities.addEntity("enemy");

	float ex = getAleatorio(100, getwindowwidth() - 100);
	float ey = getAleatorio(100, getwindowheight() - 100);

	entity->cTransform = std::make_shared<CTransform>(Vec2(ex, ey), Vec2(2.0f, 2.0f), 0.0f);

	entity->cShape = std::make_shared<CShape>(entity->cTransform->pos.x, entity->cTransform->pos.y, 50, entity->tag());

	m_lastEnemySpawnTime = m_currentFrame;
}
int Game::getAleatorio(int minimo, int maximo) 
{
	return rand() % (maximo - minimo) + minimo;
}
void Game::spawnWall(int i, int j)
{
	auto entity = map_static.addEntity("wall");

	entity->cTransform = std::make_shared<CTransform>(Vec2(j * 40,i * 40), Vec2(0.0f, 0.0f), 0.0f);

	entity->cShape = std::make_shared<CShape>(entity->cTransform->pos.x, entity->cTransform->pos.y, 50, entity->tag());
}
void Game::spawnBox(int i, int j)
{
	auto entity = m_entities.addEntity("box");

	//float mx = ;
	//float my = getwindowheight() / 2.0f;

	entity->cTransform = std::make_shared<CTransform>(Vec2(j * 50, i * 50), Vec2(2.0f, 2.0f), 0.0f);

	entity->cShape = std::make_shared<CShape>(entity->cTransform->pos.x, entity->cTransform->pos.y, 50, entity->tag());
}

void Game::spawnBase(int i, int j)
{
	auto entity = m_entities.addEntity("base");

	//float mx = ;
	//float my = getwindowheight() / 2.0f;

	entity->cTransform = std::make_shared<CTransform>(Vec2(j * 50, i * 50), Vec2(0.0f, 0.0f), 0.0f);

	entity->cShape = std::make_shared<CShape>(entity->cTransform->pos.x, entity->cTransform->pos.y, 50, entity->tag());

}

void Game::spawnBullet(std::shared_ptr<Entity> entity, const Vec2& mousePos)
{
	auto bullet = m_entities.addEntity("bullet");
	std::cout << "Bullet created" << std::endl;

	bullet->cTransform = std::make_shared<CTransform>(entity->cTransform->pos, Vec2(5.0f, 5.0f), mousePos);
	bullet->cShape = std::make_shared<CShape>(entity->cTransform->pos.x, entity->cTransform->pos.y, 50, bullet->tag());

}

void Game::spawnSpecialWeapon(std::shared_ptr<Entity> entity)
{

}

void Game::showMap()
{
	//m_entities.clear()
	for (int i = 0; i < m_map.getRows(); i++)
	{
		for (int j = 0; j < m_map.getColumns(); j++)
		{
			if (m_map.getValue(i, j) == M)
			{
				spawnWall(i, j);
			}
			if (m_map.getValue(i, j) == P)
			{
				spawnPlayer();
			}
			if (m_map.getValue(i, j) == E)
			{
				spawnEnemy(i, j);
			}
		}
	}
}