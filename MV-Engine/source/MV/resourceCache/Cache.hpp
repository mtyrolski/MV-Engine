#pragma once

#include <vector>
#include <map>
#include <SFML/Graphics/Texture.hpp>

namespace mv
{
	//?
	template < typename T = typename std::enable_if< std::is_base_of<sf::Texture,T>::value,T>::type>
	class Cache
	{
	public:
		T& get(std::string& path);
	private:
		static std::map<std::string, T> resources;
	};
}