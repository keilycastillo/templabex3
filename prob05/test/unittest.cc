#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <cmath>
#include <string>
#include "gtest_ext.h"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;



TEST(RideHeight, OutputFormat)
{
  std::string expected = "You must be at least 55 inches tall to ride\n"
                      "Please enter your height in inches: "
                      "Congratulations! You are tall enough to ride!\n";
  ASSERT_MAIN_OUTPUT_EQ("rideheight", "72", expected);
}

TEST(RideHeight, tall_enough)
{
  srand (time(NULL));
  for(int i = 0; i < 10; i++)
  {
    int height = (rand() % 20) + 55;
    std::string tall_enough_string = "Congratulations! You are tall enough to ride!";
    std::string input = std::to_string(height);
    ASSERT_MAIN_OUTPUT_THAT("rideheight", input, HasSubstr(tall_enough_string));
  }
}

TEST(RideHeight, too_short)
{
  for(int i = 0; i < 10; i++)
  {
    int height = (rand() % 20) + 34;
    std::string too_short_string = "For safety reasons, we can't let you ride yet.";
    std::string input = std::to_string(height);
    ASSERT_MAIN_OUTPUT_THAT("rideheight", input, HasSubstr(too_short_string));
  }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
