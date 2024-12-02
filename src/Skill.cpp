#include "Skill.h"

Skill::Skill(const std::string& name, const std::string type, int baseDamage, int maxTries)
    : skillName(name), skillType(type), baseDamage(baseDamage), maxTries(maxTries), remainingTries(maxTries) {}

    std::string Skill::getName() const {return skillName; }
    int Skill::getRemainingTries() const {return remainingTries; }
    int Skill::getDamage(const std::string& opponentType) const {
        //add logic for calculated damage based on effectiveness
        return baseDamage; //placeholder
    }
    void Skill::use() {
        if(remainingTries > 0) --remainingTries;
    }