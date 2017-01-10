#pragma once

#include <map>
#include "engine/config/Config.hpp"

namespace mv
{
	class StateSystem
	{
	public:
		//Emplaces new state into state map
		//returns false if state with given name exist or number<0
		//returns true if state has been added
		static bool emplaceState(std::string name, int8_t number);

		//Returns false if state with given name doesn't exist
		//returns true if state with given name exist
		static bool isStateExist(std::string name);

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
		static std::map<std::string, int8_t> states;
	};
}
