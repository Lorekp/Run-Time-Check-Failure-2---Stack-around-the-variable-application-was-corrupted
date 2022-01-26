#include "MainMenu.h"

MainMenu::MainMenu() 
{
	if (!font.loadFromFile("fonts/SquaresBoldFree.otf")) 
		std::cout << "failed to load font";

	//Play
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(sf::Color::White);
	mainMenu[0].setString("Play");
	mainMenu[0].setCharacterSize(70);
	mainMenu[0].setPosition(400, 200);
	//Options
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::White);
	mainMenu[1].setString("Options");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(400, 300);
	//About
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color::White);
	mainMenu[2].setString("About");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(400, 400);
	//Quit Game
	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(sf::Color::White);
	mainMenu[3].setString("Quit Game");
	mainMenu[3].setCharacterSize(70);
	mainMenu[3].setPosition(400, 500);
	
	MainMenuSelected = -1;
}
//drawing the mainMenu
void MainMenu::draw(sf::RenderWindow& window) {
	for (int i = 0; i < Max_main_menu; ++i) 
		window.draw(mainMenu[i]);
}
//MoveUp
void MainMenu::MoveUp()
{
	if (MainMenuSelected - 1 >= 0) {
		mainMenu[MainMenuSelected].setFillColor(sf::Color::White);

		MainMenuSelected--;
		if (MainMenuSelected == -1) {
			MainMenuSelected = 2;
		}
		mainMenu[MainMenuSelected].setFillColor(sf::Color::Blue);
	}
}
//MoveDown
void MainMenu::MoveDown()
{
	if (MainMenuSelected + 1 <= Max_main_menu) 
	{
		mainMenu[MainMenuSelected].setFillColor(sf::Color::White);
		MainMenuSelected++;
		if (MainMenuSelected == 4) {
			MainMenuSelected = 0;
		}
		mainMenu[MainMenuSelected].setFillColor(sf::Color::Blue);
	}
}

void MainMenu::MouseMoved(sf::Vector2f mousePos)
{
	

	if (mainMenu[0].getGlobalBounds().contains(mousePos))
	{
		mainMenu[MainMenuSelected].setFillColor(sf::Color::White);
		MainMenuSelected = 0;
		mainMenu[MainMenuSelected].setFillColor(sf::Color::Blue);
	}
	else if (mainMenu[1].getGlobalBounds().contains(mousePos))
	{
		mainMenu[MainMenuSelected].setFillColor(sf::Color::White);
		MainMenuSelected = 1;
		mainMenu[MainMenuSelected].setFillColor(sf::Color::Blue);
	}
	else if (mainMenu[2].getGlobalBounds().contains(mousePos))
	{
		mainMenu[MainMenuSelected].setFillColor(sf::Color::White);
		MainMenuSelected = 2;
		mainMenu[MainMenuSelected].setFillColor(sf::Color::Blue);
	}
	else if (mainMenu[3].getGlobalBounds().contains(mousePos))
	{
		mainMenu[MainMenuSelected].setFillColor(sf::Color::White);
		MainMenuSelected = 3;
		mainMenu[MainMenuSelected].setFillColor(sf::Color::Blue);
	}
}