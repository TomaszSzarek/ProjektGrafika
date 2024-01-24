#pragma once
#ifndef Bot_H
#define Bot_H

#include <SDL.h>
#include "SDL_image.h"
#include "iostream"

/**
 * @brief Klasa reprezentuj¹ca obiekt typu bot w grze.
 */
class Bot {
private:
    int x;                  ///< Wspó³rzêdna X bota.
    int y;                  ///< Wspó³rzêdna Y bota.
    int width;              ///< Szerokoœæ obiektu bota.
    int height;             ///< Wysokoœæ obiektu bota.
    SDL_Texture* texture;   ///< Tekstura obiektu bota.

public:
    /**
     * @brief Konstruktor klasy Bot, inicjalizuje obiekt typu bot na podstawie podanej œcie¿ki do obrazu.
     *
     * @param renderer WskaŸnik do renderera SDL.
     * @param sciezkaObrazu Œcie¿ka do obrazu bota.
     * @param x Wspó³rzêdna X, na której zostanie narysowany bot.
     * @param y Wspó³rzêdna Y, na której zostanie narysowany bot.
     */
    Bot(SDL_Renderer* renderer, const char* sciezkaObrazu, int x, int y);

    /**
     * @brief Metoda zwracaj¹ca szerokoœæ obiektu bota.
     *
     * @return Szerokoœæ obiektu bota.
     */
    int getWidth();

    /**
     * @brief Metoda zwracaj¹ca wysokoœæ obiektu bota.
     *
     * @return Wysokoœæ obiektu bota.
     */
    int getHeight();

    /**
     * @brief Metoda renderuj¹ca obiekt bota na ekranie.
     *
     * @param renderer WskaŸnik do renderera SDL.
     */
    void render(SDL_Renderer* renderer);
};

#endif
