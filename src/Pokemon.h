#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>
#include "Skill.h"

class Pokemon {
private:
    std::string pokemonName;       // Name of the Pokémon
    std::string pokemonType;       // Type of the Pokémon
    int maxHP;                     // Maximum HP of the Pokémon
    int currentHP;                 // Current HP of the Pokémon
    std::vector<Skill> pokemonSkills;  // List of skills the Pokémon has

public:
    // Constructor
   Pokemon(const std::string& name, const std::string& type, int maxHP, const std::vector<Skill>& skills);


    // Getters
    std::string getName() const;            // Get the name of the Pokémon
    std::string getType() const;            // Get the type of the Pokémon
    int getCurrentHP() const;               // Get the current HP
    int getMaxHP() const;                   // Get the maximum HP

    Skill getSkill(int index) const;        // Get a specific skill by index

    std::string getSkillName(int index) const;      // Get the name of a skill
    std::string getSkillType(int index) const;      // Get the type of a skill
    int getSkillDamage(int index) const;            // Get the base damage of a skill
    int getSkillRemaining(int index) const;         // Get the remaining tries of a skill
    int getSkillMax(int index) const;               // Get the maximum tries of a skill

    // Functions
    std::string useSkill(int skillIndex, Pokemon& opponent);  // Use a skill on the opponent, returns effectiveness feedback
    void takeDamage(int damage);           // Reduce HP by damage amount
    bool isFainted() const;                // Check if Pokémon has fainted (HP <= 0)
    void printStats() const;               // Print Pokémon stats (optional)
};

#endif // POKEMON_H
