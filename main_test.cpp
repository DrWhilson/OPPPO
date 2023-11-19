#include "lab1.h"
#include <gtest/gtest.h>

TEST(checkCondTest, somevars) { Fig *obj = new Sphere(); }

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
