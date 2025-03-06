#include "components.hpp"
#include <entt.hpp>
// Functions 

std::vector<int> getMousePosition(entt::registry& registry, entt::entity eventMap);
bool getLeftMouseButtonState(entt::registry& registry, entt::entity eventMap);
bool getRightMouseButtonState(entt::registry& registry, entt::entity eventMap);
std::vector<entt::entity> getEntitiesByComponent(entt::registry& registry, std::string componentName);
void setSelectedUnit(entt::registry& registry, entt::entity entity);
entt::entity getSelectedUnit(entt::registry& registry);
void setPosition(entt::registry& registry, entt::entity entity, float x, float y);
std::vector<float> getPosition(entt::registry& registry, entt::entity entity);