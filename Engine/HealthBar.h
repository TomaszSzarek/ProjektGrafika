#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

/**
 * @brief Klasa reprezentuj�ca pasek zdrowia.
 */
class HealthBar {
public:
    /**
     * @brief Konstruktor klasy HealthBar.
     *
     * @param renderer Wska�nik do renderera SDL.
     * @param x Pozycja X paska zdrowia na ekranie.
     * @param y Pozycja Y paska zdrowia na ekranie.
     * @param width Szeroko�� paska zdrowia.
     * @param height Wysoko�� paska zdrowia.
     */
    HealthBar(SDL_Renderer* renderer, int x, int y, int width, int height);

    /**
     * @brief Destruktor klasy HealthBar.
     */
    ~HealthBar();

    /**
     * @brief Metoda do renderowania paska zdrowia.
     *
     * @param currentHP Aktualna ilo�� punkt�w �ycia.
     * @param maxHP Maksymalna ilo�� punkt�w �ycia.
     */
    void Render(int currentHP, int maxHP);

private:
    SDL_Renderer* renderer;         ///< Wska�nik do renderera SDL.
    int x, y, width, height;        ///< Parametry paska zdrowia.
    SDL_Texture* backgroundTexture; ///< Tekstura t�a paska zdrowia.
    SDL_Texture* foregroundTexture; ///< Tekstura przodu paska zdrowia.

    /**
     * @brief Metoda do wczytywania tekstur.
     */
    void LoadTextures();

    /**
     * @brief Metoda do �adowania pojedynczej tekstury z pliku.
     *
     * @param path �cie�ka do pliku z tekstur�.
     * @return Wska�nik do za�adowanej tekstury.
     */
    SDL_Texture* LoadTexture(const char* path);
};
