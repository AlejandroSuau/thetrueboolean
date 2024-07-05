#pragma once

#include <string>
#include <string_view>

#include "SdlInitializer.h"
#include "TextureManager.h"
#include "Rectangle.h"
#include "IGame.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Engine {
public:
    Engine(std::string window_title, int window_width, int window_height);

    void Run(IGame& game);
    void Render();

    void RenderTexture(SDL_Texture* texture, const Rectangle& source_rect, const Rectangle& destination_rect);
    void RenderTexture(SDL_Texture* texture, const Rectangle& destination_rect);
    
    TextureManager::IdTexturePair LoadTexture(std::string_view path);
    SDL_Texture* GetTexture(std::size_t id) const;

private:
    SdlInitializer sdl_initializer_;
    TextureManager texture_manager_;
    bool is_running_;

    using WindowDestructor = std::function<void(SDL_Window*)>;
    std::unique_ptr<SDL_Window, WindowDestructor> window_;
    
    using RendererDestructor = std::function<void(SDL_Renderer*)>;
    std::unique_ptr<SDL_Renderer, RendererDestructor> renderer_;

    IGame* game_;

    void HandleEvents();
};
