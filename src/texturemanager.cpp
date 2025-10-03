#include "../includes/texturemanager.hpp"
#include "../includes/deck.hpp"
#include <filesystem>
#include <memory>

namespace fs = std::filesystem;

TextureManager::TextureManager() {
  Deck deck;

  fs::path assetsDirectory = "assets/";

  for (int i = 0; i < deck.size(); i++) {
    std::string key = deck.at(i).toString();
    std::string route = deck.at(i).cardToRoute();

    Texture2D *heapTexture = new Texture2D;
    *heapTexture = LoadTexture(route.c_str());

    if (heapTexture->id <= 0) {
      TraceLog(LOG_WARNING, "TextureManager: Texture cannot be loaded: %s",
               route.c_str());
      delete heapTexture;
    } else {

      _textures[key] = std::unique_ptr<Texture2D, TextureDeleter>(heapTexture);
    }
  }
  // Load next textures, probably in the future with a loop
  std::string backRoute = "assets/cards/card_back.png";
  Texture2D backTexture = LoadTexture(backRoute.c_str());
  _textures["backCard"] =
      std::unique_ptr<Texture2D, TextureDeleter>(new Texture2D(backTexture));
}
TextureManager::~TextureManager() { unloadAllTextures(); }

Texture2D *TextureManager::getTexture(const std::string &id) const {
  return _textures.at(id).get();
}
void TextureManager::unloadAllTextures() { _textures.clear(); }
