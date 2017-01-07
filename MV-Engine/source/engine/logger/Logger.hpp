#pragma once

#include <string>
#include "engine/config/Config.hpp"
#include "fstream";

namespace mv
{
	class Logger
	{
	public:

		static enum STREAM
		{
			CONSOLE = 0,
			FILE = 1,
			BOTH = 2
		};

		static enum TYPE
		{
			INFO = 0,
			SUGGESTION = 1,
			WARNING = 2,
			ERROR = 3
		};

		static void Log(std::string = "no data", Logger::STREAM = Logger::STREAM::CONSOLE, Logger::TYPE = Logger::TYPE::ERROR);
	
	private:

		static std::string prefix;

		static void sendMessage(std::string message, Logger::STREAM stream);

		static void consoleMessage(std::string message);

		static void fileMessage(std::string message);

		static void setPrefix(Logger::TYPE type);
	};
}
