#include "enginecontext.hpp"
#include "game.hpp"
#include "screenmanager.hpp"
#include "texturemanager.hpp"

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

class GameManager {
private:
  Game _game;
  ScreenManager _screenManager;
  TextureManager _textureManager;
  EngineContext _engineContext;

public:
  GameManager() : _screenManager(&_engineContext) {
    _engineContext._screenManager = &_screenManager;
    _engineContext._game = &_game;
    _engineContext._textureManager = &_textureManager;
  };

  ~GameManager() { unload(); };

  const Game &getGame() const;
  const ScreenManager &getScreenManager() const;
  const TextureManager &getTextureManager() const;
  const EngineContext &getContext() const;

  Game &getGame();
  ScreenManager &getScreenManager();
  TextureManager &getTextureManager();
  EngineContext &getContext();

  void unload();
};

#endif /* GAMEMANAGER_H */
