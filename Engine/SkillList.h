#pragma once
#ifndef SkillList_H
#define SkillList_H

#include <vector>
#include "Skill.h"

/**
 * @brief Klasa reprezentuj�ca list� umiej�tno�ci.
 */
class SkillList {

public:
    std::vector<Skill> skillList; ///< Lista umiej�tno�ci.

    /**
     * @brief Konstruktor klasy SkillList.
     */
    SkillList();

    /**
     * @brief Dodaje umiej�tno�� do listy umiej�tno�ci.
     *
     * @param skill Umiej�tno�� do dodania.
     */
    void addSkill(Skill& skill);

    /**
     * @brief Tworzy list� umiej�tno�ci.
     */
    void createList();
};

#endif
