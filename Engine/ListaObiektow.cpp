#include "ListaObiektow.h"

ListaObiektow::ListaObiektow() {
    //randObjectMap();
}

void ListaObiektow::addObiekt( ObiektMapy& obiektMapy) {
    objectList.push_back(obiektMapy);
}
void ListaObiektow::creatList(SDL_Renderer* renderer) {
    ObiektMapy obiektMapy1 (renderer, "../image/prop2.png", -500, 0,"Orbana",0);
    ObiektMapy obiektMapy2 (renderer, "../image/prop3.png", -500, 270,"Joli",1);
    ObiektMapy obiektMapy3(renderer, "../image/prop4.png", -500, 300, "Turtlanta",2);
    ObiektMapy obiektMapy4(renderer, "../image/prop5.png", -500, -500, "Hupig",3);
    ObiektMapy obiektMapy5(renderer, "../image/prop6.png", -500, -500, "Huczi",4);
    addObiekt(obiektMapy1);
    addObiekt(obiektMapy2);
    addObiekt(obiektMapy3);
    addObiekt(obiektMapy4);
    addObiekt(obiektMapy5);
    
}
void ListaObiektow::printList(SDL_Renderer* renderer){
    for ( auto& element : objectList) {
        element.render(renderer);
    }
}
void ListaObiektow::randObjectMap() {
    amountRandObjectMap = 1+ std::rand() % 5;
    int amountRandObjectMapCopy = amountRandObjectMap;
    for (auto it = objectList.begin(); it != objectList.end() && amountRandObjectMapCopy > 0; ++it, amountRandObjectMapCopy--) {
        it->setX(rand() % 900);
        it->setY(rand() % 500);
        it->setCenter();
    }

}
void ListaObiektow::setAmountRandObjectMap(int newAmountRandObjectMap) {
    this->amountRandObjectMap = newAmountRandObjectMap;
}
int ListaObiektow::getAmountRandObjectMap() { return amountRandObjectMap; }