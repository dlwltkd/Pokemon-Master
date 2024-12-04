#include "Pokemon.h"
#include <iostream>
#include <algorithm> // For std::max

// Constructor

Pokemon::Pokemon(const std::string& name, const std::string& type, int maxHP, const std::vector<Skill>& skills)
    : pokemonName(name), pokemonType(type), maxHP(maxHP), currentHP(maxHP), pokemonSkills(skills), lastSkillSuccess(true) {} 


// Get the name of the Pokémon
std::string Pokemon::getName() const { 
    return pokemonName; 
}

// Get the type of the Pokémon
std::string Pokemon::getType() const { 
    return pokemonType; 
}

// Get the current HP
int Pokemon::getCurrentHP() const { 
    return currentHP; 
}

// Get the maximum HP
int Pokemon::getMaxHP() const { 
    return maxHP; 
}

bool Pokemon::wasLastSkillSuccess() const { return lastSkillSuccess; }


// Get a specific skill by index
Skill Pokemon::getSkill(int index) const {
    if (index < 0 || index >= static_cast<int>(pokemonSkills.size())) {
        throw std::out_of_range("Invalid skill index");
    }
    return pokemonSkills[index];
}

// Get the name of a skill
std::string Pokemon::getSkillName(int index) const { 
    return pokemonSkills[index].getName(); 
}

// Get the type of a skill
std::string Pokemon::getSkillType(int index) const { 
    return pokemonSkills[index].getType(); 
}

// Get the base damage of a skill
int Pokemon::getSkillDamage(int index) const { 
    return pokemonSkills[index].getBaseDamage(); 
}

// Get the remaining tries of a skill
int Pokemon::getSkillRemaining(int index) const { 
    return pokemonSkills[index].getRemainingTries(); 
}

// Get the maximum tries of a skill
int Pokemon::getSkillMax(int index) const { 
    return pokemonSkills[index].getMaxTries(); 
}

// Use a skill on the opponent, returns effectiveness feedback

std::string Pokemon::useSkill(int skillIndex, Pokemon& opponent) {
    // Calculate effectiveness regardless of skill success
    char effectivenessChar = pokemonSkills[skillIndex].getEffectivenessChar(opponent.getType());

    // Translate effectiveness character into feedback string
    std::string feedback;
    if (effectivenessChar == 'O') {
        feedback = "It was super effective.";
    } else if (effectivenessChar == 'X') {
        feedback = "It was not very effective.";
    } else {
        feedback = "It was effective.";
    }

    // Check if the skill can be performed
    if (skillIndex < 0 || skillIndex >= static_cast<int>(pokemonSkills.size()) || pokemonSkills[skillIndex].getRemainingTries() <= 0) {
        std::cout << pokemonName << " failed to perform " << pokemonSkills[skillIndex].getName() << ".\n" << std::endl;
        lastSkillSuccess = false; // Indicate failure
        return feedback;
    }

    // Skill can be performed
    int damage = pokemonSkills[skillIndex].getDamage(opponent.getType());

    // Inflict damage on the opponent
    opponent.takeDamage(damage);

    // Decrease skill usage count
    pokemonSkills[skillIndex].use();

    lastSkillSuccess = true; // Indicate success

    return feedback;
}


// Reduce HP by damage amount
void Pokemon::takeDamage(int damage) {
    currentHP = std::max(0, currentHP - damage); // Ensure HP doesn't go below 0
}

// Check if Pokémon has fainted (HP <= 0)
bool Pokemon::isFainted() const {
    return currentHP <= 0;
}


