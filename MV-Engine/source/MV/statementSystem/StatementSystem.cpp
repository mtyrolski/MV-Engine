#include "StatementSystem.hpp"

namespace mv
{

	StatementSystem* StatementSystem::instance;

	void StatementSystem::createInstance()
	{
		if (instance == 0)
		{
			instance = new StatementSystem();
			instance->font.loadFromFile("data/font/arial.ttf");
		}
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

	void StatementSystem::control()
	{
		for (auto itr = statements.begin(); itr != statements.end();)
		{
			if (!itr->isActive())
				itr = statements.erase(itr);
			else
				++itr;
		}
	}

	void StatementSystem::addStatement(const std::string & _text, float time)
	{
		statements.emplace_back(_text, time,font,statements);
	}
}
