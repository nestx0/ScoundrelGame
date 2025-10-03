#include "card.hpp"
#include "raylib.h"
#include <memory>
#include <string>
#include <unordered_map>

#ifndef TEXTURES_H
#define TEXTURES_H

struct TextureDeleter {
  void operator()(Texture2D *texture) {
    if (texture && texture->id > 0) {
      ::UnloadTexture(*texture);
    };

    delete texture;
  }
};

class TextureManager {
private:
  std::unordered_map<std::string, std::unique_ptr<Texture2D, TextureDeleter>>
      _textures;

public:
  TextureManager();
  ~TextureManager();
  /*
   * @brief Gets a Texture2D object given a name, usually it is card.toString()
   */
  Texture2D *getTexture(const std::string &id) const;
  /*
   * @brief Unloads from memory all loaded textures
   */
  void unloadAllTextures();
};

#endif // TEXTURES_H
