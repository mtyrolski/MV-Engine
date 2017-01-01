#include "MapManager.hpp"

namespace mv
{
	void MapManager::init(sf::Vector2i uWorldSize, const sf::Vector2f & celldimensions)
	{
		unitWorldSize = uWorldSize;
		cellDimensions = celldimensions;
	}
	sf::Vector2i & MapManager::getUnitWorldSize()
	{
		return unitWorldSize;
	}
	sf::Vector2f & MapManager::getCellDimensions()
	{
		return cellDimensions;
	}
}

