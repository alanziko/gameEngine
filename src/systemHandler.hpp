#include <sol/sol.hpp>
#include <entt.hpp>

#include "components.hpp"
#include "constants.hpp"
#include "luaFunctions.hpp"

class SystemHandler {
    public:
        SystemHandler(entt::registry& registry);
        void setup(entt::registry& registry);
        void setFunctions(entt::registry& registry);
        void bindSystems();
        void runSystems();
    private:
        sol::state lua;
        std::function<void()> systems[2];
};