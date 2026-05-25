#include "Assets.h"
#include <iostream>

std::unordered_map<std::string, sf::Texture> Assets::textures_;

void Assets::LoadTexture(const std::string& name, const std::string& path)
{
    sf::Texture texture;
    texture.loadFromFile(path);
    textures_[name] = texture;
}