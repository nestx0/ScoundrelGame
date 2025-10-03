#include "../includes/screens.hpp"
#include "../includes/enginecontext.hpp"
#include "../includes/raylib.h"
#include "../includes/screenmanager.hpp"
#include <memory>
class ScreenManager;

void MainMenuScreen::init() {
  _playButton = std::make_unique<Button>(500, 200, 200, 100, "jugar");
  _exitButton = std::make_unique<Button>(200, 200, 200, 100, "salir");
}
void MainMenuScreen::handleInput() {
  if (_playButton->isClicked()) {
    _engineContext->_screenManager->pushScreen(
        std::make_unique<GameplayScreen>());
  } else if (_exitButton->isClicked()) {
    _engineContext->closeRequest = true;
  }
}
void MainMenuScreen::update() {}

void MainMenuScreen::render() {
  ClearBackground(GREEN);
  _playButton->drawButton();
  _exitButton->drawButton();
}

void GameplayScreen::init() {}
void GameplayScreen::handleInput() {}
void GameplayScreen::update() {}
void GameplayScreen::render() {}

void LoadingScreen::init() {}
void LoadingScreen::handleInput() {}
void LoadingScreen::update() {}
void LoadingScreen::render() {}
