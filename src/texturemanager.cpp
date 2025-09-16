#include "../includes/texturemanager.hpp"
#include "../includes/deck.hpp"

TextureManager::TextureManager()
{
    Deck deck;
    for (int i = 0; i < deck.size(); i++)
    {
        _textures[deck.at(i).toString()] = LoadTexture(deck.at(i).cardToRoute().c_str());
    }

    // Then load all extra textures needed
}
TextureManager::~TextureManager()
{
    unloadAllTextures();
}
Texture2D TextureManager::getTexture(const std::string &id) const
{
    return _textures.at(id);
}
void TextureManager::unloadAllTextures()
{
    for (auto &it : _textures)
    {
        UnloadTexture(it.second);
    }
}