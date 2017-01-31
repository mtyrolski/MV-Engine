#include "Mouse.hpp"

namespace mv
{
	void Mouse::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(object, states);
	}

	Mouse::Mouse(Mouse::TYPE type)
	{
		// to do
	}
}
