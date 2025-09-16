#include <unordered_map>
#include <string>
#include "raylib.h"
#include "card.hpp"

#ifndef TEXTURES_H
#define TEXTURES_H

class TextureManager
{
private:
    std::unordered_map<std::string, Texture2D> _textures;

public:
    TextureManager();
    ~TextureManager();
    /*
     * @brief Gets a Texture2D object given a name, usually it is card.toString()
     */
    Texture2D getTexture(const std::string &id) const;
    /*
     * @brief Unloads from memory all loaded textures
     */
    void unloadAllTextures();
};

#endif // TEXTURES_H