#ifndef PROTAGONIST_H
#define PROTAGONIST_H

#include <SDL.h>
#include "SDL_image.h"
#include "iostream"
#include <vector>
#include "ListaObiektow.h"

/**
 * @brief Klasa reprezentuj�ca protagonista w grze.
 */
class Protagonist {
private:
    int x; ///< Pozycja X protagonista.
    int y; ///< Pozycja Y protagonista.
    int width; ///< Szeroko�� protagonista.
    int height; ///< Wysoko�� protagonista.
    int CenterX; ///< Pozycja X �rodka protagonista.
    int CenterY; ///< Pozycja Y �rodka protagonista.
    int kierunek; ///< Kierunek poruszania si� protagonista (1=w, 2=s, 3=a, 4=d).
    int kolizjaW = 1; ///< Flagi kolizji w kierunku "w".
    int kolizjaS = 1; ///< Flagi kolizji w kierunku "s".
    int kolizjaA = 1; ///< Flagi kolizji w kierunku "a".
    int kolizjaD = 1; ///< Flagi kolizji w kierunku "d".
    int kolizjaNextLevel = 0; ///< Flaga kolizji z obszarem zmiany poziomu.
    int idObiektKolidujacego; ///< ID obiektu, z kt�rym protagonista koliduje.
    int killEnemy = 0; ///< Licznik pokonanych przeciwnik�w.
    const int speed = 10; ///< Szybko�� poruszania si� protagonista.
    SDL_Texture* texture; ///< Tekstura protagonista.

public:
    /**
 * @brief Pobiera pozycj� X protagonista.
 *
 * @return Pozycja X protagonista.
 */
    int getX();

    /**
     * @brief Pobiera pozycj� Y protagonista.
     *
     * @return Pozycja Y protagonista.
     */
    int getY();

    /**
     * @brief Pobiera szeroko�� protagonista.
     *
     * @return Szeroko�� protagonista.
     */
    int getWidth();

    /**
     * @brief Pobiera wysoko�� protagonista.
     *
     * @return Wysoko�� protagonista.
     */
    int getHeight();

    /**
     * @brief Pobiera pozycj� X �rodka protagonista.
     *
     * @return Pozycja X �rodka protagonista.
     */
    int getCenterX();

    /**
     * @brief Pobiera pozycj� Y �rodka protagonista.
     *
     * @return Pozycja Y �rodka protagonista.
     */
    int getCenterY();

    /**
     * @brief Pobiera kierunek poruszania si� protagonista.
     *
     * @return Kierunek poruszania si� protagonista (1=w, 2=s, 3=a, 4=d).
     */
    int getKierunek();

    /**
     * @brief Pobiera flagi kolizji w kierunku "w".
     *
     * @return Flagi kolizji w kierunku "w".
     */
    int getKolizjaW();

    /**
     * @brief Pobiera flagi kolizji w kierunku "s".
     *
     * @return Flagi kolizji w kierunku "s".
     */
    int getKolizjaS();

    /**
     * @brief Pobiera flagi kolizji w kierunku "a".
     *
     * @return Flagi kolizji w kierunku "a".
     */
    int getKolizjaA();

    /**
     * @brief Pobiera flagi kolizji w kierunku "d".
     *
     * @return Flagi kolizji w kierunku "d".
     */
    int getKolizjaD();

    /**
     * @brief Pobiera pr�dko�� poruszania si� protagonista.
     *
     * @return Pr�dko�� poruszania si� protagonista.
     */
    int getSpeed();

    /**
     * @brief Pobiera ID obiektu, z kt�rym protagonista koliduje.
     *
     * @return ID obiektu, z kt�rym protagonista koliduje.
     */
    int getIdObiektKolidujacego();

    /**
     * @brief Pobiera licznik pokonanych przeciwnik�w.
     *
     * @return Licznik pokonanych przeciwnik�w.
     */
    int getKillEnemy();

    /**
     * @brief Pobiera flag� kolizji z obszarem zmiany poziomu.
     *
     * @return Flaga kolizji z obszarem zmiany poziomu.
     */
    int getKolizjaNextLevel();

    /**
     * @brief Ustawia �rodek protagonista na jego aktualnej pozycji.
     */
    void setCenter();

    /**
     * @brief Ustawia pozycj� X protagonista.
     *
     * @param newX Nowa pozycja X protagonista.
     */
    void setX(int newX);

    /**
     * @brief Ustawia pozycj� Y protagonista.
     *
     * @param newY Nowa pozycja Y protagonista.
     */
    void setY(int newY);

    /**
     * @brief Ustawia szeroko�� protagonista.
     *
     * @param newWidth Nowa szeroko�� protagonista.
     */
    void setWidth(int newWidth);

    /**
     * @brief Ustawia wysoko�� protagonista.
     *
     * @param newHeight Nowa wysoko�� protagonista.
     */
    void setHeight(int newHeight);

    /**
     * @brief Ustawia kierunek poruszania si� protagonista.
     *
     * @param newKierunek Nowy kierunek poruszania si� protagonista (1=w, 2=s, 3=a, 4=d).
     */
    void setKierunek(int newKierunek);

    /**
     * @brief Ustawia flagi kolizji w kierunku "w".
     *
     * @param newKolizjaW Nowe flagi kolizji w kierunku "w".
     */
    void setKolizjaW(int newKolizjaW);

    /**
     * @brief Ustawia flagi kolizji w kierunku "s".
     *
     * @param newKolizjaS Nowe flagi kolizji w kierunku "s".
     */
    void setKolizjaS(int newKolizjaS);

    /**
     * @brief Ustawia flagi kolizji w kierunku "a".
     *
     * @param newKolizjaA Nowe flagi kolizji w kierunku "a".
     */
    void setKolizjaA(int newKolizjaA);

    /**
     * @brief Ustawia flagi kolizji w kierunku "d".
     *
     * @param newKolizjaD Nowe flagi kolizji w kierunku "d".
     */
    void setKolizjaD(int newKolizjaD);

    /**
     * @brief Ustawia ID obiektu, z kt�rym protagonist koliduje.
     *
     * @param newID Nowe ID obiektu koliduj�cego.
     */
    void setIdObiektKolidujacego(int newID);

    /**
     * @brief Ustawia licznik pokonanych przeciwnik�w.
     *
     * @param newKillEnemy Nowa warto�� licznika pokonanych przeciwnik�w.
     */
    void setKillEnemy(int newKillEnemy);

    /**
     * @brief Ustawia flag� kolizji z obszarem zmiany poziomu.
     *
     * @param newKolizjaNextLevel Nowa warto�� flagi kolizji z obszarem zmiany poziomu.
     */
    void setKolizjaNextLevel(int newKolizjaNextLevel);

    /**
     * @brief Ustawia obraz protagonisty.
     *
     * @param renderer Wska�nik do renderera SDL.
     * @param nowaSciezkaObrazu �cie�ka do nowego pliku obrazu.
     */
    void setObraz(SDL_Renderer* renderer, const char* nowaSciezkaObrazu);

    /**
     * @brief Obs�uguje kolizje protagonisty z obiektami na mapie.
     *
     * @param objectList Lista obiekt�w na mapie.
     */
    void kolizja(std::vector<ObiektMapy>& objectList);

    /**
     * @brief Konstruktor klasy Protagonist.
     *
     * @param renderer Wska�nik do renderera SDL.
     * @param sciezkaObrazuProtagonisty �cie�ka do pliku obrazu protagonisty.
     * @param x Pozycja X protagonisty.
     * @param y Pozycja Y protagonisty.
     */
    Protagonist(SDL_Renderer* renderer, const char* sciezkaObrazuProtagonisty, int x, int y);

    /**
     * @brief Metoda renderuj�ca protagonist� na ekranie.
     *
     * @param renderer Wska�nik do renderera SDL.
     */
    void render(SDL_Renderer* renderer);
};
#endif