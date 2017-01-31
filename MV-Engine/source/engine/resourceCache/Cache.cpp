#include "Cache.hpp"

namespace mv
{
	TextureCache::TextureCache()
	{
	}

	template<class T>
	T& Cache<T>::get(std::string& path)
	{
		if (path.empty())
		{
			throw invalid_argument("Cache can't find resource in empty path.");
		}

		{//Try find resource
			auto result = resources.find(path);

			if (result != resources.end())
				return &result;	
		}

		{//Try to load it
			T resource;

			if (!resource.loadFromFile(path))
			{
				throw invalid_argument("Cache can't find resource in this path.");
			}

			resoruces.emplace_back(path,resource);

			return &resources[path];
		}
	}
}
