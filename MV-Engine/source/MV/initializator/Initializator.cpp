#include "Initializator.hpp"


namespace mv
{
	void Initializator::init()
	{
		StateSystem::readStatesFromFile(constants::stateSystem::STATES_PATH);
	}
}


