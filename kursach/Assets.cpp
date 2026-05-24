#include "Assets.h"
#include <iostream>

std::unordered_map<std::string, sf::Texture> Assets::textures_;

void Assets::LoadTexture(const std::string& name, const std::string& path)
{
    sf::Texture texture;
    if (!texture.loadFromFile(path))
    {
        std::cout
            << "Failed to load texture: "
            << path
            << std::endl;

        return;
    }
    textures_[name] = texture;
}