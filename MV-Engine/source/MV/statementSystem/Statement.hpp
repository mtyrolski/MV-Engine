#pragma once

#include <chrono>

#include <SFML/Graphics/Text.hpp>

namespace mv
{
	class Statement final :public sf::Drawable
	{
		/* ===Objects=== */
	public:
		sf::Text text;
		std::chrono::time_point<std::chrono::system_clock> createdTime;
	protected:
	private:
		/* ===Methods=== */
	public:
		Statement(const std::string& _text);
	protected:
	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	};
}
