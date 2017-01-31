#pragma once

#include <vector>
#include <map>
namespace mv
{
	class Cache
	{
	public:
		Cache();

		void get(std::string name);

	private:

		template <class T>
		std::vector<std::map<int,T>> resources;
		/*map<ID,class>*/
	};
}
