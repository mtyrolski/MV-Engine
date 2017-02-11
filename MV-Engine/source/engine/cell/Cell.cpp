#include "Cell.hpp"

namespace mv
{
	void Cell::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(shape, states);
	}

	Cell::Cell(sf::Vector2i uPos, sf::Vector2f cellDimensions, std::string stateName)
		:unitPosition(uPos)
	{
		shape.setSize(cellDimensions);
		shape.setOutlineThickness(cellDimensions.x / 10.0f); //10%

		shape.setOutlineColor(constants::cell::FILL_COLOR);

		shape.setPosition(uPos.x*cellDimensions.x, uPos.y*cellDimensions.y);

		if (!StateSystem::isStateExist(state))
		{
			Logger::Log(constants::error::stateSystem::STATE_DOES_NOT_EXIST, Logger::STREAM::BOTH, Logger::TYPE::ERROR);
			state = StateSystem::getNumberOfState(constants::defaults::EMPTY);
		}
		else
			state = StateSystem::getNumberOfState(stateName);
	}

	void Cell::changeState(int shift)
	{
		nextState = state + shift;
		nextState %= StateSystem::getAmmountStates();
		setColor(StateSystem::getColorOfState(state));
	}

	void Cell::changeState()
	{
		changeState(1);
	}

	uint8_t Cell::getState() const
	{
		return state;
	}

	bool Cell::setState(std::string stateName)
	{
		if (StateSystem::getNumberOfState(stateName) != constants::error::stateSystem::ERROR_VALUE)
		{
			state = StateSystem::getNumberOfState(stateName);
			setColor(StateSystem::getColorOfState(stateName));
			return true;
		}

		return false;
	}
}