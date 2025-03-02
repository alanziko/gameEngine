#include "components.hpp"
#include <entt.hpp>
// Functions 

entt::entity getEventMap(entt::registry& registry);
std::vector<entt::entity> getEntitiesByComponent(entt::registry& registry, std::string componentName);
void setSelectedUnit(entt::registry& registry, entt::entity entity);
void setPosition(entt::registry& registry, entt::entity entity, float x, float y);
std::vector<float> getPosition(entt::registry& registry, entt::entity entity);
std::vector<int> getMousePosition(entt::registry& registry, entt::entity entity);