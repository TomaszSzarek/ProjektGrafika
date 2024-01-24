#pragma once
#ifndef Skill_H
#define Skill_H

#include <string>
/**
 * @brief Klasa reprezentuj�ca umiej�tno��.
 */
class Skill{
private:
    std::string typeSkill; ///< Typ umiej�tno�ci.
    std::string name; ///< Nazwa umiej�tno�ci.
    float multiplierAd; ///< Wska�nik mno�nika obra�e� fizycznych (AD) umiej�tno�ci.
    float multiplierAp; ///< Wska�nik mno�nika obra�e� magicznych (AP) umiej�tno�ci.

public:
    /**
     * @brief Konstruktor klasy Skill.
     *
     * @param skillName Nazwa umiej�tno�ci.
     * @param skillMultiplierAD Wska�nik mno�nika obra�e� fizycznych (AD) umiej�tno�ci.
     * @param skillMultiplierAp Wska�nik mno�nika obra�e� magicznych (AP) umiej�tno�ci.
     * @param skillType Typ umiej�tno�ci.
     */
    Skill(const std::string& skillName, float skillMultiplierAD,float skillMultiplierAp,const std::string& typeSkill);
    /**
  * @brief Pobiera nazw� umiej�tno�ci.
  *
  * @return Nazwa umiej�tno�ci.
  */
    std::string getName();
    /**
   * @brief Pobiera wska�nik mno�nika obra�e� fizycznych (AD) umiej�tno�ci.
   *
   * @return Wska�nik mno�nika AD umiej�tno�ci.
   */
    float getMultiplierAd();
    /**
    * @brief Pobiera wska�nik mno�nika obra�e� magicznych (AP) umiej�tno�ci.
    *
    * @return Wska�nik mno�nika AP umiej�tno�ci.
    */
    float getMultiplierAp();
};

#endif
