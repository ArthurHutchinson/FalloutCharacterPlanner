#include <string>
#include <vector>
#include <iostream>
#include <cctype>

#include "ahFunctions.h"

// This function will convert a string to lowercase
// Because C++ does not have this in their library.
// Only Char.
std::string toStrLower(std::string str) {
    std::string lowerInput;
    for (char character:str) { // For-each loop to convert each char to lower, then adds it to lowerInput string.
        lowerInput += std::tolower(character);
    };
    return lowerInput;
};

// A function that will get dialog from a single element.
std::string getDialog(std::vector<std::string> v,int index) {
    return v[index];
};

// A function that will display entire string vector to the terminal using function above.
void displayDialog(std::vector<std::string> v) {

    for (int i = 0; i < v.size(); i++) {
        std::cout << getDialog(v,i) << std::endl;
    }

};

void displayDialog(std::vector<std::string> v, int index) {
    std::cout << getDialog(v,index) << std::endl;
}

// Displays dialog between two index elements to terminal.
void displayDialog(std::vector<std::string> v,int min, int max) {

    for (int i = min; i <= max; i++) {
        std::cout << getDialog(v,i) << std::endl;
    };

};

void displayDialog(std::string str) {
    std::cout << str << std::endl;
}

// Saves on typing, getting input from the user and returns it in lower-case string.
std::string getInput() {

    std::string input;
    std::getline(std::cin,input);
    return toStrLower(input);

};

std::string getInput(int isNotLower) {
    std::string input;
    std::getline(std::cin,input);
    return input;
};