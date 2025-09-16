#include "../includes/screenmanager.hpp"

void ScreenManager::pushScreen(std::unique_ptr<BaseScreen> newScreen)
{
    _screens.push(std::move(newScreen));
}
void ScreenManager::popScreen()
{
    if (!_screens.empty())
        _screens.pop();
}
void ScreenManager::changeScreen(std::unique_ptr<BaseScreen> newScreen)
{
    clearAllScreens();
    pushScreen(std::move(newScreen));
}
void ScreenManager::clearAllScreens()
{
    while (!_screens.empty())
    {
        _screens.pop();
    }
}
BaseScreen *ScreenManager::getScreen() const
{
    return _screens.top().get();
}
bool ScreenManager::isEmpty() const
{
    return _screens.empty();
}
void ScreenManager::handleInput()
{
    _screens.top()->handleInput();
}
void ScreenManager::render()
{
    _screens.top()->render();
}