#include "FileManager.hpp"

namespace mv
{
	void FileManager::output(std::string message, std::string path, FileManager::MODE mode)
	{
		std::ofstream out;

		switch(mode)
		{
			case FileManager::MODE::OVERWRITE:
			{
				out.open(path, std::ofstream::out | std::ofstream::trunc);
				break;
			}

			case FileManager::MODE::APPEND:
			{
				out.open(path, std::ofstream::out);
				break;
			}
		}
		
		out << message << std::endl;

		out.close();
	}
}
