#pragma once

#include <fstream>

namespace mv
{
	class FileManager
	{
		/* ===Objects=== */
	public:
		enum class MODE
		{
			OVERWRITE,
			APPEND
		};
	protected:
	private:

		/* ===Methods=== */
	public:
		static void output(char* message, std::string& path, FileManager::MODE mode);
	protected:
	private:
	};
}