#include "StateSystem.hpp"

namespace mv
{
	bool StateSystem::emplaceState(std::string name, int8_t number)
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

	int8_t StateSystem::getNumberOfState(std::string name)
	{
		auto itr = states.find(name);

		if (itr == states.end()) return constants::error::stateSystem::ERROR_VALUE;
		else return itr->second;
	}

	bool StateSystem::eraseState(std::string name)
	{
		auto itr = states.find(name);
		
		if (itr == states.end()) return false;

		states.erase(itr);
		return true;
	}

	int8_t StateSystem::getAmmountStates()
	{
		return states.size();
	}
}
