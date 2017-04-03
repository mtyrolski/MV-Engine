#pragma once

#include <map>

#include <SFML/Window/Keyboard.hpp>


namespace mv
{
	class InputManager
	{
		/* ===Objects=== */
	public:
	protected:
	private:
		std::map < sf::Keyboard::Key, void(*)() > keyData;
		/* ===Methods=== */
	public:
		void control();

		bool addKeyToCheck(sf::Keyboard::Key key, void(*function)());

		bool eraseKey(sf::Keyboard::Key key);
	protected:
	private:
	};
}

/*=================
Example of use:
void a()
{
std::cout << "a";
}

inputManager.addKeyToCheck(sf::Keyboard::A, a);

while(true)
	inputManager.control();
*/