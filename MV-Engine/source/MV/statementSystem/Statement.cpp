#include "Statement.hpp"

namespace mv
{
	Statement::Statement(const std::string & _text)
	{
		text.setString(_text);
		createdTime = std::chrono::system_clock::now();
	}

	void Statement::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(text, states);
	}
}