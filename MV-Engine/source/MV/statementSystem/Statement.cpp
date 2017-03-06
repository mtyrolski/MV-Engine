#include "Statement.hpp"

namespace mv
{
	Statement::Statement(const std::string & _text, float _time)
		:liveTime(_time)
	{
		text.setString(_text);
		createdTime = clock();
	}

	bool Statement::isActive()
	{
		return (clock()-createdTime)/CLOCKS_PER_SEC < liveTime;
	}

	void Statement::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(text, states);
	}
}