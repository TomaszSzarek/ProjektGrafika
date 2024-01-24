#ifndef PROTAGONIST_H
#define PROTAGONIST_H

#include <SDL.h>
#include "SDL_image.h"
#include "iostream"
#include <vector>
#include "ListaObiektow.h"

/**
 * @brief Klasa reprezentujπca protagonista w grze.
 */
class Protagonist {
private:
    int x; ///< Pozycja X protagonista.
    int y; ///< Pozycja Y protagonista.
    int width; ///< SzerokoúÊ protagonista.
    int height; ///< WysokoúÊ protagonista.
    int CenterX; ///< Pozycja X úrodka protagonista.
    int CenterY; ///< Pozycja Y úrodka protagonista.
    int kierunek; ///< Kierunek poruszania siÍ protagonista (1=w, 2=s, 3=a, 4=d).
    int kolizjaW = 1; ///< Flagi kolizji w kierunku "w".
    int kolizjaS = 1; ///< Flagi kolizji w kierunku "s".
    int kolizjaA = 1; ///< Flagi kolizji w kierunku "a".
    int kolizjaD = 1; ///< Flagi kolizji w kierunku "d".
    int kolizjaNextLevel = 0; ///< Flaga kolizji z obszarem zmiany poziomu.
    int idObiektKolidujacego; ///< ID obiektu, z ktÛrym protagonista koliduje.
    int killEnemy = 0; ///< Licznik pokonanych przeciwnikÛw.
    const int speed = 10; ///< SzybkoúÊ poruszania siÍ protagonista.
    SDL_Texture* texture; ///< Tekstura protagonista.

public:
    /**
 * @brief Pobiera pozycjÍ X protagonista.
 *
 * @return Pozycja X protagonista.
 */
    int getX();

    /**
     * @brief Pobiera pozycjÍ Y protagonista.
     *
     * @return Pozycja Y protagonista.
     */
    int getY();

    /**
     * @brief Pobiera szerokoúÊ protagonista.
     *
     * @return SzerokoúÊ protagonista.
     */
    int getWidth();

    /**
     * @brief Pobiera wysokoúÊ protagonista.
     *
     * @return WysokoúÊ protagonista.
     */
    int getHeight();

    /**
     * @brief Pobiera pozycjÍ X úrodka protagonista.
     *
     * @return Pozycja X úrodka protagonista.
     */
    int getCenterX();

    /**
     * @brief Pobiera pozycjÍ Y úrodka protagonista.
     *
     * @return Pozycja Y úrodka protagonista.
     */
    int getCenterY();

    /**
     * @brief Pobiera kierunek poruszania siÍ protagonista.
     *
     * @return Kierunek poruszania siÍ protagonista (1=w, 2=s, 3=a, 4=d).
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
     * @brief Pobiera prÍdkoúÊ poruszania siÍ protagonista.
     *
     * @return PrÍdkoúÊ poruszania siÍ protagonista.
     */
    int getSpeed();

    /**
     * @brief Pobiera ID obiektu, z ktÛrym protagonista koliduje.
     *
     * @return ID obiektu, z ktÛrym protagonista koliduje.
     */
    int getIdObiektKolidujacego();

    /**
     * @brief Pobiera licznik pokonanych przeciwnikÛw.
     *
     * @return Licznik pokonanych przeciwnikÛw.
     */
    int getKillEnemy();

    /**
     * @brief Pobiera flagÍ kolizji z obszarem zmiany poziomu.
     *
     * @return Flaga kolizji z obszarem zmiany poziomu.
     */
    int getKolizjaNextLevel();

    /**
     * @brief Ustawia úrodek protagonista na jego aktualnej pozycji.
     */
    void setCenter();

    /**
     * @brief Ustawia pozycjÍ X protagonista.
     *
     * @param newX Nowa pozycja X protagonista.
     */
    void setX(int newX);

    /**
     * @brief Ustawia pozycjÍ Y protagonista.
     *
     * @param newY Nowa pozycja Y protagonista.
     */
    void setY(int newY);

    /**
     * @brief Ustawia szerokoúÊ protagonista.
     *
     * @param newWidth Nowa szerokoúÊ protagonista.
     */
    void setWidth(int newWidth);

    /**
     * @brief Ustawia wysokoúÊ protagonista.
     *
     * @param newHeight Nowa wysokoúÊ protagonista.
     */
    void setHeight(int newHeight);

    /**
     * @brief Ustawia kierunek poruszania siÍ protagonista.
     *
     * @param newKierunek Nowy kierunek poruszania siÍ protagonista (1=w, 2=s, 3=a, 4=d).
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
     * @brief Ustawia ID obiektu, z ktÛrym protagonist koliduje.
     *
     * @param newID Nowe ID obiektu kolidujπcego.
     */
    void setIdObiektKolidujacego(int newID);

    /**
     * @brief Ustawia licznik pokonanych przeciwnikÛw.
     *
     * @param newKillEnemy Nowa wartoúÊ licznika pokonanych przeciwnikÛw.
     */
    void setKillEnemy(int newKillEnemy);

    /**
     * @brief Ustawia flagÍ kolizji z obszarem zmiany poziomu.
     *
     * @param newKolizjaNextLevel Nowa wartoúÊ flagi kolizji z obszarem zmiany poziomu.
     */
    void setKolizjaNextLevel(int newKolizjaNextLevel);

    /**
     * @brief Ustawia obraz protagonisty.
     *
     * @param renderer Wskaünik do renderera SDL.
     * @param nowaSciezkaObrazu åcieøka do nowego pliku obrazu.
     */
    void setObraz(SDL_Renderer* renderer, const char* nowaSciezkaObrazu);

    /**
     * @brief Obs≥uguje kolizje protagonisty z obiektami na mapie.
     *
     * @param objectList Lista obiektÛw na mapie.
     */
    void kolizja(std::vector<ObiektMapy>& objectList);

    /**
     * @brief Konstruktor klasy Protagonist.
     *
     * @param renderer Wskaünik do renderera SDL.
     * @param sciezkaObrazuProtagonisty åcieøka do pliku obrazu protagonisty.
     * @param x Pozycja X protagonisty.
     * @param y Pozycja Y protagonisty.
     */
    Protagonist(SDL_Renderer* renderer, const char* sciezkaObrazuProtagonisty, int x, int y);

    /**
     * @brief Metoda renderujπca protagonistÍ na ekranie.
     *
     * @param renderer Wskaünik do renderera SDL.
     */
    void render(SDL_Renderer* renderer);
};
#endif