#include "Cell.hpp"

namespace mv
{
	Cell::Cell(sf::Vector2i uPos)
		:unitPosition(uPos)
	{
		shape.setSize(MapManager::getCellDimensions());
		shape.setOutlineThickness(MapManager::getCellDimensions().x / 10.0f); //10%

		shape.setOutlineColor(constants::cell::FILL_COLOR); 

		shape.setPosition(uPos.x*MapManager::getCellDimensions().x, uPos.y*MapManager::getCellDimensions().y);
	}

	void Cell::changeState(int shift)
	{
		nextState = state + shift;
		//nextState%=AMMOUNT_STATES
	}

	void Cell::changeState()
	{
		changeState(1);
	}

	uint8_t Cell::getState()
	{
		return state;
	}

	std::string Cell::getStateName()
	{
		return std::string(); //to do...
	}

	bool Cell::setState(std::string stateName)
	{
		return false; //to do...
	}
}