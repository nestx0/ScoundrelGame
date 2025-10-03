#include "../includes/gamemanager.hpp"

const Game &GameManager::getGame() const { return _game; }
Game &GameManager::getGame() { return _game; }
const ScreenManager &GameManager::getScreenManager() const {
  return _screenManager;
}
const EngineContext &GameManager::getContext() const { return _engineContext; }

ScreenManager &GameManager::getScreenManager() { return _screenManager; }
const TextureManager &GameManager::getTextureManager() const {
  return _textureManager;
}
TextureManager &GameManager::getTextureManager() { return _textureManager; }
EngineContext &GameManager::getContext() { return _engineContext; }

void GameManager::unload() {
  _screenManager.clearAllScreens();
  _textureManager.unloadAllTextures();
  TraceLog(LOG_INFO, "Successfully unloaded");
}
