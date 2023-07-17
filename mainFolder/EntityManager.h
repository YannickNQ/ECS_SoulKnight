#pragma once

#include "Entity.h"
#include <vector>
#include <map>

typedef std::vector<std::shared_ptr<Entity>> EntityVec;
typedef std::map<std::string, EntityVec> EntityMap;

class EntityManager
{
	EntityVec m_entities;
	EntityVec m_entitiesToAdd;
	EntityMap m_entityMap;
	size_t m_totalEntities = 0;

	void removeDeadEntities(EntityVec& vec)
	{
		/*vec.erase(std::remove_if(vec.begin, vec.end, [](const std::shared_ptr<Entity>& e) {
			return !e->isActive();
			}), vec.end());*/
	}

public:

	EntityManager()
	{

	}

	void update()
	{
		for (auto e : m_entitiesToAdd)
		{
			m_entities.push_back(e);
			m_entityMap[e->tag()].push_back(e);
		}

		m_entitiesToAdd.clear();

		removeDeadEntities(m_entities);

		/*for (auto& [tag, entityVec] : m_entityMap)
		{
			removeDeadEntities(entityVec)
		}*/
	}

	std::shared_ptr<Entity> addEntity(const std::string& tag)
	{
		//std::cout <<"hola ...."<<std::endl;
		auto entity = std::shared_ptr<Entity>(new Entity(m_totalEntities++, tag));
		m_entitiesToAdd.push_back(entity);
		update();

		return entity;
	}

	const EntityVec& getEntities()
	{
		return m_entities;
	}

	const EntityVec& getEntities(const std::string& tag)
	{
		return m_entityMap[tag];
	}

};