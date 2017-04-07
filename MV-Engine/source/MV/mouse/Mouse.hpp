#pragma once

#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderStates.hpp"
#include "SFML/Window/Mouse.hpp"

#include "MV/scene/Scene.hpp"
#include "MV//ticker/Ticker.hpp"
#include "MV/resourceCache/Cache.hpp"

namespace mv
{
	class Mouse : public sf::Drawable, public Ticker
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
 
		bool movingPermission;
		mv::Cache<sf::Texture> cache;
		/* ===Methods=== */
	public:
		Mouse(const Mouse::TYPE& type = Mouse::TYPE::DEFAULT, bool movingBorderPermission = false);
		~Mouse();

		void changeType(const Mouse::TYPE& type);

		void setBorderMovingMode(bool mode);

		void setTolerance(sf::Vector2u value);
		void setTolerance(unsigned long value_x, unsigned long value_y);

		void tick() override;

	protected:
	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		void positionUpdate();
		void checkBorders();
	};
}
