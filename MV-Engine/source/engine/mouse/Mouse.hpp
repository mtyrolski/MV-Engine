#pragma once

#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderStates.hpp"

namespace mv
{
	class Mouse : public sf::Drawable
	{
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	public:

		static enum TYPE
		{
			DEFAULT = 0
		};

		Mouse(Mouse::TYPE type = Mouse::TYPE::DEFAULT);

	private:
		sf::Sprite object;
	};
}
