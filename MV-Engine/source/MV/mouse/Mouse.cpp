#include "Mouse.hpp"
#include <iostream>
namespace mv
{
	void Mouse::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(object, states);
	}

	void Mouse::positionUpdate()
	{
		sf::Vector2i pixelPos = sf::Mouse::getPosition(*mv::Scene::getInstance().GetPointerToWindow());
		sf::Vector2f worldPos = mv::Scene::getInstance().GetPointerToWindow()->mapPixelToCoords(pixelPos);
		object.setPosition(worldPos);
	}

	void Mouse::checkBorders()
	{
		auto windowDimensions = mv::Scene::getInstance().GetPointerToWindow()->getSize();
		
		if (windowDimensions.y - sf::Mouse::getPosition(*mv::Scene::getInstance().GetPointerToWindow()).y < tolerance.y)
		{
			mv::Scene::getInstance().moveView(mv::Scene::DIRECTION::DOWN);
		}
		else if (sf::Mouse::getPosition(*mv::Scene::getInstance().GetPointerToWindow()).y < tolerance.y)
		{
			mv::Scene::getInstance().moveView(mv::Scene::DIRECTION::TOP);
		}

		if (windowDimensions.x - sf::Mouse::getPosition(*mv::Scene::getInstance().GetPointerToWindow()).x < tolerance.x)
		{
			mv::Scene::getInstance().moveView(mv::Scene::DIRECTION::RIGHT);
		}
			
		else if (sf::Mouse::getPosition(*mv::Scene::getInstance().GetPointerToWindow()).x < tolerance.x)
		{
			mv::Scene::getInstance().moveView(mv::Scene::DIRECTION::LEFT);
		}

	}

	Mouse::Mouse(const Mouse::TYPE& type)
		:tolerance(100, 100)
	{
		//texture to do
	}

	void Mouse::changeType(const Mouse::TYPE & type)
	{
		//to do
	}

	void Mouse::tick()
	{
		positionUpdate();
		checkBorders();
	}
}
