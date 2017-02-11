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
		StateSystem::readStatesFromFile(constants::stateSystem::STATES_PATH);
	}
}


