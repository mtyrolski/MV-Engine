#include "InputManager.hpp"

namespace mv
{
	void InputManager::control()
	{
		for (auto&var : keyData)
			if (sf::Keyboard::isKeyPressed(var.first))
				var.second();
	}

	bool InputManager::addKeyToCheck(sf::Keyboard::Key key, void(*function)())
	{
		keyData.emplace(key, function);

		return true;
	}
	bool InputManager::eraseKey(sf::Keyboard::Key key)
	{
		keyData.erase(key);
		return false;
	}
}
