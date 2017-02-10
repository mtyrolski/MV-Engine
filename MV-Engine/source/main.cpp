#include "engine/initializator/Initializator.hpp"
#include "engine/scene/Scene.hpp"
#include "engine/loader/Loader.hpp"
#include "EventControl.hpp"
#include <SFML/Window/Event.hpp>
#include "engine/resourceCache/Cache.hpp"
#include "engine/mapManager/MapManager.hpp"
#include "engine/cell/Cell.hpp"

#include <vector>

int main()
{
	mv::Scene* scene;
	mv::MapManager* mapManager;

	{
		mv::Initializator initializator;
		initializator.init();

		mv::Loader loader;
		loader.loadData();

		scene = new mv::Scene(loader.title, sf::Vector2f(loader.ammount.x*loader.cellDimensions.x, loader.ammount.y*loader.cellDimensions.y));
		mapManager = new mv::MapManager(loader.ammount, loader.cellDimensions);
	}

	mv::EventControl eventControl(scene);
	mapManager->constructWholeWorld(mv::constants::defaults::EMPTY);


	//main game loop
	while (scene->isOpen())
	{
		sf::Event event;
		scene->drawCollection<mv::Cell>(mapManager->getCellStorage());
		eventControl.checkEvent(event);
	}


	return 0;
}
	
