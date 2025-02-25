cmake_minimum_required(VERSION 3.22)
project(Engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES 
    src/main.cpp
    src/game.cpp
    src/renderer.cpp
    src/combatScene.cpp
    src/systemHandler.cpp
    src/luaFunctions.cpp
    src/eventHandler.cpp
)

add_executable(app ${SOURCES})

include_directories(include ${LUA_INCLUDE_DIR})

find_package(Lua 5.4 REQUIRED)
find_package(nlohmann_json 3.11 REQUIRED)
find_package(SFML 2.6 COMPONENTS system window graphics REQUIRED)

target_link_libraries(app PRIVATE sfml-system sfml-window sfml-graphics nlohmann_json::nlohmann_json ${LUA_LIBRARIES})
