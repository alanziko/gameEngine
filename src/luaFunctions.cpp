#include "luaFunctions.hpp"

std::vector<int> getMousePosition(entt::registry& registry, entt::entity eventMap) {
    std::vector<int> output;
    const auto mousePosition = registry.get<EventMap>(eventMap).mouse_position;
    output.push_back(mousePosition.x);
    output.push_back(mousePosition.y);
    return output;
}

bool getLeftMouseButtonState(entt::registry& registry, entt::entity eventMap) {
    const auto output = registry.get<EventMap>(eventMap);
    return output.left_button_state;
}
bool getRightMouseButtonState(entt::registry& registry, entt::entity eventMap) {
    const auto output = registry.get<EventMap>(eventMap);
    return output.right_button_state;
}

std::vector<entt::entity> getEntitiesByComponent(entt::registry& registry, std::string componentName) {
    std::vector<entt::entity> output = {};
    if(componentName == "Position") {
        auto const view = registry.view<Position>(entt::exclude<TextInfo>);
        for(entt::entity const entity : view) {
            output.push_back(entity);
        }
    } 
    return output;
};

void setSelectedUnit(entt::registry& registry, entt::entity entity) {
    const auto selectedEntity = registry.view<SelectedUnit>().front();
    registry.remove<SelectedUnit>(selectedEntity);
    registry.emplace<SelectedUnit>(entity);
}

entt::entity getSelectedUnit(entt::registry& registry) {
    const auto output = registry.view<SelectedUnit>();
    if (output.size() == 0) {
        const auto entity = registry.view<Position>().front();
        registry.emplace<SelectedUnit>(entity);
    }
    return output.front();
}

void setPosition(entt::registry& registry, entt::entity entity, float x, float y) {
    auto& position = registry.get<Position>(entity);
    position.x = x;
    position.y = y;
}

std::vector<float> getPosition(entt::registry& registry, entt::entity entity) {
    std::vector<float> output;
    const auto entityPosition = registry.get<Position>(entity);
    output.push_back(entityPosition.x);
    output.push_back(entityPosition.y);
    return output;   
}