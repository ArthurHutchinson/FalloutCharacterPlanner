#ifndef AHUNITTEST_H_
#define AHUNITTEST_H_

#include <iostream>

#define IS_TRUE(expected,actual) { if ((expected) != (actual)) std::cout << "ERROR: " << __FUNCTION__ << " failed on Line " << __LINE__ << std::endl << "       Expected: " << expected << std::endl << "       Actual:   " << actual << std::endl; }

void RUN_ALL_TESTS();

#endif