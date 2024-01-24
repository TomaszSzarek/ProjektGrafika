#include "ObjectCombat.h"
//ObjectCombat::ObjectCombat(SDL_Renderer* renderer, const char* sciezkaObrazu, int x, int y, float ad, float ap, float hp, float resistanceAd, float resistanceAp)
//    : x(x), y(y), ad(ad), hp(hp), ap(ap), resistanceAd(resistanceAd), resistanceAp(resistanceAp), texture(nullptr)
//{
//    SDL_Surface* surface = IMG_Load(sciezkaObrazu);
//    if (surface == nullptr) {
//        std::cerr << "B³¹d podczas wczytywania obrazu: " << SDL_GetError() << std::endl;
//        return;
//    }
//    else {
//        texture = SDL_CreateTextureFromSurface(renderer, surface);
//        if (texture == nullptr) {
//            std::cerr << "B³¹d podczas tworzenia tekstury: " << SDL_GetError() << std::endl;
//            return;
//        }
//
//        SDL_FreeSurface(surface);
//    }
//}
//
//void ObjectCombat::render(SDL_Renderer* renderer) {
//    SDL_Rect destinationRect = { x, y };
//    SDL_RenderCopy(renderer, texture, nullptr, &destinationRect);
//}
ObjectCombat::ObjectCombat(float maxHp, float currentHp, float physicalDmg, float magicDmg, float physicalDefense, float magicDefense)
    :maxHp(maxHp), currentHp(currentHp), physicalDmg(physicalDmg), magicDmg(magicDmg), physicalDefense(physicalDefense), magicDefense(magicDefense),currentMagicDefense(magicDefense),currentPhysicalDefense(physicalDefense) {}

float ObjectCombat::getMaxHp() { return maxHp; };
float ObjectCombat::getCurrentHp() { return currentHp; }
float ObjectCombat::getPhysicalDmg() { return physicalDmg; }
float ObjectCombat::getMagicDmg() { return magicDmg; }
float ObjectCombat::getMagicDefense() { return physicalDefense; }
float ObjectCombat::getPhysicalDefense() { return magicDefense; }
void ObjectCombat::setCurrentHp(float newHp){
    currentHp = newHp;
}
void ObjectCombat::getDamage(float physicalDmg, float magicalDmg, Skill skill) {
    float damage= (magicDmg * skill.getMultiplierAp() - currentMagicDefense) + (physicalDmg * skill.getMultiplierAd() - currentPhysicalDefense);
    if (damage > 0) {
        currentHp = currentHp - damage;
    }
}
void ObjectCombat::getDefenseUp(int typeOfDefense, Skill skill) {
    if (typeOfDefense == 0) {//0 fizyczne, 1 magiczne
        currentPhysicalDefense = currentPhysicalDefense + (skill.getMultiplierAp() * magicDmg);
    }else{ currentMagicDefense = currentMagicDefense + (skill.getMultiplierAp() * magicDmg); }
}
void ObjectCombat::getHeal(Skill skill) {
    currentHp = currentHp + (magicDmg * skill.getMultiplierAp());
    if (currentHp > maxHp) { currentHp = maxHp; }
}


void ObjectCombat::setCurrentMagicDefense(float newCurrentMagicDefense) {
    currentMagicDefense = newCurrentMagicDefense;
}
void ObjectCombat::setCurrentPhysicalDefense(float newCurrentPhysicalDefense) {
    currentPhysicalDefense = newCurrentPhysicalDefense;
}

