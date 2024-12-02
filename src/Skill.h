#ifndef SKILL_H
#define SKILL_H

#include <string>

class Skill {
private:
    std::string skillName;  // Name of the skill
    std::string skillType;  // Type of the skill (e.g., Normal, Water)
    int baseDamage;         // Base damage of the skill
    int maxTries;           // Maximum times this skill can be used
    int remainingTries;     // Remaining times this skill can be used

public:
    // Constructor
    Skill(const std::string& name, const std::string& type, int baseDamage, int maxTries);

    // Getters
    std::string getName() const;  // Get skill name
    std::string getType() const;  // Get skill type
    int getBaseDamage() const;    // Get skill base damage
    int getMaxTries() const;      // Get maximum tries
    int getRemainingTries() const;  // Get remaining tries

    // Function to calculate final damage based on defender's type
    int getDamage(const std::string& defenderType) const;

    // Function to decrement remaining tries
    void use();
};

#endif // SKILL_H
