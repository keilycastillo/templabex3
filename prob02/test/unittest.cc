#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <cmath>
#include <string>
#include "gtest_ext.h"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;



TEST(Range, OutputFormat)
{
  std::string expected = "Please enter the low number for this range: Please enter "
                      "the high number for this range: Please choose a number to "
                      "check in range: 5 is in range [1,10]\n";
  ASSERT_MAIN_OUTPUT_EQ("range", "1 10 5", expected);
}

TEST(Range, InRange)
{
  srand (time(NULL));
  for(int i = 0; i < 10; i++)
  {
    int low = rand() % 5,
        high = (rand() % 5) + 10,
        choice = 5;
    std::string in_range_string = std::to_string(choice) + " is in range [" + std::to_string(low) + "," + std::to_string(high) + "]";
    std::string input = std::to_string(low) + " " + std::to_string(high) + " 5";
    ASSERT_MAIN_OUTPUT_THAT("range", input, HasSubstr(in_range_string));
  }
}

TEST(Range, OutOfRange)
{
  for(int i = 0; i < 10; i++)
  {
    int low = rand() % 5,
        high = (rand() % 5) + 10,
        choice = 20;
    std::string in_range_string = std::to_string(choice) + " isn't in range [" + std::to_string(low) + "," + std::to_string(high) + "]";
    std::string input = std::to_string(low) + " " + std::to_string(high) + " 20";
    ASSERT_MAIN_OUTPUT_THAT("range", input, HasSubstr(in_range_string));
  }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
