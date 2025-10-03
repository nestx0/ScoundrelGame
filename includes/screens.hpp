#include "button.hpp"
#include "enginecontext.hpp"
#include <memory>
#ifndef SCREENS_H
#define SCREENS_H

class Button;

class BaseScreen {
protected:
  EngineContext *_engineContext;

public:
  void setContext(EngineContext *context) { _engineContext = context; };

  virtual void init() = 0; // Loads neccesary things
  virtual void
  handleInput() = 0; // Depending on the buttons pulsed, one action or another
  virtual void update() = 0; // Changes the logic state of the game
  virtual void render() = 0; // Draws everything
};

class MainMenuScreen : public BaseScreen {
public:
  virtual void init() override; // Loads neccesary things
  virtual void handleInput()
      override; // Depending on the buttons pulsed, one action or another
  virtual void update() override; // Changes the logic state of the game
  virtual void render() override; // Draws everything
private:
  std::unique_ptr<Button> _playButton;
  std::unique_ptr<Button> _exitButton;
};
class LoadingScreen : public BaseScreen {
public:
  virtual void init() override; // Loads neccesary things
  virtual void handleInput()
      override; // Depending on the buttons pulsed, one action or another
  virtual void update() override; // Changes the logic state of the game
  virtual void render() override; // Draws everything
};
class GameplayScreen : public BaseScreen {
public:
  virtual void init() override; // Loads neccesary things
  virtual void handleInput()
      override; // Depending on the buttons pulsed, one action or another
  virtual void update() override; // Changes the logic state of the game
  virtual void render() override; // Draws everything
};
#endif // SCREENS_H
