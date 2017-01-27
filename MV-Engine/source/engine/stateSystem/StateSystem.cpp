#include "StateSystem.hpp"

namespace mv
{
	std::map<std::string, int8_t> StateSystem::states;
	bool StateSystem::emplaceState(std::string name, int8_t number)
	{
		if (states.find(name) != states.end())
		{
			Logger::Log(constants::error::stateSystem::STATE_HAS_FOUND, Logger::STREAM::CONSOLE, Logger::TYPE::WARNING);
			return false;
		}
		else if (number < 0)
		{
			Logger::Log(constants::error::stateSystem::MINUS_NUMBER, Logger::STREAM::CONSOLE, Logger::TYPE::WARNING);
			return false;
		}

		states.emplace(name, number);
		return true;
	}

	bool StateSystem::isStateExist(std::string name)
	{
		return (states.find(name) != states.end());
	}

	bool StateSystem::isStateExist(uint8_t number)
	{
		for (auto&var : states)
		{
			if (var.second == number)
				return true;
		}

		return false;
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
