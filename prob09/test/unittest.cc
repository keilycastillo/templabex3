#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <cmath>
#include "gtest_ext.h"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;


TEST(MovieTickets, ChildTest)
{
  srand (time(NULL));
  for(int i = 0; i < 10; i++)
  {
    std::string input;
    std::string child_string = "The Subtotal for the ticket cost is: $" + to_string_double(20) + "\n";
    input += (to_string_int((rand()%12+1)) + " ");
    input += (to_string_int(rand()%12+1));
    ASSERT_MAIN_OUTPUT_THAT("moviesdatenight", input, HasSubstr(child_string));
  }
}

TEST(MovieTickets, YoungAdultTest)
{
  srand (time(NULL));
  for(int i = 0; i < 10; i++)
  {
    std::string input;
    std::string child_string = "The Subtotal for the ticket cost is: $" + to_string_double(13*2) + "\n";
    input += (to_string_int((rand()%8+13)) + " ");
    input += (to_string_int(rand()%8+13));
    ASSERT_MAIN_OUTPUT_THAT("moviesdatenight", input, HasSubstr(child_string));
  }
}

TEST(MovieTickets, AdultTest)
{
  srand (time(NULL));
  for(int i = 0; i < 10; i++)
  {
    std::string input;
    std::string child_string = "The Subtotal for the ticket cost is: $" + to_string_double(15*2) + "\n";
    input += (to_string_int((rand()%44+21)) + " ");
    input += (to_string_int(rand()%44+21));
    ASSERT_MAIN_OUTPUT_THAT("moviesdatenight", input, HasSubstr(child_string));
  }
}

TEST(MovieTickets, SeniorTest)
{
  srand (time(NULL));
  for(int i = 0; i < 10; i++)
  {
    std::string input;
    std::string Senior_string = "The Subtotal for the ticket cost is: $" + to_string_double(10*2) + "\n";
    input += (to_string_int((rand()%25+65)) + " ");
    input += (to_string_int(rand()%25+65));
    ASSERT_MAIN_OUTPUT_THAT("moviesdatenight", input, HasSubstr(Senior_string));
  }
}

TEST(MovieTickets, subTotalTest)
{
  srand (time(NULL));

  for(int i = 0; i < 10; i++)
  {
    std::string input;
    double subTotal = 0;
    for( int j =0; j<2;j++)
    {
        int age = rand()%99+1;
        input += (to_string_int(age) + " ");
        if(age < 13){
          subTotal += 10.00;
        }
        else if(age >=13 && age < 21){
          subTotal +=13.00;
        }
        else if(age >=21 && age < 65){
          subTotal += 15.00;
        }
        else if(age >=65){
          subTotal += 10.00;
        }
    }
    std::string subTotal_string = "The Subtotal for the ticket cost is: $" + to_string_double(subTotal) + "\n";
    ASSERT_MAIN_OUTPUT_THAT("moviesdatenight", input, HasSubstr(subTotal_string));
  }

}

TEST(MovieTickets, OutputFormat)
{
  std::string expected =  "Welcome to date night at the  Movies!\n"
                          "Tickets tonight can only be bought in pairs\n"
                          "Here are our movie ticket deals on Date Night:\n"
                          "Children - $10.00\n"
                          "Young Adults - $13.00\n"
                          "Adults - $15.00\n"
                          "Seniors - $10.00\n"
                          "Please enter the age of the person for the first guest: "
                          "Please enter the age of the person for the second guest: "
                          "The Subtotal for the ticket cost is: $26.00\n";
  ASSERT_MAIN_OUTPUT_EQ("moviesdatenight", "15 16", expected);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
