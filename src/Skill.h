#ifndef SKILL_H
#define SKILL_H

#include <string>

class Skill {
private:
    std::string skillName;    // Name of the skill
    std::string skillType;    // Type of the skill (e.g., Normal, Fire)
    int baseDamage;           // Base damage of the skill
    int maxTries;             // Maximum number of times the skill can be used
    int remainingTries;       // Remaining number of times the skill can be used

public:
    // Constructor
    Skill(const std::string& name, const std::string& type, int baseDamage, int maxTries);

    // Getters
    std::string getName() const;           // Get the name of the skill
    std::string getType() const;           // Get the type of the skill
    int getBaseDamage() const;             // Get the base damage of the skill
    int getMaxTries() const;               // Get the maximum number of times the skill can be used
    int getRemainingTries() const;         // Get the remaining number of times the skill can be used

    // Function to calculate the final damage based on effectiveness
    int getDamage(const std::string& defenderType) const;

    // Function to get the effectiveness character ('O', 'X', '-')
    char getEffectivenessChar(const std::string& defenderType) const;

    // Decrement the remaining tries of the skill
    void use();
};

#endif // SKILL_H
