#pragma once
#ifndef Bot_H
#define Bot_H

#include <SDL.h>
#include "SDL_image.h"
#include "iostream"

/**
 * @brief Klasa reprezentuj�ca obiekt typu bot w grze.
 */
class Bot {
private:
    int x;                  ///< Wsp�rz�dna X bota.
    int y;                  ///< Wsp�rz�dna Y bota.
    int width;              ///< Szeroko�� obiektu bota.
    int height;             ///< Wysoko�� obiektu bota.
    SDL_Texture* texture;   ///< Tekstura obiektu bota.

public:
    /**
     * @brief Konstruktor klasy Bot, inicjalizuje obiekt typu bot na podstawie podanej �cie�ki do obrazu.
     *
     * @param renderer Wska�nik do renderera SDL.
     * @param sciezkaObrazu �cie�ka do obrazu bota.
     * @param x Wsp�rz�dna X, na kt�rej zostanie narysowany bot.
     * @param y Wsp�rz�dna Y, na kt�rej zostanie narysowany bot.
     */
    Bot(SDL_Renderer* renderer, const char* sciezkaObrazu, int x, int y);

    /**
     * @brief Metoda zwracaj�ca szeroko�� obiektu bota.
     *
     * @return Szeroko�� obiektu bota.
     */
    int getWidth();

    /**
     * @brief Metoda zwracaj�ca wysoko�� obiektu bota.
     *
     * @return Wysoko�� obiektu bota.
     */
    int getHeight();

    /**
     * @brief Metoda renderuj�ca obiekt bota na ekranie.
     *
     * @param renderer Wska�nik do renderera SDL.
     */
    void render(SDL_Renderer* renderer);
};

#endif
