#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

#include "engine/config/Config.hpp"

namespace mv
{
	class Scene
	{	
		void display();

		void clear();

	public:
		//Constructor which creates a window
		Scene(std::string title = constants::defaults::UNNAMED, sf::Vector2f dimensions = constants::defaults::WINDOW_DIMENSIONS);

		~Scene();
		
		void refresh();

		bool isOpen();

		sf::RenderWindow *GetPointerToWindow();

		void close();

		void viewUpdate(sf::View *view);

	private:

		sf::RenderWindow *window;
	};
}