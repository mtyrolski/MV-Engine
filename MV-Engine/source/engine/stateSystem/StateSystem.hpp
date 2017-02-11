#pragma once

#include "engine/config/Config.hpp"
#include "engine/logger/Logger.hpp"
#include <SFML/Graphics/Color.hpp>

#include <map>
namespace mv
{
	class StateSystem
	{
	public:
		//Emplaces new state into state map
		//returns false if state with given name/number exist or number<0 or color is not correct
		//returns true if state has been added
		static bool emplaceState(std::string name, int8_t number, sf::Color color);

		//Reads all states 
		//returns false if path is not correct
		//returns true if states have been readed correctly
		static bool readStatesFromFile(std::string path);

		//Returns false if state with given name doesn't exist
		//returns true if state with given name exist
		static bool isStateExist(std::string name);

		//Returns false if state with given number doesn't exist
		//returns true if state with given number exist
		static bool isStateExist(uint8_t number);

		//Returns number of state with given name
		//returns -1 value if state doesn't exist
		static int8_t getNumberOfState(std::string name);

		//Erase state with given name
		//returns false if state doesn't exist
		//returns true if state has been removed
		static bool eraseState(std::string name);

		//Returns ammount of states
		static int8_t getAmmountStates();

	private:
		static std::map<std::string, std::pair<int8_t,sf::Color>> states;
	};
}
