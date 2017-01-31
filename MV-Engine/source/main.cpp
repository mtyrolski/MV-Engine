#include "engine/initializator/Initializator.hpp"
#include "engine/scene/Scene.hpp"
#include "engine/loader/Loader.hpp"

int main()
{
	mv::Scene* scene;

	{
		mv::Initializator initializator;
		initializator.init();

		mv::Loader loader;
		loader.loadData();

		scene = new mv::Scene(loader.title, sf::Vector2f(loader.ammount.x*loader.cellDimensions.x, loader.ammount.y*loader.cellDimensions.y));
	}

	while (scene->isOpen())
	{

	}

	return 0;
}
	
