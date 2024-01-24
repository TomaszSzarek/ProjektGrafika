#pragma once
#ifndef Skill_H
#define Skill_H

#include <string>
/**
 * @brief Klasa reprezentuj¹ca umiejêtnoœæ.
 */
class Skill{
private:
    std::string typeSkill; ///< Typ umiejêtnoœci.
    std::string name; ///< Nazwa umiejêtnoœci.
    float multiplierAd; ///< WskaŸnik mno¿nika obra¿eñ fizycznych (AD) umiejêtnoœci.
    float multiplierAp; ///< WskaŸnik mno¿nika obra¿eñ magicznych (AP) umiejêtnoœci.

public:
    /**
     * @brief Konstruktor klasy Skill.
     *
     * @param skillName Nazwa umiejêtnoœci.
     * @param skillMultiplierAD WskaŸnik mno¿nika obra¿eñ fizycznych (AD) umiejêtnoœci.
     * @param skillMultiplierAp WskaŸnik mno¿nika obra¿eñ magicznych (AP) umiejêtnoœci.
     * @param skillType Typ umiejêtnoœci.
     */
    Skill(const std::string& skillName, float skillMultiplierAD,float skillMultiplierAp,const std::string& typeSkill);
    /**
  * @brief Pobiera nazwê umiejêtnoœci.
  *
  * @return Nazwa umiejêtnoœci.
  */
    std::string getName();
    /**
   * @brief Pobiera wskaŸnik mno¿nika obra¿eñ fizycznych (AD) umiejêtnoœci.
   *
   * @return WskaŸnik mno¿nika AD umiejêtnoœci.
   */
    float getMultiplierAd();
    /**
    * @brief Pobiera wskaŸnik mno¿nika obra¿eñ magicznych (AP) umiejêtnoœci.
    *
    * @return WskaŸnik mno¿nika AP umiejêtnoœci.
    */
    float getMultiplierAp();
};

#endif
