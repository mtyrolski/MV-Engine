#include "MapManager.hpp"

namespace mv
{
	std::vector<Cell> MapManager::map;
	sf::Vector2i MapManager::unitWorldSize = { 0,0 };
	sf::Vector2f MapManager::cellDimensions = { 0,0 };

	bool MapManager::init(sf::Vector2i uWorldSize, const sf::Vector2f & celldimensions)
	{
		if (uWorldSize.x <= 0 || cellDimensions.x <= 0 ||
			uWorldSize.y <= 0 || cellDimensions.y <= 0)
		{
			Logger::Log(constants::error::mapManager::NEGATIVE_VALUES, Logger::STREAM::BOTH, Logger::TYPE::ERROR);
			return false;
		}
		MapManager::unitWorldSize = uWorldSize;
		MapManager::cellDimensions = celldimensions;
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

	bool MapManager::constructWholeWorld(uint8_t state)
	{
		if (MapManager::cellDimensions.x == 0 || MapManager::cellDimensions.y == 0)
		{
			return false;
		}
	}
}

