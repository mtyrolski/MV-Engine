#pragma once

#include <chrono>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include "MV/logger/Logger.hpp"

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

		struct statement
		{
		public:
			sf::Text text;
			std::chrono::time_point<std::chrono::system_clock> createdTime;

			statement(const std::string& _text)
			{
				text.setString(_text);
				createdTime = std::chrono::system_clock::now();
			}
		};

		std::vector<statement> statements;

		/* ===Methods=== */
	public:
		static void createInstance();
		static StatementSystem& getInstance();
	protected:
	private:
		StatementSystem();
		StatementSystem(StatementSystem const& copy) = delete;            // Not Implemented
		StatementSystem& operator=(StatementSystem const& copy) = delete; // Not Implemented
	};
}