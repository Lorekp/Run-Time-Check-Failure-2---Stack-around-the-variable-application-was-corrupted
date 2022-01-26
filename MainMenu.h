#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#define Max_main_menu 4
class MainMenu {
public:
	MainMenu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	void MouseMoved(sf::Vector2f mousePos);

	int MainMenuPressed() {
		return MainMenuSelected;
	}
private:
	int MainMenuSelected;
	sf::Font font;
	sf::Text mainMenu[Max_main_menu];

};