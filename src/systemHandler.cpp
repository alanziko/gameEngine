#include "systemHandler.hpp"

SystemHandler::SystemHandler() {
    lua.open_libraries(sol::lib::base);
}