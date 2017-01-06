#include "Logger.hpp"

namespace mv
{
	void Logger::Log(std::string message, Logger::STREAM stream, Logger::TYPE type)
	{
		setPrefix(type);
		sendMessage(message, stream);
	}

	void Logger::setPrefix(Logger::TYPE type)
	{
		switch (type)
		{

			case Logger::TYPE::ERROR:
			{
				break;
			}

				
			case Logger::TYPE::INFO:
			{
				break;
			}
			
			case Logger::TYPE::SUGGESTION:
			{
				break;
			}
			
			case Logger::TYPE::WARNING:
			{
				break;
			}
		}
	}
}

