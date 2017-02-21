#include "Logger.hpp"

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

namespace mv
{
	void Logger::Log(std::string message, Logger::STREAM stream, Logger::TYPE type)
	{
		std::string prefix;
		setPrefix(type,prefix);
		sendMessage(message, stream,prefix);
	}

	void Logger::sendMessage(std::string message, Logger::STREAM stream, std::string &prefix)
	{
		std::chrono::time_point<std::chrono::system_clock> date = std::chrono::system_clock::now();
		std::time_t time = std::chrono::system_clock::to_time_t(date);

		switch (stream)
		{
			case Logger::STREAM::FILE:
			{
				fileMessage(message,prefix,time);
				break;
			}

			case Logger::STREAM::CONSOLE:
			{
				consoleMessage(message,prefix, time);
				break;
			}

			case Logger::STREAM::BOTH:
			{
				consoleMessage(message,prefix, time);
				fileMessage(message,prefix, time);
				break;
			}
		}
	}

	void Logger::consoleMessage(std::string message, std::string &prefix, std::time_t& time)
	{
		std::cout << std::ctime(&time);
		std::cout << prefix << ' ';
		std::cout << message << "\n\n";
	}

	void Logger::fileMessage(std::string message, std::string &prefix, std::time_t& time)
	{
		std::ofstream file(constants::fileManager::PATH_LOG);

		file << std::ctime(&time);
		file << prefix << ' ';
		file << message << "\n\n";
	}

	void Logger::setPrefix(Logger::TYPE type, std::string &prefix)
	{
		switch (type)
		{

			case Logger::TYPE::ERROR:
			{
				prefix = constants::logger::PREFIX_ERROR;
				break;
			}

				
			case Logger::TYPE::INFO:
			{
				prefix = constants::logger::PREFIX_INFO;
				break;
			}
			
			case Logger::TYPE::SUGGESTION:
			{
				prefix = constants::logger::PREFIX_SUGGESTION;
				break;
			}
			
			case Logger::TYPE::WARNING:
			{
				prefix = constants::logger::PREFIX_WARNING;
				break;
			}
		}
	}
}

