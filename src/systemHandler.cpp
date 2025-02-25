#include "systemHandler.hpp"

SystemHandler::SystemHandler(entt::registry& registry) {
    lua.open_libraries(sol::lib::base);
    lua.script_file("../src/scripts/movementSystem.lua");   
    bindSystems();
    setFunctions(registry);
}

void SystemHandler::setFunctions(entt::registry& registry) {
    lua.set_function("getEntitiesByComponent", [&registry](std::string componentName) {
        return getEntitiesByComponent(registry, componentName);
    });
    lua.set_function("setPosition", [&registry](entt::entity entity, float x, float y) {
        return setPosition(registry, entity, x, y);
    });
    lua.set_function("getPosition", [&registry](entt::entity entity) {
        return getPosition(registry, entity);
    });
}

void SystemHandler::bindSystems() {
    systems[0] = lua["movementSystem"];
}

void SystemHandler::runSystems(entt::registry& registry) {  
    systems[0](registry);
}