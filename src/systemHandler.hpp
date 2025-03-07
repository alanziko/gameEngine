#include <sol/sol.hpp>
#include <entt.hpp>

#include "components.hpp"
#include "constants.hpp"
#include "luaFunctions.hpp"

class SystemHandler {
    public:
        SystemHandler(entt::registry& registry);
        void setup();
        void setFunctions();
        void bindSystems();
        void runSystems();
    private:
        entt::registry& registry;
        entt::entity eventMapEntity;
        sol::state lua;
        std::function<void()> systems[2];
};