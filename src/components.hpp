#pragma once
#include <SFML/Graphics.hpp>

struct Position {
    float x;
    float y;
};

struct TextInfo {
    std::string str;
    sf::Font font;
    int charSize;
};

struct SelectedUnit {};

struct EventMap {
    bool left_button_state;
    bool right_button_state;
    sf::Vector2i mouse_position;
};