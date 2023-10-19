#include <iostream>
#include <stdexcept>
#include <Book/Game.hpp>

int main()
{
    try
    {
        Game game;
        game.run();
    }
    catch (std::exception &e)
    {
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }
}