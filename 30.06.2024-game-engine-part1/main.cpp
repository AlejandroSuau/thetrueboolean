#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {

    // 1. Inicializar SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    // 2. Crear una ventana
    SDL_Window* window = SDL_CreateWindow("SDL2 Test",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          800, 600,
                                          SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Error creating SDL window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // 3. Crear un renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Error creating SDL renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // 4. Bucle principal de eventos
    bool running = true;
    while (running) {
        // 4.1. Bucle de lectura de eventos
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // 4.2. Color de fondo y limpieza de pantalla.
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // 4.3. Establecemos el color del cuadrado, sus dimensiones y pintamos.
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_Rect r{100, 100, 50, 50};
        SDL_RenderDrawRect(renderer, &r);

        // 4.4. Presentamos el renderer
        SDL_RenderPresent(renderer);
    }

    // 5. Limpiamos y cerramos los recursos
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;    
}
