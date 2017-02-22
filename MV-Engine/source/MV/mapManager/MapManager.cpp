#include "MapManager.hpp"

namespace mv
{
	void MapManager::createWorld(uint8_t defaultStateNumber)
	{
		for (int j = 0; j < unitWorldSize.y; j++)
		{
			for (int i = 0; i < unitWorldSize.x; i++)
			{
				map.emplace_back(sf::Vector2i{i,j}, cellDimensions, defaultStateNumber);
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

	bool MapManager::constructWholeWorld(const std::string& defaultState)
	{
		initialState = StateSystem::getNumberOfState(defaultState);

		if (!StateSystem::isStateExist(initialState))
		{
			Logger::Log(constants::error::stateSystem::NUMBER_HAS_NOT_FOUND, Logger::STREAM::BOTH, Logger::TYPE::ERROR);
			return false;
		}

		MapManager::createWorld(initialState);

	}

	void MapManager::updateCells()
	{
		for (auto&var : map)
			var.update();
		
	}

	void MapManager::setDefaultState(Cell& cell)
	{
		cell.setState(initialState);
	}

	void MapManager::resetAllCells()
	{
		for (auto&var : map)
			var.setState(initialState);
	}
}

