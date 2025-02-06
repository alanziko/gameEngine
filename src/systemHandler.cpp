#include "systemHandler.hpp"

SystemHandler::SystemHandler(entt::registry& registry) {
    lua.open_libraries(sol::lib::base);
    lua.script_file("../src/scripts/movementSystem.lua");
    
    lua.set_function("set_position", [&registry](entt::entity entity, float x, float y) {
        auto& pos = registry.get<Position>(entity);
        pos.x = x;
        pos.y = y;
    });

    const std::function<void(entt::entity)>& movementSystem = lua["movementSystem"];

    auto view = registry.view<Position>();
    for(const auto& entity : view) {
        movementSystem(entity);
        break;
    }
    
}