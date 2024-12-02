#include <iostream>
#include <vector>
#include "Pokemon.h"
#include "Skill.h"

// Function to print the battle page
void printBattlePage(const Pokemon& player1, const Pokemon& player2, bool player1Turn, const std::string& lastSkill1 = "-", const std::string& lastSkill2 = "-", const std::string& effectiveness1 = "", const std::string& effectiveness2 = "") {
    std::cout << "+-------------------------------------------------------------+\n";
    std::cout << "| 2024-02 Object-Oriented Programming Pokemon Master          |\n";
    std::cout << "+------------------------------+------------------------------+\n";
    std::cout << "| " << player1.getName();
    if (player1Turn) std::cout << " (*)";
    std::cout << std::string(30 - player1.getName().length() - (player1Turn ? 4 : 0), ' ') << "| " << player2.getName();
    if (!player1Turn) std::cout << " (*)";
    std::cout << std::string(30 - player2.getName().length() - (!player1Turn ? 4 : 0), ' ') << "|\n";
    std::cout << "| Type: " << player1.getType() << std::string(24 - player1.getType().length(), ' ')
              << "| Type: " << player2.getType() << std::string(24 - player2.getType().length(), ' ') << "|\n";
    std::cout << "| HP: " << player1.getCurrentHP() << std::string(27 - std::to_string(player1.getCurrentHP()).length(), ' ')
              << "| HP: " << player2.getCurrentHP() << std::string(27 - std::to_string(player2.getCurrentHP()).length(), ' ') << "|\n";
    std::cout << "+------------------------------+------------------------------+\n";
    std::cout << "| Latest Skill: " << lastSkill1 << std::string(17 - lastSkill1.length(), ' ')
              << "| Latest Skill: " << lastSkill2 << std::string(17 - lastSkill2.length(), ' ') << "|\n";
    std::cout << "| " << effectiveness1 << std::string(28 - effectiveness1.length(), ' ')
              << "| " << effectiveness2 << std::string(28 - effectiveness2.length(), ' ') << "|\n";
    std::cout << "+------------------------------+------------------------------+\n";
    for (int i = 0; i < 4; ++i) {
        std::cout << "| (" << i << ") " << player1.getSkillName(i) << std::string(28 - player1.getSkillName(i).length(), ' ')
                  << "| (" << i << ") " << player2.getSkillName(i) << std::string(28 - player2.getSkillName(i).length(), ' ') << "|\n";
        std::cout << "|     - Type: " << player1.getSkillType(i) << std::string(20 - player1.getSkillType(i).length(), ' ')
                  << "|     - Type: " << player2.getSkillType(i) << std::string(20 - player2.getSkillType(i).length(), ' ') << "|\n";
        std::cout << "|     - Damage: " << player1.getSkillDamage(i) << std::string(19 - std::to_string(player1.getSkillDamage(i)).length(), ' ')
                  << "|     - Damage: " << player2.getSkillDamage(i) << std::string(19 - std::to_string(player2.getSkillDamage(i)).length(), ' ') << "|\n";
        std::cout << "|     - Count: " << player1.getSkillRemaining(i) << "(" << player1.getSkillMax(i) << ")" << std::string(19 - std::to_string(player1.getSkillRemaining(i)).length() - std::to_string(player1.getSkillMax(i)).length() - 2, ' ')
                  << "|     - Count: " << player2.getSkillRemaining(i) << "(" << player2.getSkillMax(i) << ")" << std::string(19 - std::to_string(player2.getSkillRemaining(i)).length() - std::to_string(player2.getSkillMax(i)).length() - 2, ' ') << "|\n";
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
            effectiveness1 = player1->useSkill(skillIndex, *player2);
            lastSkill1 = player1->getSkillName(skillIndex);
        } else {
            effectiveness2 = player2->useSkill(skillIndex, *player1);
            lastSkill2 = player2->getSkillName(skillIndex);
        }

        player1Turn = !player1Turn;
    }

    // Step 3: Print Result
    std::cout << "===============================================================\n";
    if (player1->isFainted()) {
        std::cout << "Match Result: " << player2->getName() << " defeats " << player1->getName() << "\n";
    } else {
        std::cout << "Match Result: " << player1->getName() << " defeats " << player2->getName() << "\n";
    }

    return 0;
}
