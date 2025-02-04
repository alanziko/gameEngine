#pragma once
#include <SFML/Graphics.hpp>

struct Position {
    float x;
    float y;
};

struct Stats {
    int hp;
    int mvn;
};

struct TextInfo {
    std::string str;
    sf::Font font;
    int charSize;
};