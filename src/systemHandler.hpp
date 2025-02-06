#include <sol/sol.hpp>
#include <entt.hpp>

#include "components.hpp"

class SystemHandler {
    public:
        SystemHandler(entt::registry& registry);
    private:
        sol::state lua;
};