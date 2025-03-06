#include "systemHandler.hpp"

SystemHandler::SystemHandler(entt::registry& registry) {
    setup(registry);
    setFunctions(registry);
    bindSystems();
}


void SystemHandler::setup(entt::registry& registry) {

    const auto eventMapEntity = registry.view<EventMap>().front();
    lua.set("eventMapEntity", eventMapEntity);

    lua["APP_SIZE_X"] = APP_SIZE_X;
    lua["APP_SIZE_Y"] = APP_SIZE_Y;
    lua["TILE_SIZE"] = TILE_SIZE;
    lua["MAP_Y_OFFSET"] = MAP_Y_OFFSET;


    lua.open_libraries(sol::lib::base);
    lua.script_file("../src/scripts/movementSystem.lua");
    lua.script_file("../src/scripts/unitSystem.lua");
}

void SystemHandler::setFunctions(entt::registry& registry) {
    lua.set_function("getMousePosition", [&registry](entt::entity eventMap) {
        return getMousePosition(registry, eventMap);
    });
    lua.set_function("getLeftMouseButtonState", [&registry](entt::entity eventMap) {
        return getLeftMouseButtonState(registry, eventMap);
    });
    lua.set_function("getRightMouseButtonState", [&registry](entt::entity eventMap) {
        return getRightMouseButtonState(registry, eventMap);
    });
    lua.set_function("getEntitiesByComponent", [&registry](std::string componentName) {
        return getEntitiesByComponent(registry, componentName);
    });
    lua.set_function("setSelectedUnit", [&registry](entt::entity entity) {
        return setSelectedUnit(registry, entity);
    });
    lua.set_function("getSelectedUnit", [&registry]() {
        return getSelectedUnit(registry);
    });
    lua.set_function("setPosition", [&registry](entt::entity entity, float x, float y) {
        return setPosition(registry, entity, x, y);
    });
    lua.set_function("getPosition", [&registry](entt::entity entity) {
        return getPosition(registry, entity);
    });
}

void SystemHandler::bindSystems() {
    systems[0] = lua["unitSystem"];
    systems[1] = lua["movementSystem"];
}

void SystemHandler::runSystems() { 
    systems[0]();
    systems[1]();
}