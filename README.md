# Game Engine
"Game Engine" is just simple concept of game engine using ECS.

## How to build
Linux terminal commands to build project:
```
mkdir build
cd build
cmake ..
make
```
Building was only tested in Linux but it should also work in Windows by adding cmake flag ```-G "Unix Makefiles"```.

If any problems occur during build you can post an issue.

### Dependencies
- Lua 5.4
- nlohmann_json 3.11
- SFML 2.6

There are also headers-only libraries that are already included in project:
- EnTT
- sol2
## To-do list
Project is already done but there are some changes that I want to do to in the future. Most of them will make engine easier to expand and use. Final version should allow user to create components, scenes and systems (lua scripts) to make simple game without editing src.
- [ ] Organize project includes/headers
- [ ] Implement better solution for Lua bindings
- [ ] Change how functions gets entities from registry