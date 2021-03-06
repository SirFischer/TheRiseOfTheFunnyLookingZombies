#include "ResourceManager.hpp"

std::map<std::string, std::shared_ptr<void>>	ResourceManager::mResources = std::map<std::string, std::shared_ptr<void>>();

ResourceManager::ResourceManager(/* args */)
{

}

ResourceManager::~ResourceManager()
{

}

/**
 * To be extended to sf::texture, sf::audio, sf::image etc...
 **/

sf::Font		*ResourceManager::LoadFont(std::string tPath)
{
	sf::Font	*font = NULL;

	if (mResources.count(tPath))
		return (sf::Font *)(mResources[tPath].get());
	try
	{
		font = new sf::Font();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Failed to load font: " << tPath << std::endl;
		std::cerr << e.what() << '\n';
		return (NULL);
	}
	font->loadFromFile(tPath);
	mResources[tPath] = std::shared_ptr<void>(font);
	return (font);
}

sf::Texture		*ResourceManager::LoadTexture(std::string tPath)
{
	sf::Texture	*tex = NULL;

	if (mResources.count(tPath))
		return (sf::Texture *)(mResources[tPath].get());
	try
	{
		tex = new sf::Texture();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Failed to load font: " << tPath << std::endl;
		std::cerr << e.what() << '\n';
		return (NULL);
	}
	tex->loadFromFile(tPath);
	mResources[tPath] = std::shared_ptr<void>(tex);
	return (tex);
}

sf::Music	*ResourceManager::LoadMusic(std::string tPath)
{
	sf::Music	*music = NULL;

	if (mResources.count(tPath))
		return (sf::Music *)(mResources[tPath].get());
	try
	{
		music = new sf::Music();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Failed to load font: " << tPath << std::endl;
		std::cerr << e.what() << '\n';
		return (NULL);
	}
	music->openFromFile(tPath);
	mResources[tPath] = std::shared_ptr<void>(music);
	return (music);
}

sf::SoundBuffer	*ResourceManager::LoadSoundBuffer(std::string tPath)
{
	sf::SoundBuffer	*music = NULL;

	if (mResources.count(tPath))
		return (sf::SoundBuffer *)(mResources[tPath].get());
	try
	{
		music = new sf::SoundBuffer();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Failed to load font: " << tPath << std::endl;
		std::cerr << e.what() << '\n';
		return (NULL);
	}
	music->loadFromFile(tPath);
	mResources[tPath] = std::shared_ptr<void>(music);
	return (music);
}

sf::Shader		*ResourceManager::LoadShader(std::string tPath)
{
	sf::Shader	*shader = NULL;

	if (mResources.count(tPath))
		return (sf::Shader	*)(mResources[tPath].get());
	try
	{
		shader = new sf::Shader();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Failed to load font: " << tPath << std::endl;
		std::cerr << e.what() << '\n';
		return (NULL);
	}
	shader->loadFromFile(tPath, sf::Shader::Fragment);
	mResources[tPath] = std::shared_ptr<void>(shader);
	return (shader);
}