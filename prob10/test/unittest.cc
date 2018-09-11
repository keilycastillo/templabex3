#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <cmath>
#include "gtest_ext.h"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;



TEST(Salary, OutputFormat)
{
  std::string expected = "Hourly Wage: "
                      "Hours Worked: "
                      "Total Salary Owed: $1825.00\n";
  ASSERT_MAIN_OUTPUT_EQ("salary-calculator", "25 62", expected);
}

TEST(Salary, FourtyOrLessHrs)
{
  for(int i = 0; i < 10; i++)
  {
    int hourlyWage = rand() % 70;
    int hoursWorked = rand()% 40;
    std::string input = std::to_string(hourlyWage) + " " + std::to_string(hoursWorked);
    int totalSalary =  hourlyWage * hoursWorked;
    std::string total_string = "Total Salary Owed: $" + to_string_double(totalSalary)+ "\n";
    ASSERT_MAIN_OUTPUT_THAT("salary-calculator", input, HasSubstr(total_string));
  }
}

TEST(Salary, SixtyFiveOrLessHrs)
{
  for(int i = 0; i < 10; i++)
  {
    int hourlyWage = rand() % 70;
    int hoursWorked = rand() % 10 + 55;
    std::string input = std::to_string(hourlyWage) + " " + std::to_string(hoursWorked);
    double totalSalary = (hourlyWage * 40.0) + (hourlyWage * 1.5) * (hoursWorked - 40);
    std::string total_string = "Total Salary Owed: $" + to_string_double(totalSalary)+ "\n";
    ASSERT_MAIN_OUTPUT_THAT("salary-calculator", input, HasSubstr(total_string));
  }
}

TEST(Salary, OverSixtyFiveHrs)
{
  for(int i = 0; i < 10; i++)
  {
    int hourlyWage = rand() % 70;
    int hoursWorked = rand() % 20 + 66;
    std::string input = std::to_string(hourlyWage) + " " + std::to_string(hoursWorked);
    double totalSalary = (hourlyWage * 40) + (hourlyWage * 1.5) * 25 + (hoursWorked - 65) * (hourlyWage * 2);
    std::string total_string = "Total Salary Owed: $" + to_string_double(totalSalary)+ "\n";
    ASSERT_MAIN_OUTPUT_THAT("salary-calculator", input, HasSubstr(total_string));
  }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
