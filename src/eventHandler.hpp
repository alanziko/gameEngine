#include <SFML/Graphics.hpp>
#include <entt.hpp>

#include "components.hpp"

class EventHandler {
    public:
        EventHandler(sf::RenderWindow& window, entt::registry& registry);
        void pollEvent();
    private:
        void closeEvent();
        sf::RenderWindow& window;
        entt::registry& registry;
        sf::Event event;
};