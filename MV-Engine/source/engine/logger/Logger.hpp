#pragma once

#include <string>

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

		std::string prefix;

		static void sendMessage(std::string message, Logger::STREAM stream);

		static void setPrefix(Logger::TYPE type);
	};
}
