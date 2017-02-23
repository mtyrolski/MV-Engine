#include "Initializator.hpp"


namespace mv
{
	Initializator* Initializator::instance;
	void Initializator::init()
	{
		StateSystem::readStatesFromFile("data/states/states.txt");
	}

	Initializator & Initializator::getInstance()
	{
		if (instance == 0)
			Logger::Log(constants::error::singleton::SINGLETON_NOT_INITED, Logger::STREAM::BOTH, Logger::TYPE::ERROR);
		return *instance;
	}

	void Initializator::createInstance()
	{
		if (instance == 0)
			instance = new Initializator();
	}

}


