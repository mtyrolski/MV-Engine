#pragma once

#include <vector>

#include <SFML/Window/Event.hpp>

#include "MV/resourceCache/Cache.hpp"
#include "MV/mapManager/MapManager.hpp"
#include "MV/cell/Cell.hpp"
#include "MV/initializator/Initializator.hpp"
#include "MV/statementSystem/StatementSystem.hpp"
#include "MV/scene/Scene.hpp"
#include "MV/loader/Loader.hpp"
#include "EventControl.hpp"

int main()
{
	mv::Initializator::createInstance();
	mv::Initializator::getInstance().init();

	mv::Loader::createInstance();
	mv::Loader::getInstance().loadData();

	mv::Scene::createInstance(mv::Loader::getInstance().title, sf::Vector2f(mv::Loader::getInstance().ammount.x*mv::Loader::getInstance().cellDimensions.x, mv::Loader::getInstance().ammount.y*mv::Loader::getInstance().cellDimensions.y));
		
	mv::EventControl::createInstance(&mv::Scene::getInstance());

	mv::MapManager::createInstance(mv::Loader::getInstance().ammount, mv::Loader::getInstance().cellDimensions);
	mv::MapManager::getInstance().constructWholeWorld(mv::constants::defaults::EMPTY);

	mv::StatementSystem::createInstance();

	//main game loop
	while (mv::Scene::getInstance().isOpen())
	{
		sf::Event event;

		mv::Scene::getInstance().clear();
		mv::MapManager::getInstance().updateCells();
		mv::Scene::getInstance().drawCollection<mv::Cell>(mv::MapManager::getInstance().getCellStorage());
		mv::Scene::getInstance().drawCollection<mv::Statement>(&mv::StatementSystem::getInstance().getStatements());
		mv::Scene::getInstance().display();

		mv::EventControl::getInstance().checkEvent(event);
	}


	return 0;
}
	
