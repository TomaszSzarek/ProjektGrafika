#pragma once
#ifndef Background_H
#define Background_H

#include <SDL.h>
#include "SDL_image.h"
#include "iostream"

/**
 * @brief Klasa reprezentuj�ca t�o w grze.
 */
class Background {
private:
    int x;                  ///< Wsp�rz�dna X t�a.
    int y;                  ///< Wsp�rz�dna Y t�a.
    int width;              ///< Szeroko�� t�a.
    int height;             ///< Wysoko�� t�a.
    SDL_Texture* texture;   ///< Tekstura t�a.

public:
    /**
     * @brief Konstruktor klasy Background, inicjalizuje t�o na podstawie podanej �cie�ki do obrazu.
     *
     * @param renderer Wska�nik do renderera SDL.
     * @param sciezkaObrazu �cie�ka do obrazu t�a.
     * @param x Wsp�rz�dna X, na kt�rej zostanie narysowane t�o.
     * @param y Wsp�rz�dna Y, na kt�rej zostanie narysowane t�o.
     */
    Background(SDL_Renderer* renderer, const char* sciezkaObrazu, int x, int y);

    /**
     * @brief Metoda zwracaj�ca szeroko�� t�a.
     *
     * @return Szeroko�� t�a.
     */
    int getWidth();

    /**
     * @brief Metoda zwracaj�ca wysoko�� t�a.
     *
     * @return Wysoko�� t�a.
     */
    int getHeight();

    /**
     * @brief Metoda renderuj�ca t�o na ekranie.
     *
     * @param renderer Wska�nik do renderera SDL.
     */
    void render(SDL_Renderer* renderer);

    /**
     * @brief Metoda zmieniaj�ca t�o na podstawie nowej �cie�ki do obrazu.
     *
     * @param renderer Wska�nik do renderera SDL.
     * @param nowasciezkaObrazu Nowa �cie�ka do obrazu t�a.
     */
    void setBackground(SDL_Renderer* renderer, const char* nowasciezkaObrazu);
};

#endif
