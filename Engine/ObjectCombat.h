#pragma once
#ifndef ObjectCombat_H
#define ObjectCombat_H

#include <SDL.h>
#include "SDL_image.h"
#include <iostream>
#include <string>
#include "SkillList.h"

/**
 * @brief Klasa reprezentuj�ca obiekt w systemie walki.
 */
class ObjectCombat {
private:
    float maxHp; ///< Maksymalna ilo�� punkt�w �ycia.
    float currentHp; ///< Aktualna ilo�� punkt�w �ycia.
    float physicalDmg; ///< Fizyczne obra�enia.
    float magicDmg; ///< Magiczne obra�enia.
    float currentPhysicalDefense; ///< Aktualna obrona przed fizycznymi obra�eniami.
    float physicalDefense; ///< Obrona przed fizycznymi obra�eniami.
    float currentMagicDefense; ///< Aktualna obrona przed magicznymi obra�eniami.
    float magicDefense; ///< Obrona przed magicznymi obra�eniami.

public:
    SkillList skills; ///< Lista umiej�tno�ci obiektu.

    /**
     * @brief Konstruktor klasy ObjectCombat.
     *
     * @param MaxHp Maksymalna ilo�� punkt�w �ycia.
     * @param currentHp Aktualna ilo�� punkt�w �ycia.
     * @param physicalDmg Fizyczne obra�enia.
     * @param magicDmg Magiczne obra�enia.
     * @param physicalDefense Obrona przed fizycznymi obra�eniami.
     * @param magicDefense Obrona przed magicznymi obra�eniami.
     */
    ObjectCombat(float MaxHp, float currentHp, float physicalDmg, float magicDmg, float physicalDefense, float magicDefense);

    /**
     * @brief Pobiera aktualn� ilo�� punkt�w �ycia.
     *
     * @return Aktualna ilo�� punkt�w �ycia.
     */
    float getCurrentHp();
    float getPhysicalDmg();
    float getMagicDmg();
    float getPhysicalDefense();
    float getMagicDefense();
    float getMaxHp();

    /**
     * @brief Oblicza i zwraca obra�enia zadane obiektowi.
     *
     * @param physicalDmg Obra�enia fizyczne.
     * @param magicalDmg Obra�enia magiczne.
     * @param skill Umiej�tno�� u�yta przeciwko obiektowi.
     */
    void getDamage(float physicalDmg, float magicalDmg, Skill skill);

    /**
     * @brief Zwi�ksza obron� obiektu w odpowiedniej kategorii.
     *
     * @param typeOfDefense Typ obrony (fizyczna lub magiczna).
     * @param skill Umiej�tno�� u�yta do zwi�kszenia obrony.
     */
    void getDefenseUp(int typeOfDefense, Skill skill);

    /**
     * @brief Uzdrawia obiekt na podstawie u�ytej umiej�tno�ci.
     *
     * @param skill Umiej�tno�� uzdrawiaj�ca.
     */
    void getHeal(Skill skill);

    /**
     * @brief Ustawia aktualn� ilo�� punkt�w �ycia.
     *
     * @param newHp Nowa ilo�� punkt�w �ycia.
     */
    void setCurrentHp(float newHp);
    void setCurrentMagicDefense(float newMagicDefense);
    void setCurrentPhysicalDefense(float newPhysicalDefense);
};

#endif
