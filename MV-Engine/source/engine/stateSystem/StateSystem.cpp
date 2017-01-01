#include "StateSystem.hpp"

namespace mv
{
	bool StateSystem::emplace_state(std::string name, uint8_t number)
	{
		if (states.find(name) != states.end())
		{
			//INFO TO LOG (soon)
			return false;
		}
		else if (number < 0)
		{
			//INFO TO LOG (soon)
			return false;
		}

		states.emplace(name, number);
		return true;
	}

	bool StateSystem::isStateExist(std::string name)
	{
		return (states.find(name) != states.end());
	}

	uint8_t StateSystem::getNumberOfState(std::string name)
	{
		auto itr = states.find(name);

		if (itr == states.end()) return -1;
		else return itr->second;
	}

	bool StateSystem::erase_state(std::string name)
	{
		auto itr = states.find(name);
		
		if (itr == states.end()) return false;

		states.erase(itr);
		return true;
	}
}
