#ifndef AHFUNCTIONS_H_
#define AHFUNCTIONS_H_

#include <string>
#include <vector>

// Convernts a String to Lower Case
std::string toStrLower(std::string str);

// gets a specific string from a vector via index.
std::string getDialog(std::vector<std::string> v, int index);

// displays an entire vector string in console.
void displayDialog(std::vector<std::string> v);

// displays a specific index in a vector to console.
void displayDialog(std::vector<std::string> v, int index);

// displays strings between two indexes.
void displayDialog(std::vector<std::string> v, int min, int max);

// displays a string to console with the given string.
void displayDialog(std::string str);

// Gets an input and converts it to lowercase.
std::string getInput();

// Gets an input and any int placed in will NOT convert the input string to lower case.
std::string getInput(int isNotLower);

#endif