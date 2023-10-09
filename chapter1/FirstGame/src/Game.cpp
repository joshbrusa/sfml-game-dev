#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <iostream>

Game::Game()
    : window(sf::VideoMode(640, 480), "SFML Application"), circle()
{
    circle.setRadius(40.f);
    circle.setPosition(100.f, 100.f);
    circle.setFillColor(sf::Color::Cyan);
};

void Game::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update()
{
}

void Game::render()
{
    window.clear();
    window.draw(circle);
    window.display();
}