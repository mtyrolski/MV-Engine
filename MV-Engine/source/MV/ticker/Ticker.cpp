#include "Ticker.hpp"

namespace mv
{
	 std::vector<Ticker*> Ticker::objects;

	Ticker::Ticker(Ticker * pointer)
	{
		objects.push_back(pointer);
	}

	void Ticker::tickLoop()
	{
		for (auto&var : objects)
		{
			var->tick();
		}
	}

	void Ticker::removePointer(Ticker * ptr)
	{
		for (auto itr = objects.begin(); itr != objects.end(); ++itr)
		{
			if (*itr = ptr)
			{
				delete *itr;
				break;
			}
		}
	}
}
