#include "gtest/gtest.h"
#include "date.h"

using namespace std;

class DateTest : public ::testing::Test {
 public:
  void SetUp( ) { 
    // code here will execute just before the test ensues 
	first_day = Date(2018, 9, 4);
	last_day = Date(2018, 12, 11);
  }
 protected:
  Date first_day;          // first day of classes
  Date last_day;           // last day of classes
};

// Mutant: Dates from GetDate are missing a character
TEST_F(DateTest, MissingCharacterTest) 
{
  Date date(1999, 12, 31);              
  std::string expected_out = "1999-12-31";

  EXPECT_EQ(date.GetDate(), expected_out) << "test1: A Date Missing a character test fail";
}

// Mutant: Some dates don't have leading zeroes
TEST_F(DateTest, DataLeadingZerosTest) 
{
  Date date(2000, 01, 01);              
  std::string expected_out = "2000-01-01";

  EXPECT_EQ(date.GetDate(), expected_out) << "test2: A Date Leading zeroes test fail";
}

// Mutant: Today's date month off by one
TEST_F(DateTest, TodaysMonthoffbyoneTest) 
{
  Date date;
  std::string expected_out = "2021-02-22";
  
  EXPECT_EQ(date.GetDate(), expected_out) << "test3: A Date Deducting one month test fail";
}

// Mutant: Dates from GetUsDate are not in the right format (same as GetDate?)
TEST_F(DateTest, GetUsDateformatGetDateTest) 
{
  Date date(2000, 01, 01);
  
  EXPECT_NE(date.GetDate(), date.GetUsDate()) << "test4: A Date and USDate format test fail";
}

// Mutant: operator-: Probably a copy paste error
TEST_F(DateTest, MinusoperatorTest) 
{
  Date date(2000, 01, 01);
  Date yesterday = date-1;
  std::string expected_out = "1999-12-31";
  
  EXPECT_EQ(yesterday.GetDate(), expected_out) << "test5: copy paste test fail";
}

// Mutant: Days between calculation seems to be much larger than it should be
TEST_F(DateTest, DaysCalculationTest) 
{
  Date date1(1999, 12, 31);
  Date date2(2000, 01, 01);
  int val = 1;
  
  EXPECT_EQ(date1.DaysBetween(date2), val) << "test6: Days between is not calculated properly";
}

// Mutant: Developer thought months should be zero-indexed
TEST_F(DateTest, ZeroIndexTest) 
{
  Date date(0100, 01, 01);
  std::string expected_out1 = "2000-01-01";
  
  EXPECT_NE(date.GetDate(), expected_out1) << "test7: Worng index for month.";
}

// Dates constructed with epoch are about 70 years in the future
TEST_F(DateTest, EpochTest) 
{
  Date epoch(1536066000); // 70 years convert to this second
  std::string expected_out1 = "2018-09-04";
  
  EXPECT_EQ(epoch.GetDate(), expected_out1) << "test8: diffrent epoch used.";
}

// 1/1/2016 to 3/1/2016 is 60 days, but this version returns 59
TEST_F(DateTest, DaysBetweenTest) 
{
  Date date1(2016, 01, 01);
  Date date2(2016, 03, 01);

  int answer = date1.DaysBetween(date2);
  
  EXPECT_EQ(answer, 60) << "test9: this version of day calculation is wrong.";
}