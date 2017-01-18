#pragma once

#include "engine/cell/Cell.hpp"
#include <vector>

namespace mv
{
	class MapManager final
	{
	public:

		//Initialization (on the begining of game process)
		static void init(sf::Vector2i uWorldSize, const sf::Vector2f& celldimensions);

		//Returns world size in units
		static sf::Vector2i getUnitWorldSize();
		
		//Returns dimensions of cell (in px)
		static sf::Vector2f getCellDimensions();
		
		//Returns pointer to cell's vector
		static std::vector<Cell> *getCellStorage();

	private:

		//Vector of cells which are the surface
		static std::vector<Cell> map;

		//World size in units
		static sf::Vector2i unitWorldSize;

		//Dimensions of cell(in px)
		static sf::Vector2f cellDimensions;
	};
}
