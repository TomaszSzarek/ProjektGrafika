#include "Protagonist.h"


Protagonist::Protagonist(SDL_Renderer* renderer, const char* sciezkaObrazuProtagonisty, int poczatkoweX, int poczatkoweY)
    : x(poczatkoweX), y(poczatkoweY), width(), height(), texture(nullptr) {
    SDL_Surface* surface = IMG_Load(sciezkaObrazuProtagonisty);
    if (surface == nullptr) {
        std::cerr << "B³¹d podczas wczytywania obrazu: " << SDL_GetError() << std::endl;
        return;
        }
    else {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (texture == nullptr) {
            std::cerr << "B³¹d podczas tworzenia tekstury: " << SDL_GetError() << std::endl;
            return;
        }
        width = surface->w;
        height = surface->h;
        CenterX = poczatkoweX+(width/2);
        CenterY = poczatkoweY+(height/2);

        SDL_FreeSurface(surface);
    }
}

void Protagonist::render(SDL_Renderer* renderer) {
    SDL_Rect destinationRect = { x, y, width, height };
    SDL_RenderCopy(renderer, texture, nullptr, &destinationRect);
}
int Protagonist::getX() { return x; }
int Protagonist::getY() { return y; }
int Protagonist::getWidth() { return width; }
int Protagonist::getHeight() { return height; }
int Protagonist::getCenterX() { return CenterX; }
int Protagonist::getCenterY(){return CenterY; }
int Protagonist::getKierunek() {return kierunek;}
int Protagonist::getKolizjaW() { return kolizjaW; }
int Protagonist::getKolizjaS() { return kolizjaS; }
int Protagonist::getKolizjaA() { return kolizjaA; }
int Protagonist::getKolizjaD() { return kolizjaD; }
int Protagonist::getSpeed() { return speed; }
int Protagonist::getIdObiektKolidujacego() { return idObiektKolidujacego; }
int Protagonist::getKillEnemy() { return killEnemy; }
int Protagonist::getKolizjaNextLevel() { return kolizjaNextLevel; }
void Protagonist::setX(int newX) {
    x = newX;
}
void Protagonist::setY(int newY) {
    y = newY;
}
void Protagonist::setWidth(int newWidth) {
    width = newWidth;
}
void Protagonist::setHeight(int newHeight) {
    height = newHeight;
}
void Protagonist::setCenter() {
    CenterX = x + (width / 2);
    CenterY = y + (height / 2);
}
void Protagonist::setIdObiektKolidujacego(int newID) {
    idObiektKolidujacego = newID;
}
void Protagonist::setObraz(SDL_Renderer* renderer, const char* nowaSciezkaObrazu) {
    SDL_Surface* nowySurface = IMG_Load(nowaSciezkaObrazu);
    if (nowySurface == nullptr) {
        std::cerr << "B³¹d podczas wczytywania nowego obrazu: " << SDL_GetError() << std::endl;
        return;
    }

    // Zwolnij poprzedni¹ teksturê 
    SDL_DestroyTexture(texture);

    // Utwórz now¹ teksturê z nowego obrazu
    texture = SDL_CreateTextureFromSurface(renderer, nowySurface);
    if (texture == nullptr) {
        std::cerr << "B³¹d podczas tworzenia nowej tekstury: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(nowySurface);
        return;
    }
    SDL_FreeSurface(nowySurface);
}
void Protagonist::setKierunek(int newKierunek) {
    kierunek = newKierunek;
}
void Protagonist::setKolizjaW(int newKolizjaW) {
    kolizjaW = newKolizjaW;
}
void Protagonist::setKolizjaS(int newKolizjaS) {
    kolizjaS = newKolizjaS;
}
void Protagonist::setKolizjaA(int newKolizjaA) {
    kolizjaA = newKolizjaA;
}
void Protagonist::setKolizjaD(int newKolizjaD) {
    kolizjaD = newKolizjaD;
}
void Protagonist::setKillEnemy(int newKillEnemy) {
    killEnemy= newKillEnemy;
}
void Protagonist::setKolizjaNextLevel(int newKolizjaNextLevel) {
    kolizjaNextLevel = newKolizjaNextLevel;
}


void Protagonist::kolizja(std::vector<ObiektMapy>&objectList){
    if (CenterX>550&& CenterX<700 &&CenterY>600) {
        kolizjaNextLevel = 1;
    }
    else { kolizjaNextLevel = 0; }
    this->setKolizjaW(0);
    this->setKolizjaS(0);
    this->setKolizjaA(0);
    this->setKolizjaD(0);
    for (auto element : objectList) {
        element.setDistance(this->getCenterX(), this->getCenterY());
        if (element.getDistance()  +50< (element.getWidth() / 2) + (this->getWidth() / 2) && element.getCenterY() < this->getCenterY()) {
            setKolizjaW(getKolizjaW() + 1);
            setIdObiektKolidujacego(element.getID());
        }

        if (element.getDistance() + 50 < (element.getWidth() / 2) + (this->getWidth() / 2) && element.getCenterY() > this->getCenterY()) {
            setKolizjaS(getKolizjaS() + 1);
            setIdObiektKolidujacego(element.getID());
        }
        if (element.getDistance() + 50 < (element.getWidth() / 2) + (this->getWidth() / 2) && element.getCenterX() < this->getCenterX()) {
            setKolizjaA(getKolizjaA() + 1);
            setIdObiektKolidujacego(element.getID());
        }
        if (element.getDistance() + 50 < (element.getWidth() / 2) + (this->getWidth() / 2) && element.getCenterX() > this->getCenterX()) {
            setKolizjaD(getKolizjaD() + 1);
            setIdObiektKolidujacego(element.getID());
        }
    }
}