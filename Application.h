#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "AssetManager.h"

class Application
{
public:
	void run(sf::RenderWindow& window, float wWidth, float wHeight, AssetManager& assetManager);
private:
	sf::Vector2f movePlayerRight(sf::Sprite Player, std::vector<std::vector<sf::Sprite>> tiles, AssetManager assetManager, sf::RectangleShape background, int fieldSize, sf::RenderWindow& window, float dtAsSeconds);
	sf::Vector2f movePlayerLeft(sf::Sprite Player, std::vector<std::vector<sf::Sprite>> tiles, AssetManager assetManager, sf::RectangleShape background, int fieldSize, sf::RenderWindow& window, float dtAsSeconds);
	sf::Vector2f movePlayerDown(sf::Sprite Player, std::vector<std::vector<sf::Sprite>> tiles, AssetManager assetManager, sf::RectangleShape background, int fieldSize, sf::RenderWindow& window, float dtAsSeconds);
	sf::Vector2f movePlayerUp(sf::Sprite Player, std::vector<std::vector<sf::Sprite>> tiles, AssetManager assetManager, sf::RectangleShape background, int fieldSize, sf::RenderWindow& window, float dtAsSeconds);
};

