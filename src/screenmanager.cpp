#include "../includes/screenmanager.hpp"

void ScreenManager::pushScreen(std::unique_ptr<BaseScreen> newScreen) {
  if (newScreen) {
    newScreen->setContext(_engineContext);
    newScreen->init();
    _screens.push(std::move(newScreen));
  } else {
    TraceLog(LOG_WARNING, "NULL SCREEN");
  }
}
void ScreenManager::popScreen() {
  if (!_screens.empty())
    _screens.pop();
}
void ScreenManager::changeScreen(std::unique_ptr<BaseScreen> newScreen) {
  clearAllScreens();
  pushScreen(std::move(newScreen));
}
void ScreenManager::clearAllScreens() {
  while (!_screens.empty()) {
    _screens.pop();
  }
}
BaseScreen *ScreenManager::getScreen() const {
  return _screens.top() ? _screens.top().get() : nullptr;
}
bool ScreenManager::isEmpty() const { return _screens.empty(); }
void ScreenManager::handleInput() {
  _screens.top() ? _screens.top()->handleInput()
                 : TraceLog(LOG_WARNING, "Couldn't handle input");
}
void ScreenManager::render() {
  _screens.top() ? _screens.top()->render()
                 : TraceLog(LOG_WARNING, "Couldn't render");
}

void ScreenManager::update() {
  _screens.top() ? _screens.top()->update()
                 : TraceLog(LOG_WARNING, "Couldn't update");
}

void ScreenManager::run() {
  handleInput();
  update();
  render();
}
