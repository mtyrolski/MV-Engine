#pragma once

#include <SFML/Graphics/Color.hpp>

namespace mv
{
	namespace constants
	{
		namespace loader
		{
			constexpr auto DATA_PATH = "options.txt";
		}

		namespace cell
		{
			const sf::Color FILL_COLOR(120, 133, 139); //Squirrel grey
		}

		namespace logger
		{
			constexpr auto PREFIX_INFO = "[INFO]";
			constexpr auto PREFIX_SUGGESTION = "[SUGGESTION]";
			constexpr auto PREFIX_WARNING = "[WARNING]";
			constexpr auto PREFIX_ERROR = "[ERROR]";
		}

		namespace fileManager
		{
			constexpr auto PATH_LOG = "engine/log/log.txt";
		}
		
		namespace error
		{
			namespace stateSystem
			{
				constexpr int8_t ERROR_VALUE = -1;
				constexpr auto STATE_HAS_FOUND = "State with name already exists";
				constexpr auto MINUS_NUMBER = "State with given number cannot be created (number<0)";
			}
		}

		namespace defaults
		{
			constexpr auto UNNAMED = "unnamed";
			const sf::Vector2f WINDOW_DIMENSIONS = { 600,600 };
		}

	}
}