#pragma once

#include <chrono>

#include <SFML/Graphics/Font.hpp>

#include "MV/logger/Logger.hpp"
#include "MV/statementSystem/Statement.hpp"

namespace mv
{
	class StatementSystem final
	{
		/* ===Objects=== */
	public:
	protected:
	private:
		static StatementSystem *instance;

		sf::Font font;
		std::vector<Statement> statements;

		/* ===Methods=== */
	public:
		static void createInstance();
		static StatementSystem& getInstance();

		std::vector<Statement>& getStatements();
	protected:
	private:
		StatementSystem() = default;
		StatementSystem(StatementSystem const& copy) = delete;            // Not Implemented
		StatementSystem& operator=(StatementSystem const& copy) = delete; // Not Implemented
	};
}