#pragma once

#include <SFML/Window/Event.hpp>
#include "engine/scene/Scene.hpp"

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

	public:

		EventControl(Scene *scene);
		void checkEvent(sf::Event &event);

	private:

		Scene* m_scene;
	};
}
