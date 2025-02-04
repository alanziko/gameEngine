#include <entt.hpp>
#include <fstream>
#include <nlohmann/json.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "components.hpp"
#include "constants.hpp"

using json = nlohmann::json;

class CombatScene {
    public:
        CombatScene();

        void update();
        void loadScene();
        entt::registry& getRegistry();

    private:
        void updateEvents();
    
        sf::RenderWindow window;
        entt::registry registry;

};