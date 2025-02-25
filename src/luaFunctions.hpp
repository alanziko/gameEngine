#include "components.hpp"
#include <entt.hpp>
// Functions 

std::vector<entt::entity> getEntitiesByComponent(entt::registry& registry, std::string componentName);
void setPosition(entt::registry& registry, entt::entity entity, float x, float y);
std::vector<float> getPosition(entt::registry& registry, entt::entity entity);
std::vector<int> getMousePosition(entt::registry& registry, entt::entity entity);
entt::entity getEventMap(entt::registry& registry);