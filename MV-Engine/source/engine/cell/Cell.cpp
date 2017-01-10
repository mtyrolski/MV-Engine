#include "Cell.hpp"

namespace mv
{
	Cell::Cell(sf::Vector2i uPos, sf::Vector2f cellDimensions)
		:unitPosition(uPos)
	{
		shape.setSize(cellDimensions);
		shape.setOutlineThickness(cellDimensions.x / 10.0f); //10%

		shape.setOutlineColor(constants::cell::FILL_COLOR); 

		shape.setPosition(uPos.x*cellDimensions.x, uPos.y*cellDimensions.y);
	}

	void Cell::changeState(int shift)
	{
		nextState = state + shift;
		nextState %= StateSystem::getAmmountStates();
	}

	void Cell::changeState()
	{
		changeState(1);
	}

	uint8_t Cell::getState()
	{
		return state;
	}

	bool Cell::setState(std::string stateName)
	{
		if (StateSystem::getNumberOfState(stateName) != constants::error::stateSystem::ERROR_VALUE)
		{
			state = StateSystem::getNumberOfState(stateName);
			return true;
		}

		return false;
	}
}