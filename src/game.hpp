#include "renderer.hpp"
#include "combatScene.hpp"

class Game {
    public:
        Game();
        void mainloop();
        bool isRunning();
    private:
        sf::RenderWindow window;
        Renderer renderer;
        CombatScene scene;
};