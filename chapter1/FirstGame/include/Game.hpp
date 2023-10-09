#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();
    void run();

private:
    void processEvents();
    void update(sf::Time elapsedTime);
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
    static const float PlayerSpeed;
    static const sf::Time TimePerFrame;
    sf::RenderWindow window;
    sf::CircleShape player;
    bool isMovingUp;
    bool isMovingDown;
    bool isMovingLeft;
    bool isMovingRight;
};

#endif