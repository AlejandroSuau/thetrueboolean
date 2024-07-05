#include "SdlInitializer.h"

#include <string>
#include <stdexcept>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SdlInitializer::SdlInitializer() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) != 0) {
        throw std::runtime_error(
            std::string("Unable to initialize SDL: ") + SDL_GetError());
    }

    if (IMG_Init(IMG_INIT_PNG) == 0) {
        throw std::runtime_error(
            std::string("Unable to initialize SDL_Image: ") + SDL_GetError());
    }
}

SdlInitializer::~SdlInitializer() {
    IMG_Quit();
    SDL_Quit();
}
