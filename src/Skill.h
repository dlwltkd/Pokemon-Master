#ifndef SKILL_H
#define SKILL_H

#include <string>

class Skill {
    private:
    std::string skillName;
    std::string skillType;
    int baseDamage;
    int maxTries;
    int remainingTries;

    public: 
    Skill(const std::string& name, const std::string type, int baseDamage, int maxTries);
    std::string getName() const;
    int getRemainingTries() const ;
    int getDamage(const std::string& opponentType) const;
    void use();

};


#endif //SKILL_H