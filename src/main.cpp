#include <iostream>
#include <vector>
#include <string>
#include "Pokemon.h"
#include "Skill.h"
#include <iomanip>  // For std::setw
#include <sstream>  // For std::ostringstream

// Function to print the battle page
void printBattlePage(const Pokemon& player1, const Pokemon& player2, bool player1Turn,
                     const std::string& lastSkill1 = "-", const std::string& lastSkill2 = "-",
                     const std::string& effectiveness1 = "", const std::string& effectiveness2 = "") {
    const int COL_WIDTH = 29;  
    const int TOTAL_WIDTH = 61;  

    // Clean up effectiveness strings (remove any extra newlines)
    std::string eff1 = effectiveness1;
    std::string eff2 = effectiveness2;
    if (!eff1.empty() && eff1.back() == '\n') eff1.pop_back();
    if (!eff2.empty() && eff2.back() == '\n') eff2.pop_back();

    // Use std::ostringstream to format effectiveness strings
    std::ostringstream oss1, oss2;
    oss1 << std::left << std::setw(COL_WIDTH) << eff1;
    oss2 << std::left << std::setw(COL_WIDTH) << eff2;
    eff1 = oss1.str();
    eff2 = oss2.str();

    // Print table header
    std::cout << "+" << std::string(TOTAL_WIDTH, '-') << "+\n";
    std::cout << "| 2024-02 Object-Oriented Programming Pokemon Master          |\n";
    std::cout << "+------------------------------+------------------------------+\n";

    // Player names and turn indicators
    std::cout << "| " << std::left << std::setw(COL_WIDTH)
              << player1.getName() + (player1Turn ? " (*)" : "") << "| "
              << std::left << std::setw(COL_WIDTH)
              << player2.getName() + (!player1Turn ? " (*)" : "") << "|\n";

    // Player types and HP
    std::cout << "| " << std::left << std::setw(COL_WIDTH)
              << "Type: " + player1.getType() << "| "
              << std::left << std::setw(COL_WIDTH)
              << "Type: " + player2.getType() << "|\n";

    std::cout << "| " << std::left << std::setw(COL_WIDTH)
              << "HP: " + std::to_string(player1.getCurrentHP()) << "| "
              << std::left << std::setw(COL_WIDTH)
              << "HP: " + std::to_string(player2.getCurrentHP()) << "|\n";

    std::cout << "+------------------------------+------------------------------+\n";

    // Latest skills and effectiveness
    std::cout << "| " << std::left << std::setw(COL_WIDTH)
              << "Latest Skill: " + lastSkill1 << "| "
              << std::left << std::setw(COL_WIDTH)
              << "Latest Skill: " + lastSkill2 << "|\n";

    std::cout << "| " << eff1 << "| " << eff2 << "|\n";

    std::cout << "+------------------------------+------------------------------+\n";

    // Skills section
    for (int i = 0; i < 4; ++i) {
        // Skill names
        std::cout << "| " << std::left << std::setw(COL_WIDTH)
                  << "(" + std::to_string(i) + ") " + player1.getSkillName(i) << "| "
                  << std::left << std::setw(COL_WIDTH)
                  << "(" + std::to_string(i) + ") " + player2.getSkillName(i) << "|\n";

        // Prefixes and field widths
        const std::string typePrefix = "    - Type: ";
        const int typeFieldWidth = COL_WIDTH - typePrefix.length();

        const std::string damagePrefix = "    - Damage: ";
        const int damageFieldWidth = COL_WIDTH - damagePrefix.length();

        const std::string countPrefix = "    - Count: ";
        const int countFieldWidth = COL_WIDTH - countPrefix.length();

        // Type
        std::cout << "| " << typePrefix << std::left << std::setw(typeFieldWidth)
                  << player1.getSkillType(i) << "| " << typePrefix
                  << std::left << std::setw(typeFieldWidth)
                  << player2.getSkillType(i) << "|\n";

        // Damage
        std::cout << "| " << damagePrefix << std::left << std::setw(damageFieldWidth)
                  << std::to_string(player1.getSkillDamage(i)) << "| " << damagePrefix
                  << std::left << std::setw(damageFieldWidth)
                  << std::to_string(player2.getSkillDamage(i)) << "|\n";

        // Count
        std::cout << "| " << countPrefix << std::left << std::setw(countFieldWidth)
                  << std::to_string(player1.getSkillRemaining(i)) + "(" + std::to_string(player1.getSkillMax(i)) + ")"
                  << "| " << countPrefix
                  << std::left << std::setw(countFieldWidth)
                  << std::to_string(player2.getSkillRemaining(i)) + "(" + std::to_string(player2.getSkillMax(i)) + ")"
                  << "|\n";
    }

    std::cout << "+------------------------------+------------------------------+\n";
}

int main() {
    // Define all Pokémon
    std::vector<Pokemon> pokemons = {
        Pokemon("Pikachu", "Electric", 35, {
            Skill("Tackle", "Normal", 4, 5),
            Skill("Grass Knot", "Grass", 8, 5),
            Skill("Thunderbolt", "Electric", 10, 5),
            Skill("Megabolt", "Electric", 15, 3)
        }),
        Pokemon("Dratini", "Water", 41, {
            Skill("Wrap", "Normal", 4, 10),
            Skill("Aqua Tail", "Water", 3, 5),
            Skill("Water Pulse", "Water", 13, 2),
            Skill("Hyper Beam", "Normal", 20, 1)
        }),
        Pokemon("Eevee", "Normal", 55, {
            Skill("Tackle", "Normal", 4, 5),
            Skill("Sand Attack", "Ground", 8, 3),
            Skill("Bite", "Normal", 12, 3),
            Skill("Rain Dance", "Water", 15, 1)
        }),
        Pokemon("Charmander", "Fire", 39, {
            Skill("Tackle", "Normal", 4, 5),
            Skill("Flamethrower", "Fire", 11, 5),
            Skill("Dig", "Ground", 7, 5),
            Skill("Heat Wave", "Fire", 14, 5)
        }),
        Pokemon("Palkia", "Water", 90, {
            Skill("Hydro Pump", "Water", 12, 10),
            Skill("Earth Power", "Ground", 15, 10),
            Skill("Surf", "Water", 13, 10),
            Skill("Spatial Rend", "Normal", 30, 10)
        })
    };

    // Step 1: Select two Pokémon
    std::cout << "Choose a Pokemon(0~4): ";
    int choice1, choice2;
    std::cin >> choice1;
    std::cout << "Choose a Pokemon(0~4): ";
    std::cin >> choice2;

    if (choice1 == choice2) {
        std::cout << "You have to choose Pokemons different from each other.\n";
        return 0;
    }

    Pokemon* player1 = &pokemons[choice1];
    Pokemon* player2 = &pokemons[choice2];

    // Step 2: Battle Loop
    bool player1Turn = true;
    std::string lastSkill1 = "-", lastSkill2 = "-";
    std::string effectiveness1 = "", effectiveness2 = "";

    while (!player1->isFainted() && !player2->isFainted()) {
    printBattlePage(*player1, *player2, player1Turn, lastSkill1, lastSkill2, effectiveness1, effectiveness2);

    std::cout << "Choose a skill (0~3): ";
    int skillIndex;
    std::cin >> skillIndex;

    if (player1Turn) {
        // Attempt to use the skill
        std::string tempEffectiveness = player1->useSkill(skillIndex, *player2);

        if (tempEffectiveness.empty()) {
            // Skill failed, do not update lastSkill1 or effectiveness1
            // The failure message is already printed inside useSkill
        } else {
            // Skill succeeded, update lastSkill1 and effectiveness1
            lastSkill1 = player1->getSkillName(skillIndex);
            effectiveness1 = tempEffectiveness;

            // Print feedback
            std::cout << player1->getName() << " used " << lastSkill1 << ".\n";
            std::cout << effectiveness1 << "\n";
        }
    } else {
        // Attempt to use the skill
        std::string tempEffectiveness = player2->useSkill(skillIndex, *player1);

        if (tempEffectiveness.empty()) {
            // Skill failed, do not update lastSkill2 or effectiveness2
            // The failure message is already printed inside useSkill
        } else {
            // Skill succeeded, update lastSkill2 and effectiveness2
            lastSkill2 = player2->getSkillName(skillIndex);
            effectiveness2 = tempEffectiveness;

            // Print feedback
            std::cout << player2->getName() << " used " << lastSkill2 << ".\n";
            std::cout << effectiveness2 << "\n";
        }
    }

    player1Turn = !player1Turn;  // Switch turns
}


    // Step 3: Print Result
    std::cout << std::string(63, '=') << "\n";
    if (player1->isFainted()) {
        std::cout << "Match Result: " << player2->getName() << " defeats " << player1->getName() << "\n";
    } else {
        std::cout << "Match Result: " << player1->getName() << " defeats " << player2->getName() << "\n";
    }

    return 0;
}
