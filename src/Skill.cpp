#include "Skill.h"
#include <map>  // For the effectiveness table
#include <algorithm>  // For std::max

// Constructor
Skill::Skill(const std::string& name, const std::string& type, int baseDamage, int maxTries)
    : skillName(name), skillType(type), baseDamage(baseDamage), maxTries(maxTries), remainingTries(maxTries) {}

// Getters
std::string Skill::getName() const {
    return skillName;
}

std::string Skill::getType() const {
    return skillType;
}

int Skill::getBaseDamage() const {
    return baseDamage;
}

int Skill::getMaxTries() const {
    return maxTries;
}

int Skill::getRemainingTries() const {
    return remainingTries;
}

// Function to calculate final damage based on effectiveness
int Skill::getDamage(const std::string& defenderType) const {
    static const std::map<std::string, std::map<std::string, char>> effectivenessTable = {
        {"Normal", {{"Normal", '-'}, {"Ground", '-'}, {"Electric", '-'}, {"Water", '-'}, {"Grass", '-'}, {"Fire", '-'}}},
        {"Ground", {{"Normal", '-'}, {"Ground", '-'}, {"Electric", 'O'}, {"Water", '-'}, {"Grass", 'X'}, {"Fire", 'O'}}},
        {"Electric", {{"Normal", '-'}, {"Ground", 'X'}, {"Electric", 'X'}, {"Water", 'O'}, {"Grass", 'X'}, {"Fire", '-'}}},
        {"Water", {{"Normal", '-'}, {"Ground", 'O'}, {"Electric", '-'}, {"Water", 'X'}, {"Grass", 'X'}, {"Fire", 'O'}}},
        {"Grass", {{"Normal", '-'}, {"Ground", 'X'}, {"Electric", '-'}, {"Water", 'O'}, {"Grass", 'X'}, {"Fire", 'X'}}},
        {"Fire", {{"Normal", '-'}, {"Ground", '-'}, {"Electric", '-'}, {"Water", 'X'}, {"Grass", 'O'}, {"Fire", 'X'}}}
    };

    // Determine effectiveness
    char effectiveness = effectivenessTable.at(skillType).at(defenderType);

    // Calculate modified damage
    int modifiedDamage = baseDamage;
    if (effectiveness == 'O') {
        modifiedDamage += 5;  // Super effective
    } else if (effectiveness == 'X') {
        modifiedDamage -= 3;  // Not very effective
    }

    // Ensure damage is not negative
    return std::max(0, modifiedDamage);
}

// Decrement the remaining tries of the skill
void Skill::use() {
    if (remainingTries > 0) {
        --remainingTries;
    }
}
