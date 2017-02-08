#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

namespace mv
{
	namespace constants
	{
		namespace loader
		{
			constexpr auto DATA_PATH = "source/engine/loader/options.txt";
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
				constexpr auto NUMBER_HAS_NOT_FOUND = "State with given number doesn't exist";
				constexpr auto STATE_DOES_NOT_EXIST = "State with given name doesn't exist";
			}

			namespace scene
			{
				constexpr auto T_DOES_NOT_INHERT_FROM_DRAWABLE = "T doesn't inhert from sf::Drawable. It cannont be drawn by this method";
			}

			namespace mapManager
			{
				constexpr auto NEGATIVE_VALUES = "You need to enter a positive values. Dimensions of map/cell cannot be < 0!";
				constexpr auto NOT_INITED = "You need to init MapManager by 'init'";
			}
		}

		namespace defaults
		{
			constexpr auto UNNAMED = "unnamed";
			const sf::Vector2f WINDOW_DIMENSIONS = { 600,600 };
			const auto defaultState = std::make_pair<std::string, int8_t>("default", 1);
		}

	}
}