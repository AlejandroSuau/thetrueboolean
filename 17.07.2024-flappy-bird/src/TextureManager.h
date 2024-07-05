#pragma once

#include <unordered_map>
#include <memory>
#include <string_view>
#include <functional>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureManager {
public:
    using IdTexturePair = std::pair<std::size_t, SDL_Texture*>;
    TextureManager::IdTexturePair Load(std::string_view filename, SDL_Renderer* renderer);
    SDL_Texture* GetTexture(std::size_t id) const;

private:
    using TextureDeleter = std::function<void(SDL_Texture*)>;
    using TexturePtr = std::unique_ptr<SDL_Texture, TextureDeleter>;
    std::unordered_map<std::size_t, TexturePtr> textures_;
    static std::size_t sNextId;
};
