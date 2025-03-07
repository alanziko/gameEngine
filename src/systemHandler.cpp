#include "systemHandler.hpp"

SystemHandler::SystemHandler(entt::registry& registry) :
    registry(registry) {
    setup();
    setFunctions();
    bindSystems();
}


void SystemHandler::setup() {

    eventMapEntity = registry.view<EventMap>().front();

    lua["APP_SIZE_X"] = APP_SIZE_X;
    lua["APP_SIZE_Y"] = APP_SIZE_Y;
    lua["TILE_SIZE"] = TILE_SIZE;
    lua["MAP_Y_OFFSET"] = MAP_Y_OFFSET;


    lua.open_libraries(sol::lib::base);
    lua.script_file("../src/scripts/movementSystem.lua");
    lua.script_file("../src/scripts/unitSystem.lua");
}

void SystemHandler::setFunctions() {
    lua.set_function("getMousePosition", [this]() {
        return getMousePosition(registry, eventMapEntity);
    });
    lua.set_function("getLeftMouseButtonState", [this]() {
        return getLeftMouseButtonState(registry, eventMapEntity);
    });
    lua.set_function("getRightMouseButtonState", [this]() {
        return getRightMouseButtonState(registry, eventMapEntity);
    });
    lua.set_function("getEntitiesByComponent", [this](std::string componentName) {
        return getEntitiesByComponent(registry, componentName);
    });
    lua.set_function("setSelectedUnit", [this](entt::entity entity) {
        return setSelectedUnit(registry, entity);
    });
    lua.set_function("getSelectedUnit", [this]() {
        return getSelectedUnit(registry);
    });
    lua.set_function("setPosition", [this](entt::entity entity, float x, float y) {
        return setPosition(registry, entity, x, y);
    });
    lua.set_function("getPosition", [this](entt::entity entity) {
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