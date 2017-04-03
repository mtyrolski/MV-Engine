#include "SoundObject.hpp"

namespace mv
{
	bool SoundObject::EmplaceSound( std::string & name )
	{
		if ( sounds.find( name ) != sounds.end() )
		{
			Logger::Log( constants::error::soundObject::ALREADY_EXIST, Logger::STREAM::CONSOLE, Logger::TYPE::WARNING);
			return false;
		}

		sf::SoundBuffer soundBuffer;
		if ( !soundBuffer.loadFromFile( "data/sounds/" + name ) )
		{
			return false;
		}

		sf::Sound sound;
		sound.setBuffer( soundBuffer );

		soundSource.push_back( std::pair<sf::Sound, sf::SoundBuffer>( sound, soundBuffer ) );

		sounds.emplace( name, sounds.size() );

		return true;
	}

	int8_t SoundObject::GetNumberOfSound( std::string & name )
	{
		auto itr = sounds.find( name );

		if ( itr == sounds.end() )
		{
			Logger::Log( constants::error::soundObject::DOES_NOT_EXIST_IN_SYSTEM, Logger::STREAM::CONSOLE, Logger::TYPE::WARNING);
			return -1;
		} else return itr->second;
	}

	bool SoundObject::EraseSound( std::string & name )
	{
		auto soundIterator = sounds.find( name );

		if ( soundIterator == sounds.end() )
		{
			Logger::Log(constants::error::soundObject::DOES_NOT_EXIST_IN_SYSTEM, Logger::STREAM::CONSOLE, Logger::TYPE::WARNING);
			return false;
		}

		int8_t number = soundIterator->second;

		auto soundSourceIterator = soundSource.begin() + soundIterator->second;

		sounds.erase( soundIterator );

		soundSource.erase( soundSourceIterator );

		return true;
	}

	bool SoundObject::PlaySound( std::string & name )
	{
		if (!IsSoundExist(name))
		{
			Logger::Log(constants::error::soundObject::DOES_NOT_EXIST_IN_SYSTEM, Logger::STREAM::CONSOLE, Logger::TYPE::WARNING);
			return false;
		}
	
		soundSource[sounds[name]].first.play();

		while (soundSource[sounds[name]].first.getStatus() == sf::Sound::Playing)
		{
		}

		return true;
	}
}

