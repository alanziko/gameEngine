#include <entt.hpp>
#include "luaFunctions.hpp"

std::vector<entt::entity> getEntitiesByComponent(entt::registry& registry, std::string componentName) {
    std::vector<entt::entity> entities;
    if(componentName == "Position") {
        auto view = registry.view<Position>();
        for(const auto entity : view) {
            entities.push_back(entity);
        }
        return entities;
    } else {
        return std::vector<entt::entity>{};
    }
}

void setPosition(entt::registry& registry, entt::entity entity, float x, float y) {
    auto& position = registry.get<Position>(entity);
    position.x = x;
    position.y = y;
}

std::vector<float> getPosition(entt::registry& registry, entt::entity entity) {
    auto& position = registry.get<Position>(entity);
    return std::vector<float>{position.x, position.y};
}