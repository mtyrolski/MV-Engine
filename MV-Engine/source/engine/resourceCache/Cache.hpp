#pragma once

#include <vector>
#include <map>
#include <SFML/Graphics/Texture.hpp>

namespace mv
{
	template<class T>
	class Cache
	{
	public:
		T& get(std::string& path);
	private:
		static std::map<std::string, T> resources;
	};

	class TextureCache :public Cache<sf::Texture>
	{
	public:
		TextureCache();
	};
}
