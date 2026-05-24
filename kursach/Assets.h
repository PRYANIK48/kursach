#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class Assets
{
public:
    static void LoadTexture(const std::string& name, const std::string& path);

    static sf::Texture& GetTexture(const std::string& name) { return textures_.at(name); };

private:
    static std::unordered_map< std::string, sf::Texture> textures_;
};