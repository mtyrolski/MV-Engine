#include "Logger.hpp"

namespace mv
{
	std::string Logger::prefix;

	void Logger::Log(std::string message, Logger::STREAM stream, Logger::TYPE type)
	{
		setPrefix(type);
		sendMessage(message, stream);
	}

	void Logger::sendMessage(std::string message, Logger::STREAM stream)
	{
		switch (stream)
		{
			case Logger::STREAM::FILE:
			{
				fileMessage(message);
				break;
			}

			case Logger::STREAM::CONSOLE:
			{
				consoleMessage(message);
				break;
			}

			case Logger::STREAM::BOTH:
			{
				consoleMessage(message);
				fileMessage(message);
				break;
			}
		}
	}

	void Logger::consoleMessage(std::string message)
	{
		//to do
	}

	void Logger::fileMessage(std::string message)
	{
		//to do FileManager
	}

	void Logger::setPrefix(Logger::TYPE type)
	{
		switch (type)
		{

			case Logger::TYPE::ERROR:
			{
				Logger::prefix = constants::logger::PREFIX_ERROR;
				break;
			}

				
			case Logger::TYPE::INFO:
			{
				Logger::prefix = constants::logger::PREFIX_INFO;
				break;
			}
			
			case Logger::TYPE::SUGGESTION:
			{
				Logger::prefix = constants::logger::PREFIX_SUGGESTION;
				break;
			}
			
			case Logger::TYPE::WARNING:
			{
				Logger::prefix = constants::logger::PREFIX_WARNING;
				break;
			}
		}
	}
}

