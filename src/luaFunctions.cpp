#include "luaFunctions.hpp"

entt::entity getEventMap(entt::registry& registry) {
    return registry.view<EventMap>().front();
}

std::vector<entt::entity> getEntitiesByComponent(entt::registry& registry, std::string componentName) {
    std::vector<entt::entity> entities;
    if(componentName == "Position") {
        auto view = registry.view<Position>();
        for(const auto entity : view) {
            entities.push_back(entity);
        }
        return entities;
    } else if(componentName == "SelectedUnit") {
        const auto& entity = registry.view<SelectedUnit>().front();
        entities.push_back(entity);
        return entities;
    } else {
        return std::vector<entt::entity>{};
    }
}

void setSelectedUnit(entt::registry& registry, entt::entity entity) {
    const auto selecetedEntity = registry.view<SelectedUnit>().front();
    registry.remove<SelectedUnit>(selecetedEntity);
    registry.emplace<SelectedUnit>(entity);
}

void setPosition(entt::registry& registry, entt::entity entity, float x, float y) {
    auto& position = registry.get<Position>(entity);
    position.x = x;
    position.y = y;
}

std::vector<float> getPosition(entt::registry& registry, entt::entity entity) {
    const auto& position = registry.get<Position>(entity);
    return std::vector<float>{position.x, position.y};
}

std::vector<int> getMousePosition(entt::registry& registry, entt::entity entity) {
    const auto& eventMapData = registry.get<EventMap>(entity);
    sf::Vector2i mouse_position = eventMapData.mouse_position;
    return std::vector<int>{mouse_position.x, mouse_position.y};
}

