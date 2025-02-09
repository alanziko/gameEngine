#include <sol/sol.hpp>
#include <entt.hpp>

#include "components.hpp"
#include "luaFunctions.hpp"

class SystemHandler {
    public:
        SystemHandler(entt::registry& registry, sf::RenderWindow& window);
        void setFunctions(entt::registry& registry, sf::RenderWindow& window);
        void bindSystems();
        void runSystems(entt::registry& registry);
    private:
        sol::state lua;
        std::function<void(entt::registry&)> systems[2];
};