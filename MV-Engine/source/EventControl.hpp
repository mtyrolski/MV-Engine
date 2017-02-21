#pragma once

#include <SFML/Window/Event.hpp>

#include "MV/scene/Scene.hpp"

/*
				===---===
	If you want to extend event control you need to modife checkControl() method:
	-Add new case like this:

	case sf::Event::MouseLeft:
	{
		do sth...
		break;
	}
			    ===---===
*/

namespace mv
{
	class EventControl
	{
		/* ===Objects=== */
	public:
	protected:
	private:
		Scene* m_scene;
		/* ===Methods=== */
	public:
		EventControl(Scene *scene);
		void checkEvent(sf::Event &event);
	protected:
	private:
	};
}
