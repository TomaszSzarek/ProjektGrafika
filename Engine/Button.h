#pragma once
#ifndef Button_H
#define Button_H

#include <SDL.h>
#include "SDL_image.h"
#include "iostream"
#include <string>

/**
 * @brief Klasa reprezentuj¹ca przycisk w grze.
 */
class Button {
private:
    std::string name;       ///< Nazwa przycisku.
    bool active;            ///< Flaga aktywnoœci przycisku.
    int x;                  ///< Wspó³rzêdna X przycisku.
    int y;                  ///< Wspó³rzêdna Y przycisku.
    int width;              ///< Szerokoœæ przycisku.
    int height;             ///< Wysokoœæ przycisku.
    SDL_Texture* texture;   ///< Tekstura przycisku.
    int id;                 ///< Identyfikator przycisku.

public:
    /**
     * @brief Konstruktor klasy Button, inicjalizuje przycisk na podstawie podanej œcie¿ki do obrazu.
     *
     * @param renderer WskaŸnik do renderera SDL.
     * @param sciezkaObrazu Œcie¿ka do obrazu przycisku.
     * @param x Wspó³rzêdna X, na której zostanie narysowany przycisk.
     * @param y Wspó³rzêdna Y, na której zostanie narysowany przycisk.
     * @param name Nazwa przycisku.
     * @param active Flaga aktywnoœci przycisku.
     * @param id Identyfikator przycisku.
     */
    Button(SDL_Renderer* renderer, const char* sciezkaObrazu, int x, int y, std::string name, bool active, int id);

    /**
     * @brief Metoda zwracaj¹ca stan aktywnoœci przycisku.
     *
     * @return True, jeœli przycisk jest aktywny; False w przeciwnym razie.
     */
    bool getActive();

    /**
     * @brief Metoda renderuj¹ca przycisk na ekranie.
     *
     * @param renderer WskaŸnik do renderera SDL.
     */
    void render(SDL_Renderer* renderer);

    /**
     * @brief Metoda zmieniaj¹ca teksturê przycisku na now¹ na podstawie podanej œcie¿ki.
     *
     * @param renderer WskaŸnik do renderera SDL.
     * @param nowasciezkaObrazu Œcie¿ka do nowej tekstury przycisku.
     */
    void setButton(SDL_Renderer* renderer, const char* nowasciezkaObrazu);

    /**
     * @brief Metoda ustawiaj¹ca stan aktywnoœci przycisku.
     *
     * @param newActive Nowy stan aktywnoœci przycisku.
     */
    void setActive(bool newActive);

    /**
     * @brief Metoda zwracaj¹ca identyfikator przycisku.
     *
     * @return Identyfikator przycisku.
     */
    int getID();
};

#endif
