#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include <CppUTest/UtestMacros.h>

#include "lab1.h"

TEST_GROUP(FirstTestGroup){};

TEST(FirstTestGroup, FirstTest) { FAIL("Fail!"); }

int main(int ac, char **av) {
  return CommandLineTestRunner::RunAllTests(ac, av);
}
