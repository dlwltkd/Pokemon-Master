#include <iostream>
#include <vector>
#include "Pokemon.h"
#include "Skill.h"

void printBattlePage(const Pokemon& player1, const Pokemon& player2, bool player1Turn) {
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
}

int main() {
    // Initialize Pokémon
    std::vector<Skill> pikachuSkills = {
        Skill("Tackle", "Normal", 4, 5),
        Skill("Grass Knot", "Grass", 8, 5),
        Skill("Thunderbolt", "Electric", 10, 5),
        Skill("Megabolt", "Electric", 15, 3)
    };
    Pokemon pikachu("Pikachu", "Electric", 35, pikachuSkills);

    std::vector<Skill> dratiniSkills = {
        Skill("Wrap", "Normal", 4, 10),
        Skill("Aqua Tail", "Water", 3, 5),
        Skill("Water Pulse", "Water", 13, 2),
        Skill("Hyper Beam", "Normal", 20, 1)
    };
    Pokemon dratini("Dratini", "Water", 41, dratiniSkills);

    // Select Pokémon
    Pokemon* player1 = &pikachu;
    Pokemon* player2 = &dratini;

    bool player1Turn = true;

    while (!player1->isFainted() && !player2->isFainted()) {
        printBattlePage(*player1, *player2, player1Turn);

        std::cout << "Choose a skill (0~3): ";
        int skillIndex;
        std::cin >> skillIndex;

        if (player1Turn) {
            player1->useSkill(skillIndex, *player2);
        } else {
            player2->useSkill(skillIndex, *player1);
        }

        if (player2->isFainted()) {
            std::cout << "===============================================================\n";
            std::cout << "Match Result: " << player1->getName() << " defeats " << player2->getName() << "\n";
            break;
        }
        if (player1->isFainted()) {
            std::cout << "===============================================================\n";
            std::cout << "Match Result: " << player2->getName() << " defeats " << player1->getName() << "\n";
            break;
        }

        player1Turn = !player1Turn; // Switch turns
    }

    return 0;
}
