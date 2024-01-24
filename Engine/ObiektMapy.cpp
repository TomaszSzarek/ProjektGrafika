#include "ObiektMapy.h"

ObiektMapy::ObiektMapy(SDL_Renderer* renderer, const char* sciezkaObrazu, int poczatkoweX, int poczatkoweY, std::string name, int id)
    : x(poczatkoweX), y(poczatkoweY), width(), height(), texture(nullptr),name(name),id(id){
    SDL_Surface* surface = IMG_Load(sciezkaObrazu);
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
        centerX = poczatkoweX+(width/2); 
        centerY = poczatkoweY+(height/2);
        

        SDL_FreeSurface(surface);
    }
}
void ObiektMapy::render(SDL_Renderer* renderer) const{
    SDL_Rect destinationRect = { x, y, width, height };
    SDL_RenderCopy(renderer, texture, nullptr, &destinationRect);
}
int ObiektMapy::getX() const { return x; };
int ObiektMapy::getY()  const{ return y; };
int ObiektMapy::getWidth() const{ return width; };
int ObiektMapy::getHeight()  { return height; };
int ObiektMapy::getCenterX() { return centerX; };
int ObiektMapy::getCenterY() { return centerY; };
int ObiektMapy::getID() { return id; };
float ObiektMapy::getDistance() const{ return distance; }
void ObiektMapy::setX(int newX) {
    x = newX;
}
void ObiektMapy::setY(int newY) {
    y = newY;
}
void ObiektMapy::setWidth(int newWidth) {
    width = newWidth;
}
void ObiektMapy::setHeight(int newHeight) {
    height = newHeight;
}
void ObiektMapy::setCenter(){
    centerX = x + (width / 2);
    centerY = y + (height / 2);
}
void ObiektMapy::setDistance(int protagonistCenterX,int protagonistCenterY) {
    if (protagonistCenterX <= this->getCenterX() && protagonistCenterY <= this->getCenterY()) {
        distance = std::sqrt(std::pow(this->getCenterX() - protagonistCenterX, 2) + std::pow(this->getCenterY() - protagonistCenterY, 2));
    }
    else if (protagonistCenterX <= this->getCenterX() && protagonistCenterY > this->getCenterY()) {
        distance = std::sqrt(std::pow(this->getCenterX() - protagonistCenterX, 2) + std::pow(protagonistCenterY - this->getCenterY(), 2));
    }
    else if (protagonistCenterX > this->getCenterX() && protagonistCenterY <= this->getCenterY()) {
        distance = std::sqrt(std::pow(protagonistCenterX - this->getCenterX(), 2) + std::pow(this->getCenterY() - protagonistCenterY, 2));
    }
    else {
        distance = std::sqrt(std::pow(this->getCenterX() - protagonistCenterX, 2) + std::pow(protagonistCenterY - this->getCenterY(), 2));
    }
}