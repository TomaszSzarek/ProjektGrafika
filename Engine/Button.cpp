#include "Button.h"


Button::Button(SDL_Renderer* renderer, const char* sciezkaObrazu, int poczatkoweX, int poczatkoweY, std::string name, bool active, int id)
    : x(poczatkoweX), y(poczatkoweY), width(), height(), texture(nullptr), name(name), active(active), id(id) {
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


bool Button::getActive() { return active; }


void Button::render(SDL_Renderer* renderer) {
    SDL_Rect destinationRect = { x, y, width, height };
    SDL_RenderCopy(renderer, texture, nullptr, &destinationRect);
}


void Button::setButton(SDL_Renderer* renderer, const char* nowasciezkaObrazu) {
    SDL_Surface* nowySurface = IMG_Load(nowasciezkaObrazu);
    if (nowySurface == nullptr) {
        std::cerr << "B³¹d podczas wczytywania nowego obrazu: " << SDL_GetError() << std::endl;
        return;
    }

    // Zwolnij poprzedni¹ teksturê
    SDL_DestroyTexture(texture);

    // Utwórz now¹ teksturê z nowego obrazu
    texture = SDL_CreateTextureFromSurface(renderer, nowySurface);
    if (texture == nullptr) {
        std::cerr << "B³¹d podczas tworzenia nowej tekstury: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(nowySurface);
        return;
    }
    SDL_FreeSurface(nowySurface);
}


void Button::setActive(bool newActive) {
    active = newActive;
}


int Button::getID() { return id; }
