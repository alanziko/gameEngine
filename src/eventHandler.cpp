#include "eventHandler.hpp"

EventHandler::EventHandler(sf::RenderWindow& window, entt::registry& registry) :
    window(window),
    registry(registry) {
    
    const auto eventMapEntity = registry.create();
    registry.emplace<EventMap>(eventMapEntity);
}

void EventHandler::pollEvent() {
    const auto& eventMap = registry.view<EventMap>().front();
    while(window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        
        auto& eventMapComponent = registry.get<EventMap>(eventMap);
        eventMapComponent.event = event; 
        eventMapComponent.mouse_position = sf::Mouse::getPosition(window);
    }
}
  