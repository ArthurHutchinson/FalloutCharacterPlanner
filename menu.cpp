#include <string>
#include <cctype>
#include <iostream>

#include "ahFunctions.h"

class menu {

private:
    std::vector <std::string> MENU_DIALOG = {
            "======================================",
            "|  FALLOUT TTRPG Character Planner   |",
            "======================================",
            "|       System by XP to Lvl 3        |",
            "| Planner Coded by Arthur Hutchinson |",
            "======================================",
            "| - (N)ew Character                  |",
            "| - (E)xit                           |",
            "======================================",
    };

public:
    void displayMenu() {

        // Displays dialog above
        displayDialog(MENU_DIALOG);

        std::string input = getInput();

        while (true) {
            if (input == "n" || input == "new character" || input == "new") {
                displayDialog("======================================");
                break;
            } else if (input == "e" || input == "exit") {
                std::cout << "DEBUG: Exit Game Started" << std::endl;
                exit(0);
            } else {
                std::cout << "Unknown Command" << std::endl;
                input = getInput();
            }
        }

    }
};