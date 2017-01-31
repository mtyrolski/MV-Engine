#pragma once

#include "engine/cell/Cell.hpp"
#include <vector>

namespace mv
{
	class MapManager final
	{
	private:

		static void createWorld(std::string defaultStateName);

	public:

		//Initialization (on the begining of game process)
		//returns false if unitWorldSize<=0 || cellDimensions<=0
		static bool init(sf::Vector2i uWorldSize, const sf::Vector2f& celldimensions);

		//Returns world size in units
		static sf::Vector2i getUnitWorldSize();
		
		//Returns dimensions of cell (in px)
		static sf::Vector2f getCellDimensions();
		
		//Returns pointer to cell's vector
		static std::vector<Cell> *getCellStorage();

		//Construct whole world 
		static bool constructWholeWorld(std::string defaultState);

	private:

		//Vector of cells which are the surface
		static std::vector<Cell> map;

		//World size in units
		static sf::Vector2i unitWorldSize;

		//Dimensions of cell(in px)
		static sf::Vector2f cellDimensions;
	};
}
