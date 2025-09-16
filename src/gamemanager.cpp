#include "../includes/gamemanager.hpp"

const Game &GameManager::getGame() const
{
    return _game;
}
Game &GameManager::getGame()
{
    return _game;
}
const ScreenManager &GameManager::getScreenManager() const
{
    return _screenManager;
}
ScreenManager &GameManager::getScreenManager()
{
    return _screenManager;
}
const TextureManager &GameManager::getTextureManager() const
{
    return _textureManager;
}
TextureManager &GameManager::getTextureManager()
{
    return _textureManager;
}