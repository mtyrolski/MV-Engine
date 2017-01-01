#include "Cell.hpp"

namespace mv
{
	Cell::Cell(sf::Vector2i uPos)
		:unitPosition(uPos)
	{
		shape.setSize(MapManager::getCellDimensions());
		m_shape.setOutlineThickness(m_dimensions.x / 10.0f); //10%

		m_shape.setOutlineColor(sf::Color(120, 133, 139)); //Squirrel grey

		updateTexture();

		m_shape.setPosition(id.x*m_dimensions.x, id.y*m_dimensions.y);

		nextValue = Cell::EMPTY;

	}
}