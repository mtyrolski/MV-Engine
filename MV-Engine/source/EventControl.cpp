#include "EventControl.hpp"

namespace mv
{
	EventControl::EventControl(Scene * scene)
		:m_scene(scene)
	{	
	}

	void EventControl::checkEvent(sf::Event & event)
	{
		while(m_scene->GetPointerToWindow()->pollEvent(event))
		{
			switch (event.type)
			{	
				case sf::Event::Closed:
				{
					m_scene->close();
					break;
				}
			
				/*there you can add new case*/
			}
		}
	}
}

