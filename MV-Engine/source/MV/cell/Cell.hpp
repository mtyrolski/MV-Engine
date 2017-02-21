#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "MV/config/Config.hpp"
#include "MV/stateSystem/StateSystem.hpp"

namespace mv
{
	class Cell : public sf::Drawable
	{
		/* ===Objects=== */
	public:
	protected:
	private:
		//Shape of cell
		sf::RectangleShape shape;

		//State of cell
		uint8_t state;

		//State of cell in next cycle
		uint8_t nextState;

		//Position in unit system
		const sf::Vector2i unitPosition;

		/* ===Methods=== */
	public:

		Cell(sf::Vector2i uPos = { 0,0 }, sf::Vector2f cellDimensions = { 0,0 }, std::string stateName = constants::defaults::EMPTY);

		//Change state for given shift
		void changeState(int shift);

		//Change state for 1 
		void changeState();

		//Returns number of state
		uint8_t getState() const;

		//Change cell's state to given name
		//returns false if state hasn't been changed
		//returns true if state has been changed
		bool setState(std::string stateName);

		//Updates cell state to next state
		void update();
	protected:
	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		void setColor(sf::Color color);
	};
}
