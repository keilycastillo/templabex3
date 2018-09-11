#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <cmath>
#include "gtest_ext.h"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;

double roundTwoDecimal(double x)
{
  double value = (int)(x * 100 + 0.5);
  return (double)value / 100;
}

TEST(CashBack, OutputFormat)
{
   std::string expected = "Please enter type of card (‘g’ = green, ‘y’ = yellow, ‘r’ = red): "
   "Please enter amount of money spent: $"
   "Amount of cash back received: $2.11\n";
   ASSERT_MAIN_OUTPUT_EQ("cashback", "y 42.12", expected);
}

TEST(CashBack, GreenCard)
{
   for(int i = 0; i < 10; i++)
   {
      double money_spent = ((double)rand() / RAND_MAX * 100) / 100.0;
      money_spent = roundTwoDecimal(money_spent);
      double cashback;

      std::string output_string;

      std::string input = "g " + to_string_double(money_spent);

      cashback = money_spent * 0.10;
      cashback = roundTwoDecimal(cashback);

      output_string = "Amount of cash back received: $" + to_string_double(cashback) + "\n";

      ASSERT_MAIN_OUTPUT_THAT("cashback", input, HasSubstr(output_string));
   }
}

TEST(CashBack, YellowCard)
{
   for(int i = 0; i < 10; i++)
   {
      double money_spent = ((double)rand() / RAND_MAX * 100) / 100.0;
      money_spent = roundTwoDecimal(money_spent);
      double cashback;

      std::string output_string;

      std::string input = "y " + to_string_double(money_spent);

      cashback = money_spent * 0.05;
      cashback = roundTwoDecimal(cashback);

      output_string = "Amount of cash back received: $" + to_string_double(cashback) + "\n";

      ASSERT_MAIN_OUTPUT_THAT("cashback", input, HasSubstr(output_string));
   }
}

TEST(CashBack, RedCard)
{
   for(int i = 0; i < 10; i++)
   {
      double money_spent = ((double)rand() / RAND_MAX * 100) / 100.0;
      money_spent = roundTwoDecimal(money_spent);
      double cashback;

      std::string output_string;

      std::string input = "r " + to_string_double(money_spent);

      cashback = money_spent * 0.02;
      cashback = roundTwoDecimal(cashback);

      output_string = "Amount of cash back received: $" + to_string_double(cashback) + "\n";

      ASSERT_MAIN_OUTPUT_THAT("cashback", input, HasSubstr(output_string));
   }
}

TEST(CashBack, FailCase)
{
   for(int i = 0; i < 10; i++)
   {

      int fail_input = rand() % 10;
      double money_spent = ((double)rand() / RAND_MAX * 100) / 100.0;
      money_spent = roundTwoDecimal(money_spent);
      double cashback;

      std::string output_string;

      std::string input = to_string_double(fail_input) + " " + to_string_double(money_spent);

      output_string = "Invalid card type.\n";

      ASSERT_MAIN_OUTPUT_THAT("cashback", input, HasSubstr(output_string));
   }
}

int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
