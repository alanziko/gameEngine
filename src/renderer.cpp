#include "renderer.hpp"

Renderer::Renderer(sf::RenderWindow& win) : window(win) {
    textColor = sf::Color::White; // to change
}

void Renderer::draw(entt::registry& registry) {
    window.clear();  
    
    drawUnits(registry);
    drawText(registry);

    window.display();
}

void Renderer::drawUnits(entt::registry& registry) {
    auto view = registry.view<Position>();
        for (const auto& entity : view) {
        const auto pos = view.get<Position>(entity); 
        // const auto color = view.get<sf::Color>(entity);

        sf::RectangleShape rect(sf::Vector2f(TILE_SIZE, TILE_SIZE));
        rect.setPosition(sf::Vector2f(pos.x*TILE_SIZE, pos.y*TILE_SIZE+MAP_Y_OFFSET));
        rect.setFillColor(sf::Color::Red);

        window.draw(rect);
    }
}

void Renderer::drawText(entt::registry& registry) {
    auto view = registry.view<Position, TextInfo>();
    for (const auto& entity : view) {
        const auto pos = view.get<Position>(entity);
        const auto textInfo = view.get<TextInfo>(entity);

        sf::Text text(textInfo.str, textInfo.font, textInfo.charSize);
        text.setFillColor(textColor);
        text.setPosition(pos.x, pos.y);

        window.draw(text);
    }
}