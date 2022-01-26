#include <iostream>

class RenderCycle
{
public:
	static void render(sf::RenderWindow& window, std::vector<std::vector<sf::Sprite>> drawables, sf::RectangleShape background, sf::Sprite player) {
		window.clear(sf::Color::White);
		window.draw(background);

		for (size_t i = 0; i < drawables.size(); i++) 
			for (int j = 0; j < drawables.at(i).size(); j++)
			window.draw(drawables.at(i).at(j));
		window.draw(player);
		//Flipping the Buffers
		window.display();
		std::cout << "Render!/n";
	}
};
