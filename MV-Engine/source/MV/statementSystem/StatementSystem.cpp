#include "StatementSystem.hpp"

namespace mv
{

	StatementSystem* StatementSystem::instance;

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

	std::vector<Statement>& StatementSystem::getStatements()
	{
		return statements;
	}
}
