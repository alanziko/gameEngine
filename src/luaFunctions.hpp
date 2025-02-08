#include "components.hpp"
// Functions 

std::vector<entt::entity> getEntitiesByComponent(entt::registry& registry, std::string componentName);
void setPosition(entt::registry& registry, entt::entity entity, float x, float y);
std::vector<float> getPosition(entt::registry& registry, entt::entity entity);