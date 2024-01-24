/**
 * @brief Klasa reprezentuj�ca t�o w grze.
 */
#include "Background.h"

/**
     * @brief Konstruktor klasy Background, inicjalizuje t�o na podstawie podanej �cie�ki do obrazu.
     *
     * @param renderer Wska�nik do renderera SDL.
     * @param sciezkaObrazu �cie�ka do obrazu t�a.
     * @param x Wsp�rz�dna X, na kt�rej zostanie narysowane t�o.
     * @param y Wsp�rz�dna Y, na kt�rej zostanie narysowane t�o.
     */
Background::Background(SDL_Renderer* renderer, const char* sciezkaObrazu, int poczatkoweX, int poczatkoweY)
    : x(poczatkoweX), y(poczatkoweY), width(), height(), texture(nullptr) {
    SDL_Surface* surface = IMG_Load(sciezkaObrazu);
    if (surface == nullptr) {
        std::cerr << "B��d podczas wczytywania obrazu: " << SDL_GetError() << std::endl;
        return;
    }
    else {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (texture == nullptr) {
            std::cerr << "B��d podczas tworzenia tekstury: " << SDL_GetError() << std::endl;
            return;
        }
        width = surface->w;
        height = surface->h;

        SDL_FreeSurface(surface);
    }
}

/**
     * @brief Metoda zwracaj�ca szeroko�� t�a.
     *
     * @return Szeroko�� t�a.
     */
int Background::getWidth() { return width; }
    /**
     * @brief Metoda zwracaj�ca wysoko�� t�a.
     *
     * @return Wysoko�� t�a.
     */

int Background::getHeight() { return height; }
/**
     * @brief Metoda renderuj�ca t�o na ekranie.
     *
     * @param renderer Wska�nik do renderera SDL.
     */
void Background::render(SDL_Renderer* renderer) {
    SDL_Rect destinationRect = { x, y, width, height };
    SDL_RenderCopy(renderer, texture, nullptr, &destinationRect);
}

/**
     * @brief Metoda zmieniaj�ca t�o na podstawie nowej �cie�ki do obrazu.
     *
     * @param renderer Wska�nik do renderera SDL.
     * @param nowasciezkaObrazu Nowa �cie�ka do obrazu t�a.
     */

void Background::setBackground(SDL_Renderer* renderer, const char* nowasciezkaObrazu) {
    SDL_Surface* nowySurface = IMG_Load(nowasciezkaObrazu);
    if (nowySurface == nullptr) {
        std::cerr << "B��d podczas wczytywania nowego obrazu: " << SDL_GetError() << std::endl;
        return;
    }

    // Zwolnij poprzedni� tekstur�
    SDL_DestroyTexture(texture);

    // Utw�rz now� tekstur� z nowego obrazu
    texture = SDL_CreateTextureFromSurface(renderer, nowySurface);
    if (texture == nullptr) {
        std::cerr << "B��d podczas tworzenia nowej tekstury: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(nowySurface);
        return;
    }
    SDL_FreeSurface(nowySurface);
}
