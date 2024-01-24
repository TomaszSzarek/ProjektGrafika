#include "healthbar.h"

HealthBar::HealthBar(SDL_Renderer* renderer, int x, int y, int width, int height)
    : renderer(renderer), x(x), y(y), width(width), height(height) {
    LoadTextures();
}

HealthBar::~HealthBar() {
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(foregroundTexture);
}

void HealthBar::Render(int currentHP, int maxHP) {
    SDL_Rect backgroundRect = { x, y, width, height };
    SDL_Rect foregroundRect = { x+3, y+3, static_cast<int>(width * (static_cast<double>(currentHP) / maxHP)-6), height-6 };

    SDL_RenderCopy(renderer, backgroundTexture, nullptr, &backgroundRect);
    SDL_RenderCopy(renderer, foregroundTexture, nullptr, &foregroundRect);
}

void HealthBar::LoadTextures() {
    backgroundTexture = LoadTexture("../image/healthbarBackground.png");
    foregroundTexture = LoadTexture("../image/healthbarForeground.png");
}

SDL_Texture* HealthBar::LoadTexture(const char* path) {
    SDL_Surface* surface = IMG_Load(path);
    if (surface == nullptr) {
        std::cerr << "Error loading image: " << IMG_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (texture == nullptr) {
        std::cerr << "Error creating texture: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    return texture;
}
