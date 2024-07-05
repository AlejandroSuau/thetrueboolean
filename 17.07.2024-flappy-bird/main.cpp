#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <array>

#include "src/Engine.h"
#include "src/IGame.h"
#include "src/TextureManager.h"

class MyGame : public IGame {
public:
    MyGame() : engine_("SDL Test", 800, 600) {}

    void Start() override {
        LoadTextures();
        engine_.Run(*this);
    }

    void LoadTextures() {
        for (std::size_t i = 0; i < bird_textures_.size(); ++i) {
            bird_textures_[i] = engine_.LoadTexture("assets/bird-" + std::to_string(i) + ".png");
        }
    }

    void Update(float dt) override {
        elapsed_time_ += dt;
        if (elapsed_time_ >= 0.25f) {
            active_texture_index_ = ++active_texture_index_ % bird_textures_.size();
            elapsed_time_ = 0;
        }
    }

    void Render() override {
        auto* bird_texture = bird_textures_[active_texture_index_].second;
        Rectangle source_rect {0.f, 0.f, 34.f, 24.f};
        Rectangle destination_rect {50.f, 50.f, 68.f, 48.f};
        engine_.RenderTexture(bird_texture, source_rect, destination_rect);
    }

private:
    Engine engine_;
    std::array<TextureManager::IdTexturePair, 3> bird_textures_;
    std::size_t active_texture_index_{0};
    float elapsed_time_{0.f};
};



int main(int argc, char* argv[]) {
    MyGame my_game;
    my_game.Start();

    return 0;    
}
