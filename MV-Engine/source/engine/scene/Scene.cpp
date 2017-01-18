#include "Scene.hpp"

namespace mv
{
	void Scene::display()
	{
		window->display();
	}

	void Scene::clear()
	{
		window->clear();
	}

	Scene::Scene(std::string title, sf::Vector2f dimensions)
	{
		window = new sf::RenderWindow(sf::VideoMode(dimensions.x, dimensions.y), title);
	}

	Scene::~Scene()
	{
		if (window != nullptr)
			delete window;
	}

	bool Scene::isOpen()
	{
		return window->isOpen();
	}

	sf::RenderWindow * Scene::GetPointerToWindow()
	{
		return window;
	}

	void Scene::close()
	{
		window->close();
	}

	void Scene::viewUpdate(sf::View * view)
	{
		//to do
	}
}
