#include "TextureManager.h"

std::size_t TextureManager::sNextId = 0;

TextureManager::IdTexturePair TextureManager::Load(std::string_view filename, SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load(filename.data());
    if (!surface) {
        SDL_Log("Failed to load surface: %s, %s", filename.data(), SDL_GetError());
        return {0, nullptr};
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture) {
        SDL_Log("Failed to create texture: %s, %s", filename.data(), SDL_GetError());
        return {0, nullptr};
    }

    std::size_t current_id = sNextId++;
    textures_[current_id] = TexturePtr(texture, SDL_DestroyTexture);
    return {current_id, texture};
}

SDL_Texture* TextureManager::GetTexture(std::size_t id) const {
    auto it = textures_.find(id);
    if (it == textures_.end()) {
        SDL_Log("Texture with ID %zu not found", id);
        return nullptr;
    }

    return it->second.get();
}
