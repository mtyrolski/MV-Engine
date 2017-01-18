#include "MapManager.hpp"

namespace mv
{
	std::vector<Cell> MapManager::map;
	sf::Vector2i MapManager::unitWorldSize;
	sf::Vector2f MapManager::cellDimensions;

	void MapManager::init(sf::Vector2i uWorldSize, const sf::Vector2f & celldimensions)
	{
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
}

