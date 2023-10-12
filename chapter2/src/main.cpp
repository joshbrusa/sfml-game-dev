#include <map>
#include <SFML/Graphics.hpp>

namespace Textures
{
    enum class ID
    {
        Landscape,
        Airplane,
    };
}

class TextureHolder
{
private:
    std::map<Textures::ID,
             std::unique_ptr<sf::Texture>>
        mTextureMap;
};

int main()
{

    return 0;
}