#include "Application.h"
#include <thread>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/System.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>
#include "AssetManager.h"
#include "RenderCycle.h"

void Application::run(sf::RenderWindow& window, float wWidth, float wHeight, AssetManager& assetManager)
{
    //
    const float Speed = 2.f;
    int fieldSize = 20;

    //making an Eventmanager & AssetManager
    


    //making the background out of a 64x64 Tile
    sf::Texture backgroundTR = sf::Texture(assetManager.GetTexture("EmptyWhiteTile.png"));
    backgroundTR.setRepeated(true);
    sf::RectangleShape background(sf::Vector2f(wWidth, wHeight));
    background.setTextureRect(sf::IntRect(0, 0, wWidth, wHeight));
    background.setTexture(&backgroundTR);
    //making vector, which; will contain the tiles of the TileMap
    std::vector<std::vector<sf::Sprite>> tiles;
    tiles.resize(fieldSize);
    //filling the field with empty Tiles
    for (int i = 0; i < fieldSize; i++)
        for (int j = 0; j < fieldSize; j++) {
            tiles.at(i).resize(fieldSize);
            tiles.at(i).at(j) = sf::Sprite(assetManager.GetTexture("EmptyWhiteTile.png"));
            tiles.at(i).at(j).setPosition(i * 64, j * 64);
        }
    //making the start arrow
    tiles.at(10).at(11) = sf::Sprite(assetManager.GetTexture("Arrow.png"));
    tiles.at(10).at(11).setPosition(10 * 64 + 16, 11 * 64);
    //making the player
    sf::Sprite Player = sf::Sprite(assetManager.GetTexture("Player.png"));
    Player.setOrigin(32, 32);
    Player.setPosition(64, 512);
    //spawning player at the start arrow
    for (int i = 0; i < fieldSize; i++)
        for (int j = 0; j < fieldSize; j++)
            if (tiles.at(i).at(j).getTexture() == &assetManager.GetTexture("Arrow.png"))
                Player.setPosition(64 * i + 32, 64 * j + 32);
    //
    tiles.at(15).at(11) = sf::Sprite(assetManager.GetTexture("SlantedLU.png"));
    tiles.at(15).at(11).setPosition(15 * 64, 11 * 64);
    //rendering once
    RenderCycle::render(window, tiles, background, Player);

    //starting the eventManager Thread
    //std::thread events(std::thread([&] { eventManager.EventHandling(window, sprites, tiles); }));

    while (window.isOpen())
    {
        //Events handled by eventManager in EventManager.cpp
        sf::Time deltaTime;
        sf::Clock clock;
        bool movedRight = false;
        bool movedLeft = false;
        bool movedUp = false;
        bool movedDown = false;
        bool moved = false;
        //restarts the clock
        deltaTime = clock.restart();
        float dtAsSeconds = deltaTime.asSeconds() + 1; // Delta time in seconds
        //events
        sf::Event event;
        window.waitEvent(event);
        do {
            switch (event.type)
            {
            case sf::Event::EventType::Closed:
                window.close();
                break;
            case sf::Event::EventType::KeyPressed:
                if (event.key.code == sf::Keyboard::Key::Escape)
                    window.close();
                else if (event.key.code == sf::Keyboard::Key::Right) {
                    if (tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).getTexture() == &assetManager.GetTexture("Arrow.png")) {
                        if (tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).getRotation() == 0) {
                            Player.setPosition(movePlayerRight(Player, tiles, assetManager, background, fieldSize, window, dtAsSeconds));
                            movedRight = true;
                        }
                    }
                    else if (tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).getTexture() == &assetManager.GetTexture("SlantedLUArrowRight.png")) {
                        Player.setPosition(movePlayerRight(Player, tiles, assetManager, background, fieldSize, window, dtAsSeconds));
                        movedRight = true;
                    }
                    else if (tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).getTexture() == &assetManager.GetTexture("FlatHArrowUp.png")) {
                        Player.setPosition(movePlayerRight(Player, tiles, assetManager, background, fieldSize, window, dtAsSeconds));
                        movedRight = true;
                    }
                    else if (tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).getTexture() == &assetManager.GetTexture("FlatHArrowDown.png")) {
                        Player.setPosition(movePlayerRight(Player, tiles, assetManager, background, fieldSize, window, dtAsSeconds));
                        movedRight = true;
                    }
                }
                else if (event.key.code == sf::Keyboard::Key::Left) {
                    if (tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).getTexture() == &assetManager.GetTexture("Arrow.png")) {
                        if (tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).getRotation() == 180) {
                            Player.setPosition(movePlayerRight(Player, tiles, assetManager, background, fieldSize, window, dtAsSeconds));
                            movedLeft = true;
                        }
                    }
                    else if (tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).getTexture() == &assetManager.GetTexture("SlantedLUArrowLeft.png")) {
                        Player.setPosition(movePlayerRight(Player, tiles, assetManager, background, fieldSize, window, dtAsSeconds));
                        movedLeft = true;
                    }
                    else if (tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).getTexture() == &assetManager.GetTexture("FlatHArrowUp.png")) {
                        Player.setPosition(movePlayerRight(Player, tiles, assetManager, background, fieldSize, window, dtAsSeconds));
                        movedLeft = true;
                    }
                    else if (tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).getTexture() == &assetManager.GetTexture("FlatHArrowDown.png")) {
                        Player.setPosition(movePlayerRight(Player, tiles, assetManager, background, fieldSize, window, dtAsSeconds));
                        movedLeft = true;
                    }
                }
                else if (event.key.code == sf::Keyboard::Key::Up) {
                    if (tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).getTexture() == &assetManager.GetTexture("Arrow.png")) {
                        if (tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).getRotation() == 270) {
                            Player.setPosition(movePlayerRight(Player, tiles, assetManager, background, fieldSize, window, dtAsSeconds));
                            movedUp = true;
                        }
                    }
                    else if (tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).getTexture() == &assetManager.GetTexture("SlantedLUArrowUp.png")) {
                        Player.setPosition(movePlayerRight(Player, tiles, assetManager, background, fieldSize, window, dtAsSeconds));
                        movedUp = true;
                    }
                    else if (tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).getTexture() == &assetManager.GetTexture("FlatVArrowL.png")) {
                        Player.setPosition(movePlayerRight(Player, tiles, assetManager, background, fieldSize, window, dtAsSeconds));
                        movedUp = true;
                    }
                    else if (tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).getTexture() == &assetManager.GetTexture("FlatVArrowR.png")) {
                        Player.setPosition(movePlayerRight(Player, tiles, assetManager, background, fieldSize, window, dtAsSeconds));
                        movedUp = true;
                    }
                }
                else if (event.key.code == sf::Keyboard::Key::Down) {
                    if (tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).getTexture() == &assetManager.GetTexture("Arrow.png")) {
                        if (tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).getRotation() == 90) {
                            Player.setPosition(movePlayerRight(Player, tiles, assetManager, background, fieldSize, window, dtAsSeconds));
                            movedDown = true;
                        }
                    }
                    else if (tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).getTexture() == &assetManager.GetTexture("SlantedLUArrowDown.png")) {
                        Player.setPosition(movePlayerRight(Player, tiles, assetManager, background, fieldSize, window, dtAsSeconds));
                        movedDown = true;
                    }
                    else if (tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).getTexture() == &assetManager.GetTexture("FlatVArrowL.png")) {
                        Player.setPosition(movePlayerRight(Player, tiles, assetManager, background, fieldSize, window, dtAsSeconds));
                        movedDown = true;
                    }
                    else if (tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).getTexture() == &assetManager.GetTexture("FlatVArrowR.png")) {
                        Player.setPosition(movePlayerRight(Player, tiles, assetManager, background, fieldSize, window, dtAsSeconds));
                        movedDown = true;
                    }
                }

            }

        } while (window.pollEvent(event));
        if (movedLeft || movedRight || movedUp || movedDown)
            moved = true;
        if (moved)
            if (tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).getTexture() == &assetManager.GetTexture("SlantedLU.png")) {
                if (movedRight)
                    tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).setTexture(assetManager.GetTexture("SlantedLUArrowUp.png"));
                else if (movedLeft)
                    tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).setTexture(assetManager.GetTexture("SlantedLUArrowDown.png"));
                else if (movedDown)
                    tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).setTexture(assetManager.GetTexture("SlantedLUArrowLeft.png"));
                else if (movedUp)
                    tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).setTexture(assetManager.GetTexture("SlantedLUArrowRight.png"));
            }
            else if (tiles.at(Player.getPosition().x / 64).at(Player.getPosition().y / 64).getTexture() == &assetManager.GetTexture("Goal.png")) {
                std::cout << "You Win!\n";
            }
        RenderCycle::render(window, tiles, background, Player);
        //Render cycle

    }




}
sf::Vector2f Application::movePlayerRight(sf::Sprite Player, std::vector<std::vector<sf::Sprite>> tiles, AssetManager assetManager, sf::RectangleShape background, int fieldSize, sf::RenderWindow& window, float dtAsSeconds) {
    //goes through all the tiles in the right direction of the player and looks if there is a component, if not returns the leaked tile, if yes then it moves the Player to the component
    bool leak = true;
    for (int k = int(Player.getPosition().x / 64); k < fieldSize; k++)
        if (tiles.at(k).at(int(Player.getPosition().y / 64)).getTexture() != &assetManager.GetTexture("EmptyWhiteTile.png") && (k != int(Player.getPosition().x / 64))) {
            std::cout << "current tile:" << k << " - " << int(Player.getPosition().y / 64) << "\n";
            for (int b = Player.getPosition().x; b < (k * 64 + 32); b++) {
                Player.move(1 * dtAsSeconds, 0);
                RenderCycle::render(window, tiles, background, Player);
            }
            leak = false;
            k = fieldSize;
        }
    if (leak)
        std::cout << "leaked at tile: " << Player.getPosition().x / 64 << " - " << Player.getPosition().y / 64 << "\n";
    return Player.getPosition();
}
sf::Vector2f Application::movePlayerLeft(sf::Sprite Player, std::vector<std::vector<sf::Sprite>> tiles, AssetManager assetManager, sf::RectangleShape background, int fieldSize, sf::RenderWindow& window, float dtAsSeconds) {
    //goes through all the tiles in the right direction of the player and looks if there is a component, if not returns the leaked tile, if yes then it moves the Player to the component
    bool leak = true;
    for (int k = int(Player.getPosition().x / 64); k > -1; k--)
        if (tiles.at(k).at(int(Player.getPosition().y / 64)).getTexture() != &assetManager.GetTexture("EmptyWhiteTile.png") && (k != int(Player.getPosition().x / 64))) {
            std::cout << "current tile:" << k << " - " << int(Player.getPosition().y / 64) << "\n";
            for (int b = Player.getPosition().x; b < (k * 64 + 32); b++) {
                Player.move(-1 * dtAsSeconds, 0);
                RenderCycle::render(window, tiles, background, Player);
            }
            leak = false;
            k = fieldSize;
        }
    if (leak)
        std::cout << "leaked at tile: " << Player.getPosition().x / 64 << " - " << Player.getPosition().y / 64 << "\n";
    return Player.getPosition();
}
sf::Vector2f Application::movePlayerUp(sf::Sprite Player, std::vector<std::vector<sf::Sprite>> tiles, AssetManager assetManager, sf::RectangleShape background, int fieldSize, sf::RenderWindow& window, float dtAsSeconds) {
    //goes through all the tiles in the right direction of the player and looks if there is a component, if not returns the leaked tile, if yes then it moves the Player to the component
    bool leak = true;
    for (int k = int(Player.getPosition().y / 64); k > -1; k--)
        if (tiles.at(int(Player.getPosition().x / 64)).at(k).getTexture() != &assetManager.GetTexture("EmptyWhiteTile.png") && (k != int(Player.getPosition().x / 64))) {
            std::cout << "current tile:" << k << " - " << int(Player.getPosition().x / 64) << "\n";
            for (int b = Player.getPosition().y; b < (k * 64 + 32); b++) {
                Player.move(0, -1 * dtAsSeconds);
                RenderCycle::render(window, tiles, background, Player);
            }
            leak = false;
            k = fieldSize;
        }
    if (leak)
        std::cout << "leaked at tile: " << Player.getPosition().x / 64 << " - " << Player.getPosition().y / 64 << "\n";
    return Player.getPosition();
}
sf::Vector2f Application::movePlayerDown(sf::Sprite Player, std::vector<std::vector<sf::Sprite>> tiles, AssetManager assetManager, sf::RectangleShape background, int fieldSize, sf::RenderWindow& window, float dtAsSeconds) {
    //goes through all the tiles in the right direction of the player and looks if there is a component, if not returns the leaked tile, if yes then it moves the Player to the component
    bool leak = true;
    for (int k = int(Player.getPosition().y / 64); k > -1; k--)
        if (tiles.at(int(Player.getPosition().x / 64)).at(k).getTexture() != &assetManager.GetTexture("EmptyWhiteTile.png") && (k != int(Player.getPosition().x / 64))) {
            std::cout << "current tile:" << k << " - " << int(Player.getPosition().y / 64) << "\n";
            for (int b = Player.getPosition().x; b < (k * 64 + 32); b++) {
                Player.move(0, 1 * dtAsSeconds);
                RenderCycle::render(window, tiles, background, Player);
            }
            leak = false;
            k = fieldSize;
        }
    if (leak)
        std::cout << "leaked at tile: " << Player.getPosition().x / 64 << " - " << Player.getPosition().y / 64 << "\n";
    return Player.getPosition();
}