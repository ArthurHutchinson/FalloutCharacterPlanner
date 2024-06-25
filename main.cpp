#include <iostream>

#include "program.cpp"
#include "ahUnitTest.h"

int main() {

    // This will run the functions in the program and make sure calculations are done correctly.
    RUN_ALL_TESTS();

    // Program starts here.
    program program;
    program.startProgram();

    return 0;

}
