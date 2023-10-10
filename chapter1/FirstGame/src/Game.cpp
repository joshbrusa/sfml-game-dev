#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

const float Game::PlayerSpeed = 100.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
    : window(sf::VideoMode(640, 480), "SFML Application"),
      texture(),
      player(),
      font(),
      text(),
      isMovingUp(false),
      isMovingDown(false),
      isMovingLeft(false),
      isMovingRight(false)
{
    texture.loadFromFile("../assets/images/Eagle.png");
    font.loadFromFile("../assets/fonts/Sansation.ttf");

    player.setTexture(texture);
    player.setPosition(100.f, 100.f);
    text.setFont(font);
    text.setPosition(5.f, 5.f);
    text.setCharacterSize(10);
    text.setString("First Game");
};

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (window.isOpen())
    {
        timeSinceLastUpdate += clock.restart();
        processEvents();

        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }

        render();
    }
}

void Game::render()
{
    window.clear();
    window.draw(player);
    window.draw(text);
    window.display();
}

void Game::update(sf::Time elapsedTime)
{
    sf::Vector2f movement(0.f, 0.f);
    if (isMovingUp)
        movement.y -= PlayerSpeed;
    if (isMovingDown)
        movement.y += PlayerSpeed;
    if (isMovingLeft)
        movement.x -= PlayerSpeed;
    if (isMovingRight)
        movement.x += PlayerSpeed;
    player.move(movement * elapsedTime.asSeconds());
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    switch (key)
    {
    case sf::Keyboard::W:
        isMovingUp = isPressed;
        break;
    case sf::Keyboard::S:
        isMovingDown = isPressed;
        break;
    case sf::Keyboard::A:
        isMovingLeft = isPressed;
        break;
    case sf::Keyboard::D:
        isMovingRight = isPressed;
        break;
    default:
        break;
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;
        case sf::Event::Closed:
            window.close();
            break;
        default:
            break;
        }
    }
}