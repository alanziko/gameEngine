#include <sol/sol.hpp>
#include <entt.hpp>

#include "components.hpp"
#include "luaFunctions.hpp"

class SystemHandler {
    public:
        SystemHandler(entt::registry& registry);
        void setFunctions(entt::registry& registry);
        void bindSystems();
        void runSystems(entt::registry& registry);
    private:
        sol::state lua;
        std::function<void(entt::registry&)> systems[2];
};