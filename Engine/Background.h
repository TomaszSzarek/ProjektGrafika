#pragma once
#ifndef Background_H
#define Background_H

#include <SDL.h>
#include "SDL_image.h"
#include "iostream"

/**
 * @brief Klasa reprezentuj¹ca t³o w grze.
 */
class Background {
private:
    int x;                  ///< Wspó³rzêdna X t³a.
    int y;                  ///< Wspó³rzêdna Y t³a.
    int width;              ///< Szerokoœæ t³a.
    int height;             ///< Wysokoœæ t³a.
    SDL_Texture* texture;   ///< Tekstura t³a.

public:
    /**
     * @brief Konstruktor klasy Background, inicjalizuje t³o na podstawie podanej œcie¿ki do obrazu.
     *
     * @param renderer WskaŸnik do renderera SDL.
     * @param sciezkaObrazu Œcie¿ka do obrazu t³a.
     * @param x Wspó³rzêdna X, na której zostanie narysowane t³o.
     * @param y Wspó³rzêdna Y, na której zostanie narysowane t³o.
     */
    Background(SDL_Renderer* renderer, const char* sciezkaObrazu, int x, int y);

    /**
     * @brief Metoda zwracaj¹ca szerokoœæ t³a.
     *
     * @return Szerokoœæ t³a.
     */
    int getWidth();

    /**
     * @brief Metoda zwracaj¹ca wysokoœæ t³a.
     *
     * @return Wysokoœæ t³a.
     */
    int getHeight();

    /**
     * @brief Metoda renderuj¹ca t³o na ekranie.
     *
     * @param renderer WskaŸnik do renderera SDL.
     */
    void render(SDL_Renderer* renderer);

    /**
     * @brief Metoda zmieniaj¹ca t³o na podstawie nowej œcie¿ki do obrazu.
     *
     * @param renderer WskaŸnik do renderera SDL.
     * @param nowasciezkaObrazu Nowa œcie¿ka do obrazu t³a.
     */
    void setBackground(SDL_Renderer* renderer, const char* nowasciezkaObrazu);
};

#endif
