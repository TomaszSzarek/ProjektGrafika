#pragma once

#include "ObiektMapy.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

/**
 * @brief Klasa reprezentuj�ca list� obiekt�w na mapie.
 */
class ListaObiektow {
private:
    int amountRandObjectMap; ///< Liczba losowo generowanych obiekt�w na mapie.

public:
    std::vector<ObiektMapy> objectList; ///< Lista obiekt�w.

    /**
     * @brief Konstruktor klasy ListaObiektow.
     */
    ListaObiektow();

    /**
     * @brief Dodaje obiekt do listy.
     *
     * @param obiektMapy Obiekt do dodania do listy.
     */
    void addObiekt(ObiektMapy& obiektMapy);

    /**
     * @brief Tworzy list� obiekt�w na podstawie renderera.
     *
     * @param renderer Wska�nik do renderera SDL.
     */
    void creatList(SDL_Renderer* renderer);

    /**
     * @brief Wy�wietla list� obiekt�w na ekranie za pomoc� renderera.
     *
     * @param renderer Wska�nik do renderera SDL.
     */
    void printList(SDL_Renderer* renderer);

    /**
     * @brief Generuje losowo obiekty na mapie.
     */
    void randObjectMap();

    /**
     * @brief Ustawia liczb� losowo generowanych obiekt�w na mapie.
     *
     * @param newAmountRandObjectMap Nowa liczba obiekt�w do wygenerowania.
     */
    void setAmountRandObjectMap(int newAmountRandObjectMap);

    /**
     * @brief Pobiera liczb� losowo generowanych obiekt�w na mapie.
     *
     * @return Aktualna liczba obiekt�w do wygenerowania.
     */
    int getAmountRandObjectMap();
};
