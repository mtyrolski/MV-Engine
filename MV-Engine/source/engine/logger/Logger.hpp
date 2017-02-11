#pragma once

#include <string>
#include "engine/config/Config.hpp"
#include <fstream>
#include <iostream>
#include <chrono>
#include <ctime>

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

		static void sendMessage(std::string message, Logger::STREAM stream, std::string &prefix);

		static void consoleMessage(std::string message, std::string &prefix, std::time_t& time);

		static void fileMessage(std::string message, std::string &prefix, std::time_t& time);

		static void setPrefix(Logger::TYPE type,std::string &prefix);
	};
}
