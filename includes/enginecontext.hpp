class ScreenManager;
class TextureManager;
class Game;

#ifndef ENGINECONTEXT_H
#define ENGINECONTEXT_H

struct EngineContext {
  ScreenManager *_screenManager = nullptr;
  Game *_game = nullptr;
  TextureManager *_textureManager = nullptr;

  bool closeRequest = false;
};

#endif // ENGINECONTEXT_H
