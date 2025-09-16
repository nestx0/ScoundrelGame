#include "game.hpp"
#include "texturemanager.hpp"
#include "screenmanager.hpp"

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

class GameManager
{
private:
    Game &_game;
    ScreenManager _screenManager;
    TextureManager _textureManager;

public:
    GameManager(Game &game) : _game(game) {};

    const Game &getGame() const;
    const ScreenManager &getScreenManager() const;
    const TextureManager &getTextureManager() const;

    Game &getGame();
    ScreenManager &getScreenManager();
    TextureManager &getTextureManager();
};

#endif