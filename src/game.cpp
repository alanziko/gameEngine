#include "game.hpp"

Game::Game() :
    window(sf::RenderWindow(sf::VideoMode(APP_SIZE_X, APP_SIZE_Y), "App")),
    renderer(window), 
    scene(window) {
    window.setFramerateLimit(30); 
}

bool Game::isRunning() {
    return window.isOpen();
}

void Game::mainloop() {
    scene.update();
    renderer.draw(scene.getRegistry());
}