#include "Engine.h"

Engine::Engine(std::string window_title, int window_width, int window_height)
    : is_running_(false)
    , window_(
        SDL_CreateWindow(window_title.c_str(), 
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               window_width,
                               window_height,
                               SDL_WINDOW_SHOWN),
        SDL_DestroyWindow)
    , renderer_(
        SDL_CreateRenderer(window_.get(), -1, SDL_RENDERER_ACCELERATED),
        SDL_DestroyRenderer)
    , game_(nullptr) {}

void Engine::Run(IGame& game) {
    game_ = &game;
    is_running_ = true;
    SDL_ShowWindow(window_.get());

    Uint64 last_frame_time = SDL_GetTicks64();

    while (is_running_) {
        Uint64 current_time = SDL_GetTicks64();
        float dt = static_cast<float>(current_time - last_frame_time) / 1000.f;
        last_frame_time = SDL_GetTicks64();

        HandleEvents();

        game_->Update(dt);

        Render();
    }
}

void Engine::Render() {
    SDL_RenderClear(renderer_.get());

    game_->Render();

    SDL_SetRenderDrawColor(renderer_.get(), 0, 0, 0, 255);
    SDL_RenderPresent(renderer_.get());
}

void Engine::HandleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            is_running_ = false;
        }
    }
}

TextureManager::IdTexturePair Engine::LoadTexture(std::string_view path) {
    return texture_manager_.Load(path, renderer_.get());
}

SDL_Texture* Engine::GetTexture(std::size_t id) const {
    return texture_manager_.GetTexture(id);
}

void Engine::RenderTexture(SDL_Texture* texture, const Rectangle& destination_rect) {
    SDL_Rect dest_rect{
        static_cast<int>(destination_rect.x), 
        static_cast<int>(destination_rect.y),
        static_cast<int>(destination_rect.w), 
        static_cast<int>(destination_rect.h)};

    SDL_RenderCopy(renderer_.get(), texture, nullptr, &dest_rect);
}

void Engine::RenderTexture(
    SDL_Texture* texture,
    const Rectangle& source_rect,
    const Rectangle& destination_rect) {
    SDL_Rect src_rect{
        static_cast<int>(source_rect.x), 
        static_cast<int>(source_rect.y),
        static_cast<int>(source_rect.w), 
        static_cast<int>(source_rect.h)};
    SDL_Rect dest_rect{
        static_cast<int>(destination_rect.x), 
        static_cast<int>(destination_rect.y),
        static_cast<int>(destination_rect.w), 
        static_cast<int>(destination_rect.h)};

    SDL_RenderCopy(renderer_.get(), texture, &src_rect, &dest_rect);
}
