#include "Scene.hpp"

namespace mv
{
	Scene* Scene::instance;

	void Scene::display()
	{
		window->display();
	}

	Scene & Scene::getInstance()
	{
		if (instance == 0)
			Logger::Log(constants::error::singleton::SINGLETON_NOT_INITED, Logger::STREAM::BOTH, Logger::TYPE::ERROR);
		return *instance;
	}

	void Scene::createInstance(const std::string& title, const sf::Vector2f& dimensions)
	{
		if (instance == 0)
			instance = new Scene(title,dimensions);
	}


	void Scene::clear()
	{
		window->clear();
	}

	Scene::Scene(const std::string& title, const sf::Vector2f& dimensions)
	{
		window = new sf::RenderWindow(sf::VideoMode(dimensions.x, dimensions.y), title);
	}

	Scene::~Scene()
	{
		if (window != nullptr)
			delete window;
	}

	bool Scene::isOpen() const
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
