#pragma once

#include "ObiektMapy.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

/**
 * @brief Klasa reprezentuj¹ca listê obiektów na mapie.
 */
class ListaObiektow {
private:
    int amountRandObjectMap; ///< Liczba losowo generowanych obiektów na mapie.

public:
    std::vector<ObiektMapy> objectList; ///< Lista obiektów.

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
     * @brief Tworzy listê obiektów na podstawie renderera.
     *
     * @param renderer WskaŸnik do renderera SDL.
     */
    void creatList(SDL_Renderer* renderer);

    /**
     * @brief Wyœwietla listê obiektów na ekranie za pomoc¹ renderera.
     *
     * @param renderer WskaŸnik do renderera SDL.
     */
    void printList(SDL_Renderer* renderer);

    /**
     * @brief Generuje losowo obiekty na mapie.
     */
    void randObjectMap();

    /**
     * @brief Ustawia liczbê losowo generowanych obiektów na mapie.
     *
     * @param newAmountRandObjectMap Nowa liczba obiektów do wygenerowania.
     */
    void setAmountRandObjectMap(int newAmountRandObjectMap);

    /**
     * @brief Pobiera liczbê losowo generowanych obiektów na mapie.
     *
     * @return Aktualna liczba obiektów do wygenerowania.
     */
    int getAmountRandObjectMap();
};
