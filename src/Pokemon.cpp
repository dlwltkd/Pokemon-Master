#include "Pokemon.h"
#include <iostream>
#include <algorithm> //std::max

//Constructor
Pokemon::Pokemon(const std::string& name, const std::string type, int maxHP, const std::vector<Skill>& skills)
    : pokemonName(name), pokemonType(type), maxHP(maxHP), pokemonSkills(skills) {}
    
    //getters
    std::string Pokemon::getName() const {return pokemonName; }
    std::string Pokemon::getType() const { return pokemonType; }
    int Pokemon::getCurrentHP() const {return currentHP; }
    int Pokemon::getMaxHP() const {return maxHP; }

    //Functions
    int Pokemon::useSkill(int skillIndex, Pokemon& opponent){
        //placeholder for if skill cannot be performed, double check specifics
        if(skillIndex < 0 || skillIndex >= pokemonSkills.size() || pokemonSkills[skillIndex].getRemainingTries() <= 0) {
            std::cout << pokemonName << " failed to perfom " << pokemonSkills[skillIndex].getName() <<".\n"; 
            return 0;
        }
        int damage = pokemonSkills[skillIndex].getDamage(opponent.getType()); //damage calculated based on skill effectiveness
        opponent.takeDamage(damage);
        pokemonSkills[skillIndex].use(); //decrease the skill usage
        return damage;

    } 
    void Pokemon::takeDamage(int damage){
        currentHP = std::max(0,currentHP - damage);
    }
    bool Pokemon::isFainted() const {
        return currentHP <= 0;
    }
    void Pokemon::printStats() const {

        std::cout << "PLACEHOLDER\n";
    }