#include "Bot.h"


Bot::Bot(SDL_Renderer* renderer, const char* sciezkaObrazu, int poczatkoweX, int poczatkoweY)
    : x(poczatkoweX), y(poczatkoweY), width(), height(), texture(nullptr) {
    SDL_Surface* surface = IMG_Load(sciezkaObrazu);
    if (surface == nullptr) {
        std::cerr << "B³¹d podczas wczytywania obrazu: " << SDL_GetError() << std::endl;
        return;
    }
    else {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (texture == nullptr) {
            std::cerr << "B³¹d podczas tworzenia tekstury: " << SDL_GetError() << std::endl;
            return;
        }
        width = surface->w;
        height = surface->h;

        SDL_FreeSurface(surface);
    }
}

int Bot::getWidth() { return width; }


int Bot::getHeight() { return height; }


void Bot::render(SDL_Renderer* renderer) {
    SDL_Rect destinationRect = { x, y, width, height };
    SDL_RenderCopy(renderer, texture, nullptr, &destinationRect);
}
