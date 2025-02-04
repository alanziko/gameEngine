#include <sol/sol.hpp>

class SystemHandler {
    public:
        SystemHandler();
    private:
        sol::state lua;
};