#pragma once
#ifndef Skill_H
#define Skill_H

#include <string>
/**
 * @brief Klasa reprezentująca umiejętność.
 */
class Skill{
private:
    std::string typeSkill; ///< Typ umiejętności.
    std::string name; ///< Nazwa umiejętności.
    float multiplierAd; ///< Wskaźnik mnożnika obrażeń fizycznych (AD) umiejętności.
    float multiplierAp; ///< Wskaźnik mnożnika obrażeń magicznych (AP) umiejętności.

public:
    /**
     * @brief Konstruktor klasy Skill.
     *
     * @param skillName Nazwa umiejętności.
     * @param skillMultiplierAD Wskaźnik mnożnika obrażeń fizycznych (AD) umiejętności.
     * @param skillMultiplierAp Wskaźnik mnożnika obrażeń magicznych (AP) umiejętności.
     * @param skillType Typ umiejętności.
     */
    Skill(const std::string& skillName, float skillMultiplierAD,float skillMultiplierAp,const std::string& typeSkill);
    /**
  * @brief Pobiera nazwę umiejętności.
  *
  * @return Nazwa umiejętności.
  */
    std::string getName();
    /**
   * @brief Pobiera wskaźnik mnożnika obrażeń fizycznych (AD) umiejętności.
   *
   * @return Wskaźnik mnożnika AD umiejętności.
   */
    float getMultiplierAd();
    /**
    * @brief Pobiera wskaźnik mnożnika obrażeń magicznych (AP) umiejętności.
    *
    * @return Wskaźnik mnożnika AP umiejętności.
    */
    float getMultiplierAp();
};

#endif
