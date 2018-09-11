#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include "gtest_ext.h"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;



TEST(Operations, OutputFormat)
{
   std::string expected = "Please enter in the operation (+, -, *, /): Please "
                          "input the first number: Please input the second "
                          "number: You chose to multiply: 5 * 6 = 30\n";
   ASSERT_MAIN_OUTPUT_EQ("operations", "* 5 6", expected);
}

TEST(Operations, Addition)
{
   srand (time(NULL));
   for(int i = 0; i < 10; i++)
   {
      std::string operation_input = "+";
      int numOne = rand();
      int numTwo = rand();
      std::string output_string;
      std::string input = operation_input + " " + std::to_string(numOne) + " "
                          + std::to_string(numTwo);

      std::string strOne = std::to_string(numOne);
      std::string strTwo = std::to_string(numTwo);
      int sum = numOne + numTwo;
      output_string = "You chose to add: " + strOne + " + " + strTwo + " = "
                      + std::to_string(sum);

      ASSERT_MAIN_OUTPUT_THAT("operations", input, HasSubstr(output_string));
   }
}

TEST(Operations, Subtraction)
{
   for(int i = 0; i < 10; i++)
   {
      std::string operation_input = "-";
      int numOne = rand();
      int numTwo = rand();
      std::string output_string;
      std::string input = operation_input + " " + std::to_string(numOne) + " "
                          + std::to_string(numTwo);

      std::string strOne = std::to_string(numOne);
      std::string strTwo = std::to_string(numTwo);

      int dif = numOne - numTwo;
      output_string = "You chose to subtract: " + strOne + " - " + strTwo
                      + " = " + std::to_string(dif);

      ASSERT_MAIN_OUTPUT_THAT("operations", input, HasSubstr(output_string));
   }
}

TEST(Operations, Multiplication)
{
   for(int i = 0; i < 10; i++)
   {
      std::string operation_input = "*";
      int numOne = rand();
      int numTwo = rand();
      std::string output_string;
      std::string input = operation_input + " " + std::to_string(numOne) + " "
                          + std::to_string(numTwo);

      std::string strOne = std::to_string(numOne);
      std::string strTwo = std::to_string(numTwo);

      int multiply = numOne * numTwo;
      output_string = "You chose to multiply: " + strOne + " * " + strTwo
                      + " = " + std::to_string(multiply);

      ASSERT_MAIN_OUTPUT_THAT("operations", input, HasSubstr(output_string));
   }
}

TEST(Operations, Division)
{
   for(int i = 0; i < 10; i++)
   {
      std::string operation_input = "/";
      int numOne = rand();
      int numTwo = rand();
      std::string output_string;
      std::string input = operation_input + " " + std::to_string(numOne) + " "
                          + std::to_string(numTwo);

      std::string strOne = std::to_string(numOne);
      std::string strTwo = std::to_string(numTwo);

      int divide = numOne / numTwo;
      output_string = "You chose to divide: " + strOne + " / " + strTwo + " = "
                      + std::to_string(divide);

      ASSERT_MAIN_OUTPUT_THAT("operations", input, HasSubstr(output_string));
   }
}

TEST(Operations, FailCase)
{
   for(int i = 0; i < 10; i++)
   {
      int fail_input = rand() % 10;
      int numOne = rand();
      int numTwo = rand();
      std::string output_string;
      std::string input = std::to_string(fail_input) + " "
                          + std::to_string(numOne) + " "
                          + std::to_string(numTwo);

      output_string = "Invalid operation type.\n";

      ASSERT_MAIN_OUTPUT_THAT("operations", input, HasSubstr(output_string));
   }
}

int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
