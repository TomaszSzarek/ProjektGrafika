/**
 * @brief Klasa reprezentuj¹ca t³o w grze.
 */
#include "Background.h"

/**
     * @brief Konstruktor klasy Background, inicjalizuje t³o na podstawie podanej œcie¿ki do obrazu.
     *
     * @param renderer WskaŸnik do renderera SDL.
     * @param sciezkaObrazu Œcie¿ka do obrazu t³a.
     * @param x Wspó³rzêdna X, na której zostanie narysowane t³o.
     * @param y Wspó³rzêdna Y, na której zostanie narysowane t³o.
     */
Background::Background(SDL_Renderer* renderer, const char* sciezkaObrazu, int poczatkoweX, int poczatkoweY)
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

/**
     * @brief Metoda zwracaj¹ca szerokoœæ t³a.
     *
     * @return Szerokoœæ t³a.
     */
int Background::getWidth() { return width; }
    /**
     * @brief Metoda zwracaj¹ca wysokoœæ t³a.
     *
     * @return Wysokoœæ t³a.
     */

int Background::getHeight() { return height; }
/**
     * @brief Metoda renderuj¹ca t³o na ekranie.
     *
     * @param renderer WskaŸnik do renderera SDL.
     */
void Background::render(SDL_Renderer* renderer) {
    SDL_Rect destinationRect = { x, y, width, height };
    SDL_RenderCopy(renderer, texture, nullptr, &destinationRect);
}

/**
     * @brief Metoda zmieniaj¹ca t³o na podstawie nowej œcie¿ki do obrazu.
     *
     * @param renderer WskaŸnik do renderera SDL.
     * @param nowasciezkaObrazu Nowa œcie¿ka do obrazu t³a.
     */

void Background::setBackground(SDL_Renderer* renderer, const char* nowasciezkaObrazu) {
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
