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

	template<class T>
	bool Scene::drawCollection(std::vector<T>* collection)
	{
		if (!std::is_base_of(T, sf::Drawable))
		{
			Logger::Log(constants::error::scene::T_DOES_NOT_INHERT_FROM_DRAWABLE, Logger::STREAM::BOTH, Logger::TYPE::WARNING);
			return false;
		}

		for (auto&var : collection)
			var.draw();
		
		return true;
	}
}
