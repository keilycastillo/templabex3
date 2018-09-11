#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <cmath>
#include "gtest_ext.h"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;


TEST(FanControl, MenuTest)
{
  srand (time(NULL));
  for(int i = 0; i < 10; i++)
  {
    std::string expected_output;
    int FanOption = rand()%7-2;
    std::string input = to_string_int(FanOption);
    //If you are a student, and can somehow read and understand this and understand it, then you can do the problem.
    //Why are you even looking in here?
    expected_output=(FanOption ==1 ? "Warehouse Fan A is now turned on\n":
                    (FanOption ==2 ? "Warehouse Fan B is now turned on\n":
                    (FanOption ==3 ? "Office Fan system is now turned on\n":
                    (FanOption ==4 ? "Emergency Ventilation is now turned on - Please Evacuate the building\n":
                    (FanOption ==0 ? "Exiting program\n":
                    (FanOption<0||FanOption>4 ? "***Invalid menu option***\n": "This should never be output\n"))))));

    ASSERT_MAIN_OUTPUT_THAT("fancontrol", input, HasSubstr(expected_output));
  }
}

TEST(FanControl, EdgeCases)
{

  std::string input;
    input = to_string_int(-1);
    ASSERT_MAIN_OUTPUT_THAT("fancontrol", input, HasSubstr("***Invalid menu option***"));
    input = to_string_int(5);
    ASSERT_MAIN_OUTPUT_THAT("fancontrol", input, HasSubstr("***Invalid menu option***"));
    input = to_string_int(0);
    ASSERT_MAIN_OUTPUT_THAT("fancontrol", input, HasSubstr("Exiting program"));
    input = to_string_int(4);
    ASSERT_MAIN_OUTPUT_THAT("fancontrol", input, HasSubstr("Emergency Ventilation is now turned on - Please Evacuate the building\n"));

}

TEST(FanControl, OutputFormat)
{
  std::string expected =  "Welcome to the fan control system\n"
                          "The fans connected to the system:\n"
                          "1 - Warehouse Fan A\n"
                          "2 - Warehouse Fan B\n"
                          "3 - Office Fan system\n"
                          "4 - Emergency Ventilation\n"
                          "0 - Exit program\n"
                          "Please select which fans you want to turn on by entering a number 0-4: "
                          "Warehouse Fan A is now turned on\n"
                          "Thank you for using the fan control system!\n";
  ASSERT_MAIN_OUTPUT_EQ("fancontrol", "1", expected);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
