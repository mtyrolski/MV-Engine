#include "engine/initializator/Initializator.hpp"

int main()
{
	mv::Initializator* initializator = new mv::Initializator();
	initializator->init();
	delete initializator;

	return 0;
}