#include "EntityManager.h"
EntityManager::EntityManager()
{

}

void EntityManager::update() 
{
	//Add entities from m_entitiesToAdd to m_entities
	//Also add entities to the map by its key
	for (auto e : m_entitiesToAdd)
	{
		m_entities.push_back(e);
		m_entityMap[e->tag()].push_back(e);
	}
	//Clear entitiesToAdd
	m_entitiesToAdd.clear();

	//remove entities from m_entities by its state
	removeDeadEntities(m_entities);
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag)
{
	auto entity = std::shared_ptr<Entity>(new Entity(m_totalEntities++, tag));
	m_entitiesToAdd.push_back(entity);
	update();

	return entity;
}

void EntityManager::removeDeadEntities(EntityVec& vec)
{
	vec.erase(std::remove_if(vec.begin(), vec.end(), [](const std::shared_ptr<Entity>& e)
		{
			return !e->isActive();
		}), vec.end());
}

const EntityVec& EntityManager::getEntities()
{
	return m_entities;
}

const EntityVec& EntityManager::getEntities(const std::string& tag)
{
	return m_entityMap[tag];
}



