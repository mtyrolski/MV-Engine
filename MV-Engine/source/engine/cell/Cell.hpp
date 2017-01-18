#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "engine/config/Config.hpp"
#include "engine/stateSystem/StateSystem.hpp"

namespace mv
{
	class Cell : public sf::Drawable
	{
		
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	public:

		Cell(sf::Vector2i uPos, sf::Vector2f cellDimensions);

		//Change state for given shift
		void changeState(int shift);

		//Change state for 1 
		void changeState();

		//Returns number of state
		uint8_t getState();

		//Change cell's state to given name
		//returns false if state hasn't been changed
		//returns true if state has been changed
		bool setState(std::string stateName);

		

	private:

		//Shape of cell
		sf::RectangleShape shape;

		//State of cell
		uint8_t state;

		//State of cell in next cycle
		uint8_t nextState;

		//Position in unit system
		const sf::Vector2i unitPosition;
	};
}
