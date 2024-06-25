#include <iostream>

#include "menu.cpp"
#include "sheet.cpp"

class program {
public:
    void startProgram() {

        // Dipslays the menu.
        menu menu;
        menu.displayMenu();

        // Sheet setup.
        sheet sheet;
        sheet.setupCharacter();

        // Displays sheet.
        sheet.displaySheet();


        //std::cout << sheet.getName() << std::endl;

        // displayCharacterSheet(sheet) or sheet.displaySheet();

    }
};