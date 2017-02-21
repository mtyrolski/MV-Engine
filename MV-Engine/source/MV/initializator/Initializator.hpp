#pragma once

#include "MV/stateSystem/StateSystem.hpp"
#include "MV/config/Config.hpp"

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
