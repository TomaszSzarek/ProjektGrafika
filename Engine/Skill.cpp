#include "Skill.h"

Skill::Skill(const std::string& skillName, float skillMultiplierAd, float skillMultiplierAp, const std::string& typeSkill)
    : name(skillName), multiplierAd(skillMultiplierAd), multiplierAp(skillMultiplierAp), typeSkill(typeSkill) {}

std::string Skill::getName()  { return name; }
float Skill::getMultiplierAd()  { return multiplierAd; }
float Skill::getMultiplierAp()  { return multiplierAp; }
