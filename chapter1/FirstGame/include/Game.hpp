#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();
    void run();

private:
    int count;

    // private:
    //     void processEvents();
    //     void update();
    //     void render();

    // private:
    //     sf::RenderWindow window;
    //     sf::CircleShape circle;
};

#endif