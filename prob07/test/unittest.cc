#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <cmath>
#include "gtest_ext.h"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;


TEST(creditcardapproval, CreditTest)
{
  srand (time(NULL));
  for(int i = 0; i < 10; i++)
  {
    std::string expected_output;
    int CreditInput = rand()%851;
    std::string input = to_string_int(CreditInput);
    //If you are a student, and can somehow read and understand this and understand it, then you can do the problem.
    //Why are you even looking in here?
    expected_output=(CreditInput <=580&&CreditInput >0?                   "Sorry, we cannot approve you for any credit card at the moment\n":
                    (CreditInput >=580&&CreditInput<670 ?  "We can approve you for the SILVER Tuffy Card\n":
                    (CreditInput >=670&&CreditInput<800 ?  "We can approve you for the GOLD Tuffy Card\n":
                    (CreditInput >=800&&CreditInput<=850 ? "We would love to approve you for the PLATINUM Tuffy Card\n":
                    (CreditInput<0||CreditInput>850 ?          "You have entered in an invalid credit score. Please restart the program and try again\n":
                                                           "This should never be output\n")))));

    ASSERT_MAIN_OUTPUT_THAT("creditcardapproval", input, HasSubstr(expected_output));
  }
}

TEST(creditcardapproval, InvalidInputTest)
{
  srand (time(NULL));
  //Loop for negative inputs
  for(int i = 0; i < 5; i++)
  {
    std::string expected_output;
    int CreditInput = (rand()%851+1 )* -1;
    std::string input = to_string_int(CreditInput);
    //If you are a student, and can somehow read and understand this and understand it, then you can do the problem.
    //Why are you even looking in here?
    expected_output=(CreditInput <=580&&CreditInput >0 ?                   "Sorry, we cannot approve you for any credit card at the moment\n":
                    (CreditInput >=580&&CreditInput<670 ?  "We can approve you for the SILVER Tuffy Card\n":
                    (CreditInput >=670&&CreditInput<800 ?  "We can approve you for the GOLD Tuffy Card\n":
                    (CreditInput >=800&&CreditInput<=850 ? "We would love to approve you for the PLATINUM Tuffy Card\n":
                    (CreditInput<0||CreditInput>850 ?      "You have entered in an invalid credit score. Please restart the program and try again\n":
                                                           "This should never be output\n")))));

    ASSERT_MAIN_OUTPUT_THAT("creditcardapproval", input, HasSubstr(expected_output));
  }
  //Loop for positive inputs
  for(int i = 0; i < 5; i++)
  {
    std::string expected_output;
    int CreditInput = rand()%851+851;
    std::string input = to_string_int(CreditInput);
    //If you are a student, and can somehow read and understand this and understand it, then you can do the problem.
    //Why are you even looking in here?
    expected_output=(CreditInput <=580&&CreditInput >0 ?   "Sorry, we cannot approve you for any credit card at the moment\n":
                    (CreditInput >=580&&CreditInput<670 ?  "We can approve you for the SILVER Tuffy Card\n":
                    (CreditInput >=670&&CreditInput<800 ?  "We can approve you for the GOLD Tuffy Card\n":
                    (CreditInput >=800&&CreditInput<=850 ? "We would love to approve you for the PLATINUM Tuffy Card\n":
                    (CreditInput<0||CreditInput>850 ?          "You have entered in an invalid credit score. Please restart the program and try again\n":
                                                           "This should never be output\n")))));

    ASSERT_MAIN_OUTPUT_THAT("creditcardapproval", input, HasSubstr(expected_output));
  }
}




TEST(creditcardapproval, EdgeCases)
{
    std::string input;
    input = to_string_int(579);
    ASSERT_MAIN_OUTPUT_THAT("creditcardapproval", input, HasSubstr("Sorry, we cannot approve you for any credit card at the moment"));

    input = to_string_int(580);
    ASSERT_MAIN_OUTPUT_THAT("creditcardapproval", input, HasSubstr("We can approve you for the SILVER Tuffy Card"));
    input = to_string_int(669);
    ASSERT_MAIN_OUTPUT_THAT("creditcardapproval", input, HasSubstr("We can approve you for the SILVER Tuffy Card"));

    input = to_string_int(670);
    ASSERT_MAIN_OUTPUT_THAT("creditcardapproval", input, HasSubstr("We can approve you for the GOLD Tuffy Card"));
    input = to_string_int(799);
    ASSERT_MAIN_OUTPUT_THAT("creditcardapproval", input, HasSubstr("We can approve you for the GOLD Tuffy Card"));

    input = to_string_int(800);
    ASSERT_MAIN_OUTPUT_THAT("creditcardapproval", input, HasSubstr("We would love to approve you for the PLATINUM Tuffy Card\n"));
    input = to_string_int(850);
    ASSERT_MAIN_OUTPUT_THAT("creditcardapproval", input, HasSubstr("We would love to approve you for the PLATINUM Tuffy Card\n"));

    input = to_string_int(0);
    ASSERT_MAIN_OUTPUT_THAT("creditcardapproval", input, HasSubstr("Sorry, we cannot approve you for any credit card at the moment"));
    input = to_string_int(-1);
    ASSERT_MAIN_OUTPUT_THAT("creditcardapproval", input, HasSubstr("You have entered in an invalid credit score. Please restart the program and try again"));
    input = to_string_int(851);
    ASSERT_MAIN_OUTPUT_THAT("creditcardapproval", input, HasSubstr("You have entered in an invalid credit score. Please restart the program and try again"));
}

TEST(creditcardapproval, OutputFormat)
{
  std::string expected =  "Thank you for applying for the Tuffy Credit card. Please enter your credit score\n"
                          "Credit Score: "
                          "We can approve you for the GOLD Tuffy Card\n"
                          "Thank you for using our program, please come again\n";
  ASSERT_MAIN_OUTPUT_EQ("creditcardapproval", "700", expected);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
