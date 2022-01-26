#include "MainMenu.h"
#include "Application.h"
#include "AssetManager.h"
#include <SFML/Graphics.hpp>

int main()
{
    //making the window
    float wWidth = 1920.f;
    float wHeight = 1080.f;
    sf::Uint32 style = sf::Style::Titlebar | sf::Style::Close;
    sf::RenderWindow window(sf::VideoMode(wWidth,wHeight), style);
    MainMenu mainMenu;
    Application application;
    AssetManager assetManager;
    //putting the Main Menu on top
    window.clear();
    mainMenu.draw(window);
    window.display();
    while (window.isOpen())
    {
        sf::Event event;
        window.waitEvent(event);
        do {
            switch (event.type)
            {
            case sf::Event::EventType::Closed:
                window.close();
            case sf::Event::EventType::KeyReleased:
                if (event.key.code == sf::Keyboard::Up)
                {
                    mainMenu.MoveUp();
                    break;
                }
                else if (event.key.code == sf::Keyboard::Down) {
                    mainMenu.MoveDown();
                    break;
                }
                else if (event.key.code == sf::Keyboard::Return) {
                    sf::RenderWindow Play(sf::VideoMode(1920, 1080), "Labyrinth");
                    sf::RenderWindow Options(sf::VideoMode(1920, 1080), "Options");
                    sf::RenderWindow About(sf::VideoMode(1920, 1080), "About");

                    int x = mainMenu.MainMenuPressed();
                    switch (x)
                    {
                    case 0:
                        //Run Game
                        Options.close();
                        About.close();
                        application.run(Play, wWidth, wHeight, assetManager);
                        Play.close();
                        break;
                    case 1:
                        //Options
                    case 2:
                        //About
                    case 3:
                        //Quit Game
                        window.close();
                        break;
                    default:
                        break;
                    }
                    
                }
            case sf::Event::MouseButtonReleased:
                if (event.key.code == sf::Mouse::Left) {
                    sf::RenderWindow Play(sf::VideoMode(1920, 1080), "Labyrinth");
                    sf::RenderWindow Options(sf::VideoMode(1920, 1080), "Options");
                    sf::RenderWindow About(sf::VideoMode(1920, 1080), "About");
                    int x = mainMenu.MainMenuPressed();
                    switch (x)
                    {
                    case 0:
                        //Run Game
                        Options.close();
                        About.close();
                        application.run(Play, wWidth, wHeight, assetManager);
                        Play.close();
                        break;
                    case 1:
                        //Options
                    case 2:
                        //About
                    case 3:
                        //Quit Game
                        window.close();
                        break;
                    default:
                        break;
                    }
                }
            case sf::Event::EventType::MouseMoved:
                mainMenu.MouseMoved(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
                break;
            default:
                break;
            }
        } while (window.pollEvent(event));
        window.clear();
        mainMenu.draw(window);
        window.display();
    }
    window.close();
    return 0;
}

