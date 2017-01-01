#include "Cell.hpp"

namespace mv
{
	Cell::Cell(sf::Vector2i uPos)
		:unitPosition(uPos)
	{
		shape.setSize(MapManager::getCellDimensions());
		shape.setOutlineThickness(MapManager::getCellDimensions().x / 10.0f); //10%


		updateTexture();

		m_shape.setPosition(id.x*m_dimensions.x, id.y*m_dimensions.y);

		nextValue = Cell::EMPTY;

	}
}