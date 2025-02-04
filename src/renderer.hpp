#include <SFML/Graphics.hpp>
#include <entt.hpp>

#include "constants.hpp"
#include "components.hpp"

class Renderer {
    public:
        Renderer(sf::RenderWindow& win);
    
        void draw(entt::registry& registry);

    private:
        void drawUnits(entt::registry& registry);
        void drawText(entt::registry& registry);

        sf::RenderWindow& window;
        sf::Color textColor;
};