#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "engine/config/Config.hpp"
#include "engine/mapManager/MapManager.hpp"

namespace mv
{
	class Cell : public sf::Drawable
	{
	public:

		Cell(sf::Vector2i uPos);

	private:

		//Shape of cell
		sf::RectangleShape shape;

		//State of cell
		uint8_t state;

		//Position in unit system
		const sf::Vector2i unitPosition;
	};
}
