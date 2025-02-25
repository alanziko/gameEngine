#include <entt.hpp>
#include <fstream>
#include <nlohmann/json.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "components.hpp"
#include "constants.hpp"
#include "systemHandler.hpp"
#include "eventHandler.hpp"

using json = nlohmann::json;

class CombatScene {
    public:
        CombatScene(sf::RenderWindow& window);

        void update();
        void loadScene();
        entt::registry& getRegistry();
    private:    
        sf::RenderWindow& window;
        entt::registry registry;
        SystemHandler systemHandler;
        EventHandler eventHandler;
};