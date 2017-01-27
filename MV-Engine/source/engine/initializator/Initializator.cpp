#include "Initializator.hpp"


namespace mv
{
	Initializator::Initializator()
	{
	}

	Initializator::~Initializator()
	{
	}

	void Initializator::init()
	{
		StateSystem::emplaceState(constants::defaults::defaultState.first, constants::defaults::defaultState.second);
	}
}


