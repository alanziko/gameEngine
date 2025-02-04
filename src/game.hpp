#include "renderer.hpp"
#include "combatScene.hpp"
#include "systemHandler.hpp"

class Game {
    public:
        Game();
        void mainloop();
        bool isRunning();
    private:
        SystemHandler systemHandler;
        sf::RenderWindow window;
        Renderer renderer;
        CombatScene scene;
};