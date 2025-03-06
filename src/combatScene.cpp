#include "combatScene.hpp"

CombatScene::CombatScene(sf::RenderWindow& window) : 
    window(window),
    eventHandler(window, registry),
    systemHandler(registry) {
    loadScene();
}

void CombatScene::update() {
    eventHandler.pollEvent();
    systemHandler.runSystems();
}

entt::registry& CombatScene::getRegistry() {
    return registry;
}

void CombatScene::loadScene() {
    std::fstream file("../src/scenes/testScene.json");

    json j;
    file >> j;

    for(const auto& entity_data : j["entities"]) {
        const auto& entity = registry.create();

        auto position = entity_data["position"];

        registry.emplace<Position>(entity, (float)position["x"], (float)position["y"]);
        // registry.emplace<sf::Color>(entity, sf::Color::Red);
    }
}