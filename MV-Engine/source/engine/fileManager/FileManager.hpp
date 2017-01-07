#pragma once

#include <fstream>

namespace mv
{
	class FileManager
	{
	public:

		static enum MODE
		{
			OVERWRITE = 0,
			APPEND = 1
		};


		static void output(std::string message, std::string path, FileManager::MODE mode);		
	
		};
}