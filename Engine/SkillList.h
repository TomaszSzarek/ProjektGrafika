#pragma once
#ifndef SkillList_H
#define SkillList_H

#include <vector>
#include "Skill.h"

/**
 * @brief Klasa reprezentująca listę umiejętności.
 */
class SkillList {

public:
    std::vector<Skill> skillList; ///< Lista umiejętności.

    /**
     * @brief Konstruktor klasy SkillList.
     */
    SkillList();

    /**
     * @brief Dodaje umiejętność do listy umiejętności.
     *
     * @param skill Umiejętność do dodania.
     */
    void addSkill(Skill& skill);

    /**
     * @brief Tworzy listę umiejętności.
     */
    void createList();
};

#endif
