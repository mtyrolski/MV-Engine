#pragma once

#include <ctime>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace mv
{
	class Statement final :public sf::Drawable
	{
		/* ===Objects=== */
	public:
	protected:
	private:
		sf::Text text;
		float createdTime;
		float liveTime;
		/* ===Methods=== */
	public:
		Statement(const std::string& _text, float time);

		bool isActive();
	protected:
	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	};
}
