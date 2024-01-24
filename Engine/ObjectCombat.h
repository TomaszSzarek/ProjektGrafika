#pragma once
#ifndef ObjectCombat_H
#define ObjectCombat_H

#include <SDL.h>
#include "SDL_image.h"
#include <iostream>
#include <string>
#include "SkillList.h"

/**
 * @brief Klasa reprezentuj¹ca obiekt w systemie walki.
 */
class ObjectCombat {
private:
    float maxHp; ///< Maksymalna iloœæ punktów ¿ycia.
    float currentHp; ///< Aktualna iloœæ punktów ¿ycia.
    float physicalDmg; ///< Fizyczne obra¿enia.
    float magicDmg; ///< Magiczne obra¿enia.
    float currentPhysicalDefense; ///< Aktualna obrona przed fizycznymi obra¿eniami.
    float physicalDefense; ///< Obrona przed fizycznymi obra¿eniami.
    float currentMagicDefense; ///< Aktualna obrona przed magicznymi obra¿eniami.
    float magicDefense; ///< Obrona przed magicznymi obra¿eniami.

public:
    SkillList skills; ///< Lista umiejêtnoœci obiektu.

    /**
     * @brief Konstruktor klasy ObjectCombat.
     *
     * @param MaxHp Maksymalna iloœæ punktów ¿ycia.
     * @param currentHp Aktualna iloœæ punktów ¿ycia.
     * @param physicalDmg Fizyczne obra¿enia.
     * @param magicDmg Magiczne obra¿enia.
     * @param physicalDefense Obrona przed fizycznymi obra¿eniami.
     * @param magicDefense Obrona przed magicznymi obra¿eniami.
     */
    ObjectCombat(float MaxHp, float currentHp, float physicalDmg, float magicDmg, float physicalDefense, float magicDefense);

    /**
     * @brief Pobiera aktualn¹ iloœæ punktów ¿ycia.
     *
     * @return Aktualna iloœæ punktów ¿ycia.
     */
    float getCurrentHp();
    float getPhysicalDmg();
    float getMagicDmg();
    float getPhysicalDefense();
    float getMagicDefense();
    float getMaxHp();

    /**
     * @brief Oblicza i zwraca obra¿enia zadane obiektowi.
     *
     * @param physicalDmg Obra¿enia fizyczne.
     * @param magicalDmg Obra¿enia magiczne.
     * @param skill Umiejêtnoœæ u¿yta przeciwko obiektowi.
     */
    void getDamage(float physicalDmg, float magicalDmg, Skill skill);

    /**
     * @brief Zwiêksza obronê obiektu w odpowiedniej kategorii.
     *
     * @param typeOfDefense Typ obrony (fizyczna lub magiczna).
     * @param skill Umiejêtnoœæ u¿yta do zwiêkszenia obrony.
     */
    void getDefenseUp(int typeOfDefense, Skill skill);

    /**
     * @brief Uzdrawia obiekt na podstawie u¿ytej umiejêtnoœci.
     *
     * @param skill Umiejêtnoœæ uzdrawiaj¹ca.
     */
    void getHeal(Skill skill);

    /**
     * @brief Ustawia aktualn¹ iloœæ punktów ¿ycia.
     *
     * @param newHp Nowa iloœæ punktów ¿ycia.
     */
    void setCurrentHp(float newHp);
    void setCurrentMagicDefense(float newMagicDefense);
    void setCurrentPhysicalDefense(float newPhysicalDefense);
};

#endif
