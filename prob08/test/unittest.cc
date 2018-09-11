#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include "gtest_ext.h"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;


TEST(Operations, OutputFormat1)
{
   std::string expected = "Input your first roll: "
   "Your total profit is $1\n";
   ASSERT_MAIN_OUTPUT_EQ("luckydice", "3", expected);
}

TEST(Operations, OutputFormat2)
{
   std::string expected = "Input your first roll: "
   "Input your second roll: "
   "Your total profit is $30\n";
   ASSERT_MAIN_OUTPUT_EQ("luckydice", "13 12", expected);
}

TEST(LuckyDice, OneRoll)
{
   srand (time(NULL));
   for(int i = 0; i < 10; i++)
   {
     int r = rand() % 10 + 1;
     std::string output_string;
     std::string input = std::to_string(r);
     int total_profit = 1;
     output_string = "Input your first roll: Your total profit is $"
     + std::to_string(total_profit) + "\n";

     ASSERT_MAIN_OUTPUT_THAT("luckydice", input, HasSubstr(output_string));
   }
}

TEST(LuckyDice, TwoRolls_Range1)
{
  for(int i = 0; i < 10; i++)
  {
    int r = rand() % 10 + 11;
    std::string output_string;
    std::string input = std::to_string(r) + " ";
    int total_profit = 10;
    output_string = "Input your first roll: ";
    r = 1;
    input += std::to_string(r);
    output_string += "Input your second roll: Your total profit is $"
    + std::to_string(total_profit) + "\n";

    ASSERT_MAIN_OUTPUT_THAT("luckydice", input, HasSubstr(output_string));
  }
}

TEST(LuckyDice, TwoRolls_Range2)
{
  for(int i = 0; i < 10; i++)
  {
    int r = rand() % 10 + 11;
    std::string output_string;
    std::string input = std::to_string(r) + " ";
    int total_profit = 10;
    output_string = "Input your first roll: ";
    r = rand() % 8 + 2;
    input += std::to_string(r);
    total_profit *= 2;
    output_string += "Input your second roll: Your total profit is $"
    + std::to_string(total_profit) + "\n";

    ASSERT_MAIN_OUTPUT_THAT("luckydice", input, HasSubstr(output_string));
  }
}

TEST(LuckyDice, TwoRolls_Range3)
{
  for(int i = 0; i < 10; i++)
  {
    int r = rand() % 10 + 11;
    std::string output_string;
    std::string input = std::to_string(r) + " ";
    int total_profit = 10;
    output_string = "Input your first roll: ";
    r = rand() % 7 + 10;
    input += std::to_string(r);
    total_profit *= 3;
    output_string += "Input your second roll: Your total profit is $"
    + std::to_string(total_profit) + "\n";

    ASSERT_MAIN_OUTPUT_THAT("luckydice", input, HasSubstr(output_string));
  }
}

TEST(LuckyDice, TwoRolls_Range4)
{
  for(int i = 0; i < 10; i++)
  {
    int r = rand() % 10 + 11;
    std::string output_string;
    std::string input = std::to_string(r) + " ";
    int total_profit = 10;
    output_string = "Input your first roll: ";
    r = rand() % 3 + 17;
    input += std::to_string(r);
    total_profit *= 5;
    output_string += "Input your second roll: Your total profit is $"
    + std::to_string(total_profit) + "\n";

    ASSERT_MAIN_OUTPUT_THAT("luckydice", input, HasSubstr(output_string));
  }
}

TEST(LuckyDice, TwoRolls_Range5)
{
  for(int i = 0; i < 10; i++)
  {
    int r = rand() % 10 + 11;
    std::string output_string;
    std::string input = std::to_string(r) + " ";
    int total_profit = 10;
    output_string = "Input your first roll: ";
    r = 20;
    input += std::to_string(r);
    total_profit *= 20;
    output_string += "Input your second roll: Your total profit is $"
    + std::to_string(total_profit) + "\n";

    ASSERT_MAIN_OUTPUT_THAT("luckydice", input, HasSubstr(output_string));
  }
}

int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
