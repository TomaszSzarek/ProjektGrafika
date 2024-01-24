#pragma once
#ifndef Button_H
#define Button_H

#include <SDL.h>
#include "SDL_image.h"
#include "iostream"
#include <string>

/**
 * @brief Klasa reprezentuj�ca przycisk w grze.
 */
class Button {
private:
    std::string name;       ///< Nazwa przycisku.
    bool active;            ///< Flaga aktywno�ci przycisku.
    int x;                  ///< Wsp�rz�dna X przycisku.
    int y;                  ///< Wsp�rz�dna Y przycisku.
    int width;              ///< Szeroko�� przycisku.
    int height;             ///< Wysoko�� przycisku.
    SDL_Texture* texture;   ///< Tekstura przycisku.
    int id;                 ///< Identyfikator przycisku.

public:
    /**
     * @brief Konstruktor klasy Button, inicjalizuje przycisk na podstawie podanej �cie�ki do obrazu.
     *
     * @param renderer Wska�nik do renderera SDL.
     * @param sciezkaObrazu �cie�ka do obrazu przycisku.
     * @param x Wsp�rz�dna X, na kt�rej zostanie narysowany przycisk.
     * @param y Wsp�rz�dna Y, na kt�rej zostanie narysowany przycisk.
     * @param name Nazwa przycisku.
     * @param active Flaga aktywno�ci przycisku.
     * @param id Identyfikator przycisku.
     */
    Button(SDL_Renderer* renderer, const char* sciezkaObrazu, int x, int y, std::string name, bool active, int id);

    /**
     * @brief Metoda zwracaj�ca stan aktywno�ci przycisku.
     *
     * @return True, je�li przycisk jest aktywny; False w przeciwnym razie.
     */
    bool getActive();

    /**
     * @brief Metoda renderuj�ca przycisk na ekranie.
     *
     * @param renderer Wska�nik do renderera SDL.
     */
    void render(SDL_Renderer* renderer);

    /**
     * @brief Metoda zmieniaj�ca tekstur� przycisku na now� na podstawie podanej �cie�ki.
     *
     * @param renderer Wska�nik do renderera SDL.
     * @param nowasciezkaObrazu �cie�ka do nowej tekstury przycisku.
     */
    void setButton(SDL_Renderer* renderer, const char* nowasciezkaObrazu);

    /**
     * @brief Metoda ustawiaj�ca stan aktywno�ci przycisku.
     *
     * @param newActive Nowy stan aktywno�ci przycisku.
     */
    void setActive(bool newActive);

    /**
     * @brief Metoda zwracaj�ca identyfikator przycisku.
     *
     * @return Identyfikator przycisku.
     */
    int getID();
};

#endif
