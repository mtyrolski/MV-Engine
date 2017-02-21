#include "MapManager.hpp"

namespace mv
{
	void MapManager::createWorld(std::string defaultStateName)
	{
		for (int j = 0; j < unitWorldSize.y; j++)
		{
			for (int i = 0; i < unitWorldSize.x; i++)
			{
				map.emplace_back(sf::Vector2i{i,j}, cellDimensions, defaultStateName);
			}
		}
	}


	MapManager::MapManager(sf::Vector2i uWorldSize, const sf::Vector2f & cellDim)
	{
		if (uWorldSize.x <= 0 || cellDim.x <= 0 ||
			uWorldSize.y <= 0 || cellDim.y <= 0)
		{
			Logger::Log(constants::error::mapManager::NEGATIVE_VALUES, Logger::STREAM::BOTH, Logger::TYPE::ERROR);
			return;
		}
		MapManager::unitWorldSize = uWorldSize;
		MapManager::cellDimensions = cellDim;
	}

	sf::Vector2i MapManager::getUnitWorldSize()
	{
		return MapManager::unitWorldSize;
	}
	sf::Vector2f MapManager::getCellDimensions()
	{
		return MapManager::cellDimensions;
	}

	std::vector<Cell>* MapManager::getCellStorage()
	{
		return &map;
	}

	bool MapManager::constructWholeWorld(std::string defaultState)
	{

		if (!StateSystem::isStateExist(defaultState))
		{
			Logger::Log(constants::error::stateSystem::NUMBER_HAS_NOT_FOUND, Logger::STREAM::BOTH, Logger::TYPE::ERROR);
			return false;
		}

		MapManager::createWorld(defaultState);

	}

}

