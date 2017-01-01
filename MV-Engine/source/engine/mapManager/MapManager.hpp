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
		sf::Vector2i &getUnitWorldSize();
		
		//Returns dimensions of cell (in px)
		sf::Vector2f &getCellDimensions();

	private:

		//Vector of cells which are the surface
		std::vector<Cell> map;

		//World size in units
		static sf::Vector2i unitWorldSize;

		//Dimensions of cell(in px)
		static sf::Vector2f cellDimensions;
	};
}
