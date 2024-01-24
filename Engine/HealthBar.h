#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

/**
 * @brief Klasa reprezentuj¹ca pasek zdrowia.
 */
class HealthBar {
public:
    /**
     * @brief Konstruktor klasy HealthBar.
     *
     * @param renderer WskaŸnik do renderera SDL.
     * @param x Pozycja X paska zdrowia na ekranie.
     * @param y Pozycja Y paska zdrowia na ekranie.
     * @param width Szerokoœæ paska zdrowia.
     * @param height Wysokoœæ paska zdrowia.
     */
    HealthBar(SDL_Renderer* renderer, int x, int y, int width, int height);

    /**
     * @brief Destruktor klasy HealthBar.
     */
    ~HealthBar();

    /**
     * @brief Metoda do renderowania paska zdrowia.
     *
     * @param currentHP Aktualna iloœæ punktów ¿ycia.
     * @param maxHP Maksymalna iloœæ punktów ¿ycia.
     */
    void Render(int currentHP, int maxHP);

private:
    SDL_Renderer* renderer;         ///< WskaŸnik do renderera SDL.
    int x, y, width, height;        ///< Parametry paska zdrowia.
    SDL_Texture* backgroundTexture; ///< Tekstura t³a paska zdrowia.
    SDL_Texture* foregroundTexture; ///< Tekstura przodu paska zdrowia.

    /**
     * @brief Metoda do wczytywania tekstur.
     */
    void LoadTextures();

    /**
     * @brief Metoda do ³adowania pojedynczej tekstury z pliku.
     *
     * @param path Œcie¿ka do pliku z tekstur¹.
     * @return WskaŸnik do za³adowanej tekstury.
     */
    SDL_Texture* LoadTexture(const char* path);
};
