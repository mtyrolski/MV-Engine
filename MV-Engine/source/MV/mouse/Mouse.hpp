#pragma once

#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderStates.hpp"
#include "SFML/Window/Mouse.hpp"

#include "MV/scene/Scene.hpp"

namespace mv
{
	class Mouse : public sf::Drawable
	{
		/* ===Objects=== */
	public:
		enum class TYPE
		{
			DEFAULT = 0
		};
	protected:
	private:
		sf::Sprite object;

		//to checking border
		sf::Vector2u tolerance;
		/* ===Methods=== */
	public:
		Mouse(const Mouse::TYPE& type = Mouse::TYPE::DEFAULT);

		void changeType(const Mouse::TYPE& type);

		void tick();
	protected:
	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		void positionUpdate();
		void checkBorders();
	};
}
