#pragma once
#include <SFML/Graphics.hpp>

struct Position {
    float x;
    float y;
};

struct Stats {
    int hit_points;
    int movement;
};

struct TextInfo {
    std::string str;
    sf::Font font;
    int charSize;
};

struct SelectedUnit {};

struct EventMap {
    sf::Event event;
    sf::Vector2i mouse_position;
};