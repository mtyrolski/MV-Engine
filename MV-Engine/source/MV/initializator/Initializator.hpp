#pragma once

#include "MV/stateSystem/StateSystem.hpp"
#include "MV/config/Config.hpp"

namespace mv
{
	class Initializator
	{
		/* ===Objects=== */
	public:
	protected:
	private:
		static Initializator *instance;
		/* ===Methods=== */
	public:
		//Inits the program
		void init();

		static Initializator& getInstance();
		static void createInstance();
	protected:
	private:
		Initializator() = default;
		Initializator(Initializator const& copy) = delete;            // Not Implemented
		Initializator& operator=(Initializator const& copy) = delete; // Not Implemented
	};
}
