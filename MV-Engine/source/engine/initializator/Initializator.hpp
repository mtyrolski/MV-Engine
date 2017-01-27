#pragma once

#include "engine/stateSystem/StateSystem.hpp"
#include "engine/config/Config.hpp"

namespace mv
{
	class Initializator
	{
	public:

		Initializator();

		~Initializator();

		//Inits the program
		void init();
	};
}
