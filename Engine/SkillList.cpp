#include "SkillList.h"

SkillList::SkillList() {
}

void SkillList::addSkill(Skill&skill) {
	skillList.push_back(skill);
}
void SkillList::createList() {
	Skill atak1("atakFizyczny", 3, 1,"atak");
	Skill atak2("atak1",2, 2, "atak");
	//Skill atak3("atak2", 2, 3);
	Skill atak4("atakMagiczny", 1, 6, "atak");
	Skill obrona1("obronaFizyczna",5, 1, "obrona");
	Skill obrona2("obronaMagiczna", 1, 5, "obrona");
	Skill leczenie("leczenie", 1, 2.5, "leczenie");
	addSkill(atak1);
	addSkill(atak2);
	//addSkill(atak3);
	addSkill(atak4);
	addSkill(obrona1);
	addSkill(obrona2);
	addSkill(leczenie);
}