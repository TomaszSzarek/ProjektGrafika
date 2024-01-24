#pragma once
#ifndef ButtonList_H
#define ButtonList_H

#include <vector>
#include "Button.h"

/**
 * @brief Klasa reprezentuj¹ca listê przycisków w grze.
 */
class ButtonList {
public:
    std::vector<Button> buttonList; ///< Wektor przechowuj¹cy przyciski.

    /**
     * @brief Konstruktor klasy ButtonList, inicjalizuje pust¹ listê przycisków.
     */
    ButtonList();

    /**
     * @brief Metoda dodaj¹ca przycisk do listy przycisków.
     *
     * @param button Referencja do przycisku, który zostanie dodany do listy.
     */
    void addButton(Button& button);

    /**
     * @brief Metoda tworz¹ca listê przycisków na podstawie renderer'a.
     *
     * @param renderer WskaŸnik do renderera SDL, który bêdzie u¿ywany do wczytania tekstur przycisków.
     */
    void createList(SDL_Renderer* renderer);

    /**
     * @brief Metoda renderuj¹ca wszystkie przyciski na ekranie.
     *
     * @param renderer WskaŸnik do renderera SDL, który bêdzie u¿ywany do renderowania przycisków.
     */
    void printList(SDL_Renderer* renderer);

    /**
     * @brief Metoda sprawdzaj¹ca aktywnoœæ przycisków i aktualizuj¹ca ich wygl¹d.
     *
     * @param renderer WskaŸnik do renderera SDL, który bêdzie u¿ywany do renderowania przycisków.
     */
    void checkActive(SDL_Renderer* renderer);
};

#endif
