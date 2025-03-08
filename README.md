# Game Engine
"Game Engine" is just simple concept of game engine using ECS.
This project was created during the learning process, and its quality isn’t the best.
## How to build
Linux terminal commands to build project:
```
mkdir build
cd build
cmake ..
make
```
Building was only tested in Linux but it should also work in Windows by adding cmake flag ```-G "Unix Makefiles"```.

If any problems occur during the build process, you can report them by posting an issue.
### Dependencies
- [Lua](https://www.lua.org/) 5.4
- [nlohmann/json](https://github.com/nlohmann/json) 3.11
- [SFML](https://www.sfml-dev.org) 2.6

There are also headers-only libraries that are already included in project:
- [EnTT](https://github.com/skypjack/entt) 3.14.0
- [sol2](https://github.com/ThePhD/sol2) 3.3.0
## To-do list
The project is already complete, but I plan to implement some future changes to enhance its expandability and ease of use. These updates will focus on making the engine more flexible and user-friendly. The final version should enable users to create components, scenes, and systems (Lua scripts) to build simple games without needing to modify the source code.
- [ ] Organize project includes/headers
- [ ] Implement better solution for Lua bindings
- [ ] Change how functions access entities and updates components values
- [ ] Create scene class for menu