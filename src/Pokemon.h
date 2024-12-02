#ifndef POKEMON_H
#define POKEMON_H


#include <string>
#include <vector>
#include "Skill.h"



class Pokemon {
    private: 
    std::string pokemonName;
    std::string pokemonType;
    int maxHP;
    int currentHP;
    std::vector<Skill> pokemonSkills;
    
    
    public:
    //Constructor
    Pokemon(const std::string& name, const std::string type, int maxHP, const std::vector<Skill>& skills);
    
    //getters
    std::string getName() const;
    std::string getType() const;
    int getCurrentHP() const;
    int getMaxHP() const;
    Skill getSkill(int index) const;

    //Functions
    int useSkill(int skillIndex, Pokemon& opponent); //uses skill on opponent
    void takeDamage(int damage); //reduces HP
    bool isFainted() const; //checks if HP <= 0
    void printStats() const; //prints pokemon stats


    
    
};

#endif //POKEMON_H