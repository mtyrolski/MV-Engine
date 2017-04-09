#pragma once

#include <vector>
#include <map>

#include <SFML/Graphics/Texture.hpp>

namespace mv
{
	template < typename T = typename std::enable_if< std::is_base_of<sf::Texture,T>::value,T>::type>
	class Cache
	{
		/* ===Objects=== */
	public:
	protected:
	private:
		std::map<std::string, T> resources;
		/* ===Methods=== */
	public:
		T& get(const std::string& path);
	protected:
	private:
	};

	template<typename T>
	inline T & Cache<T>::get(const std::string & path)
	{

		if (path.empty())
		{
			Logger::Log("Cache can't find resource in empty path.", Logger::STREAM::BOTH, Logger::TYPE::WARNING);
		}

		{//Try find resource
			auto result = resources.find(path);
			if (result != resources.end())
				return (T&)result->second;
		}

		{//Try to load it
			T resource;

			if (!resource.loadFromFile(path))
			{
				Logger::Log("Cache can't find resource in this path.", Logger::STREAM::BOTH, Logger::TYPE::WARNING);
			}

			resources.emplace(path, resource);

			return (T&)resources[path];
		}
	}

	template<typename T>
	inline T & Cache<T>::get(std::string && path)
	{
		return get(path);
	}

}