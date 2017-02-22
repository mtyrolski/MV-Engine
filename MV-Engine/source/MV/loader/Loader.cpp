#include "Loader.hpp"

namespace mv
{
	void Loader::loadData()
	{
		std::ifstream file("data/options/options.txt");

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
