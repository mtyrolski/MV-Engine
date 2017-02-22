#include "Mouse.hpp"

namespace mv
{
	void Mouse::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(object, states);
	}

	Mouse::Mouse(const Mouse::TYPE& type)
	{
		// to do
	}
}
