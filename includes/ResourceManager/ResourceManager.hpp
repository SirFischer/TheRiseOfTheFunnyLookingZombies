#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <list>
#include <map>
#include <memory>
#include <iostream>

class ResourceManager
{
private:
	ResourceManager(/* args */);
	~ResourceManager();

	static std::map<std::string, std::shared_ptr<void>>	mResources;

public:

	static sf::Font			*LoadFont(std::string tPath);
	static sf::Texture		*LoadTexture(std::string tPath);
	static sf::Music		*LoadMusic(std::string tPath);
	static sf::SoundBuffer	*LoadSoundBuffer(std::string tPath);
	static sf::Shader		*LoadShader(std::string tPath);

};

