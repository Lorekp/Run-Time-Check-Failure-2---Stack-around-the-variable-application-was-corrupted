#ifndef  ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <SFML/Graphics.hpp>
#include <map>

class AssetManager
{
public:
	AssetManager();

	//static sf::Texture& GetTexture(std::string const& filename);

	static sf::Texture& GetTexture(std::string const& filename)
	{
		auto& texMap = sInstance->m_Textures;

		//See if texture is already loaded
		auto pairFound = texMap.find(filename);
		//If yes, return the texture
		if (pairFound != texMap.end())
		{
			return pairFound->second;
		}
		else //load the texture and return it
		{
			//create element in the texture map
			auto& texture = texMap[filename];
			texture.loadFromFile(filename);
			return texture;
		}
	}

private:
	std::map<std::string, sf::Texture> m_Textures;

	static AssetManager* sInstance;
};

#endif // ! ASSET_MANAGERH
