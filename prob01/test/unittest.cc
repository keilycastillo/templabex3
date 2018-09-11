#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <cmath>
#include "gtest_ext.h"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;



TEST(RepresentativeEligibility, OutputFormat)
{
  std::string expected = "Age (in years): "
                      "Years as a U.S. Citizen: "
                      "You are eligible to be a U.S. Senator.\n";
  ASSERT_MAIN_OUTPUT_EQ("representative-eligibility", "30 15", expected);
}

TEST(RepresentativeEligibility, IsSenator)
{
  for(int i = 0; i < 10; i++)
  {
    int ageInYears = (rand() % 40) + 30;
    int yearsAsCitizen = (rand() % 40) + 9;
    std::string input = std::to_string(ageInYears) + " " +std::to_string(yearsAsCitizen);
    std::string expected = "You are eligible to be a U.S. Senator.\n";
    ASSERT_MAIN_OUTPUT_THAT("representative-eligibility", input, HasSubstr(expected));
  }
}

TEST(RepresentativeEligibility, IsRepresentative)
{
  for (int i = 0; i < 10; i++) {
    int ageInYears = (rand() % 50) + 25;
    int yearsAsCitizen = (rand() % 1) + 7;
    //std::cout << ageInYears << " " << yearsAsCitizen << std::endl;
    std::string input = std::to_string(ageInYears) + " " +std::to_string(yearsAsCitizen);
    std::string expected = "You are eligible to be a U.S. Representative.\n";
    ASSERT_MAIN_OUTPUT_THAT("representative-eligibility", input, HasSubstr(expected));
  }
}

TEST(RepresentativeEligibility, IsNeither)
{
  for(int i = 0; i < 10; i++)
  {
    int ageInYears = (rand() % 5) + 19;
    int yearsAsCitizen = (rand() % 2) + 4;
    std::string input = std::to_string(ageInYears) + " " +std::to_string(yearsAsCitizen);
    std::string expected = "You are not eligible to be a Senator or Representative.\n";
    ASSERT_MAIN_OUTPUT_THAT("representative-eligibility", input, HasSubstr(expected));
  }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
