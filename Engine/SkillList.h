#pragma once
#ifndef SkillList_H
#define SkillList_H

#include <vector>
#include "Skill.h"

/**
 * @brief Klasa reprezentuj¹ca listê umiejêtnoœci.
 */
class SkillList {

public:
    std::vector<Skill> skillList; ///< Lista umiejêtnoœci.

    /**
     * @brief Konstruktor klasy SkillList.
     */
    SkillList();

    /**
     * @brief Dodaje umiejêtnoœæ do listy umiejêtnoœci.
     *
     * @param skill Umiejêtnoœæ do dodania.
     */
    void addSkill(Skill& skill);

    /**
     * @brief Tworzy listê umiejêtnoœci.
     */
    void createList();
};

#endif
