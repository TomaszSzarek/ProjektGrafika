#ifndef ObiektMapy_H
#define ObiektMapy_H

#include <SDL.h>
#include "SDL_image.h"
#include "iostream"
#include <string>

/**
 * @brief Klasa reprezentuj�ca obiekt na mapie.
 */
class ObiektMapy {
private:
    int id; ///< Unikalny identyfikator obiektu.
    int x; ///< Pozycja X obiektu.
    int y; ///< Pozycja Y obiektu.
    int width; ///< Szeroko�� obiektu.
    int height; ///< Wysoko�� obiektu.
    int centerX; ///< Pozycja X �rodka obiektu.
    int centerY; ///< Pozycja Y �rodka obiektu.
    float distance; ///< Odleg�o�� od innego punktu.

public:
    std::string name; ///< Nazwa obiektu.
    SDL_Texture* texture; ///< Tekstura obiektu.

    /**
     * @brief Konstruktor klasy ObiektMapy.
     *
     * @param renderer Wska�nik do renderera SDL.
     * @param sciezkaObrazu �cie�ka do pliku obrazu.
     * @param x Pozycja X obiektu.
     * @param y Pozycja Y obiektu.
     * @param name Nazwa obiektu.
     * @param id Unikalny identyfikator obiektu.
     */
    ObiektMapy(SDL_Renderer* renderer, const char* sciezkaObrazu, int x, int y, std::string name, int id);

    int getID();
    int getX() const;
    int getY()const;
    int getWidth() const;
    int getHeight();
    int getCenterX();
    int getCenterY();
    float getDistance() const;
    void setX(int newX);
    void setY(int newY);
    void setWidth(int newWidth);
    void setHeight(int newHeight);
    void setCenter();
    void setDistance(int protagonistX, int protagonistY);
    void render(SDL_Renderer* renderer)const;
};

#endif
