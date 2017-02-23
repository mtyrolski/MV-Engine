#include "StatementSystem.hpp"

namespace mv
{
	void StatementSystem::createInstance()
	{
		if (instance == 0)
			instance = new StatementSystem();
	}
	StatementSystem & StatementSystem::getInstance()
	{
		if (instance == 0)
			Logger::Log(constants::error::singleton::SINGLETON_NOT_INITED, Logger::STREAM::BOTH, Logger::TYPE::ERROR);
		return *instance;
	}

}
