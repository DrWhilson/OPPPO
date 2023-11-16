#include "lab1.h"
#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include <CppUTest/UtestMacros.h>

TEST_GROUP(FirstGroup){};

TEST(FirstGroup, failtst) { FAIL("FAIL!"); }

int main(int argc, char **argv) { return RUN_ALL_TESTS(argc, argv); }
