#pragma once

#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderStates.hpp"

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

		/* ===Methods=== */
	public:
		Mouse(const Mouse::TYPE& type = Mouse::TYPE::DEFAULT);
	protected:
	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	};
}
