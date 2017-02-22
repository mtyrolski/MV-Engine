#pragma once

#include <vector>

#include "MV/cell/Cell.hpp"

namespace mv
{
	class MapManager final
	{
		/* ===Objects=== */
	public:
	protected:
	private:
		//Vector of cells which are the surface
		std::vector<Cell> map;

		//World size in units
		sf::Vector2i unitWorldSize{ 0,0 };

		//Dimensions of cell(in px)
		sf::Vector2f cellDimensions{ 0,0 };

		uint8_t initialState;

		/* ===Methods=== */
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

		//Construct whole world with default state
		bool constructWholeWorld(const std::string&defaultState);

		//Uptades cells (to next state)
		void updateCells();

		//Sets default state
		void setDefaultState(Cell&);

		//Sets default state in each cell
		void resetAllCells();

		//Sets outline color in each cell
		void setOutlineColor(const sf::Color& color);

		//Checks that object with given position is in map
		bool isInMap(sf::Vector2i& unitPosition);

		//Checks that object with given position is in map
		bool isInMap(unsigned int i, unsigned int j);
	
	protected:
	private:
		void createWorld(uint8_t defaultStateNumber);
	};
}
