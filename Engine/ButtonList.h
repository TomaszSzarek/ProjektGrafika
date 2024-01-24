#pragma once
#ifndef ButtonList_H
#define ButtonList_H

#include <vector>
#include "Button.h"

/**
 * @brief Klasa reprezentuj�ca list� przycisk�w w grze.
 */
class ButtonList {
public:
    std::vector<Button> buttonList; ///< Wektor przechowuj�cy przyciski.

    /**
     * @brief Konstruktor klasy ButtonList, inicjalizuje pust� list� przycisk�w.
     */
    ButtonList();

    /**
     * @brief Metoda dodaj�ca przycisk do listy przycisk�w.
     *
     * @param button Referencja do przycisku, kt�ry zostanie dodany do listy.
     */
    void addButton(Button& button);

    /**
     * @brief Metoda tworz�ca list� przycisk�w na podstawie renderer'a.
     *
     * @param renderer Wska�nik do renderera SDL, kt�ry b�dzie u�ywany do wczytania tekstur przycisk�w.
     */
    void createList(SDL_Renderer* renderer);

    /**
     * @brief Metoda renderuj�ca wszystkie przyciski na ekranie.
     *
     * @param renderer Wska�nik do renderera SDL, kt�ry b�dzie u�ywany do renderowania przycisk�w.
     */
    void printList(SDL_Renderer* renderer);

    /**
     * @brief Metoda sprawdzaj�ca aktywno�� przycisk�w i aktualizuj�ca ich wygl�d.
     *
     * @param renderer Wska�nik do renderera SDL, kt�ry b�dzie u�ywany do renderowania przycisk�w.
     */
    void checkActive(SDL_Renderer* renderer);
};

#endif
