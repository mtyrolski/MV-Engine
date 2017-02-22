#include "Initializator.hpp"


namespace mv
{
	void Initializator::init()
	{
		StateSystem::readStatesFromFile("data/states/states.txt");
	}
}


