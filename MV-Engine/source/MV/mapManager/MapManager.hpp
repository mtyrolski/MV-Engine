#pragma once

#include "MV/cell/Cell.hpp"
#include <vector>

namespace mv
{
	class MapManager final
	{
	private:

		void createWorld(std::string defaultStateName);

	public:

		//Constructor (on the begining of game process)
		//returns false if unitWorldSize<=0 || cellDimensions<=0
		MapManager(sf::Vector2i uWorldSize, const sf::Vector2f& celldimensions);

		//Returns world size in units
		sf::Vector2i getUnitWorldSize();
		
		//Returns dimensions of cell (in px)
		sf::Vector2f getCellDimensions();
		
		//Returns pointer to cell's vector
		std::vector<Cell> *getCellStorage();

		//Construct whole world 
		bool constructWholeWorld(std::string defaultState);

		//Uptades cells (to next state)
		void updateCells();

	private:

		//Vector of cells which are the surface
		std::vector<Cell> map;

		//World size in units
		sf::Vector2i unitWorldSize{ 0,0 };

		//Dimensions of cell(in px)
		sf::Vector2f cellDimensions{ 0,0 };
	};
}
