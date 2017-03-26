#pragma once

#include <map>
#include <vector>

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include "MV/config/Config.hpp"
#include "MV/logger/Logger.hpp"

namespace mv
{
	//SoundObject class
	//It is designed to administer short sounds
	class SoundObject
	{
	public:
	protected:
	private:

		std::map<std::string, int8_t> sounds;

		std::vector<std::pair<sf::Sound, sf::SoundBuffer>> soundSource;

		/* ===Methods=== */

	public:

		//Emplaces new sound
		//returns false if sound with given name exist 
		//or sound isn't in source folder
		//returns true if sound has been added
		bool EmplaceSound( std::string & name );

		bool EmplaceSound(std::string && name)
		{
			return EmplaceSound(name);
		}

		//Returns false if sound with given name doesn't exist
		//returns true if sound with given name exist
		bool IsSoundExist( std::string & name )
		{
			return ( sounds.find( name ) != sounds.end() );
		}

		bool IsSoundExist(std::string && name)
		{
			IsSoundExist(name);
		}

		//Returns number of sound with given name
		//returns -1 value if sound doesn't exist
		int8_t GetNumberOfSound( std::string & name );

		int8_t GetNumberOfSound(std::string && name)
		{
			return GetNumberOfSound(name);
		}

		//Erase sound with given name
		//returns false if sound doesn't exist
		//returns true if sound has been removed
		bool EraseSound( std::string & name );

		bool EraseSound(std::string && name)
		{
			return EraseSound(name);
		}

		//Plays sound with given name
		//returns false if sound doesn't exist
		//returns true if sound is being played succesfully
		bool PlaySound( std::string & name );

		bool PlaySound(std::string && name)
		{
			return PlaySound(name);
		}

	protected:
	private:
		void playOnce(std::string & name);
	};
}