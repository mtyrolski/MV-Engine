#include "Loader.hpp"

namespace mv
{
	void Loader::loadData()
	{
		std::fstream file(constants::loader::DATA_PATH, std::ios::in);

		if (file.good())
		{
			file >> Loader::title;
			file >> Loader::cellDimensions.x;
			file >> Loader::cellDimensions.y;
			file >> Loader::ammount.x;
			file >> Loader::ammount.y;
			file >> Loader::moveSpeed;
		}
	}
}
