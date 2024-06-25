#include <string>
#include <vector>

#include "ahUnitTest.h"
#include "ahFunctions.h"
#include "sheet.cpp"

sheet sheet;

void IS_TRUE_TEST() {
    // IS_TRUE(1,2); // This is meant to fail on purpose.
    IS_TRUE(2,2);
}

void ahFunctions_toStrLower_Test() {
    IS_TRUE("abc",toStrLower("ABC"));
    IS_TRUE("a b c",toStrLower("A b C"));
    IS_TRUE("the quick brown fox jumps over the lazy dog.",toStrLower("The quick brown fox jumps over the lazy dog."));
    // IS_TRUE("a b c","a B c"); // This is meant to fail on purpose.
}

void getDialog_Test() {
    std::vector<std::string> v_test = {
            "Test1",
            "Test Two",
            "The quick brown fox jumps over the lazy dog."
    };

    IS_TRUE("Test1",getDialog(v_test,0));
    IS_TRUE("Test Two",getDialog(v_test,1));
    IS_TRUE("The quick brown fox jumps over the lazy dog.",getDialog(v_test,2));
    // IS_TRUE("Nothing",getDialog(v_test,1)); // This is meant to fail on purpose.
}

void displayDialog_Test() {

    std::vector<std::string> testVect = {
            "Test 1","Test 2","Test 3","Test 4","Test 5","Test 6"
    };

    // Expected is ALL elements.
    displayDialog(testVect);

    std::vector<std::string> testVect2 = {
            "2Test 1","2Test 2","2Test 3","2Test 4","2Test 5","2Test 6"
    };

    // Expected is 2Test 2 to 2Test 5.
    displayDialog(testVect2,1,4);

    // Expected is string.
    std::string testStr = "This is a test.";
    displayDialog(testStr);
    displayDialog("This is also a test pt 2");

}

void calcModifier_Test() {
    IS_TRUE(2,sheet.calcModifier(7));
    IS_TRUE(-3,sheet.calcModifier(2));
}

void calcStaminaPoints_Test() {
    IS_TRUE(12,sheet.calcStaminaPoints(2));
    IS_TRUE(14,sheet.calcStaminaPoints(4));

    int agility = 8;
    IS_TRUE(13,sheet.calcStaminaPoints(sheet.calcModifier(agility)));

    agility = 3;
    IS_TRUE(8,sheet.calcStaminaPoints(sheet.calcModifier(agility)));
}

void RUN_ALL_TESTS() {
    IS_TRUE_TEST();
    ahFunctions_toStrLower_Test();
    getDialog_Test();
    calcModifier_Test();
    calcStaminaPoints_Test();
    // displayDialog_Test(); // Manual test, unable to unit test due to it outputting cout.
}