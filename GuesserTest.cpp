/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(GuesserTest, Capitalize_test)
{
  Guesser object("Celebrate");
  ASSERT_FALSE(object.match("CeleBrate")); // Try 1
  ASSERT_EQ(object.remaining(), 1);

  ASSERT_FALSE(object.match("Celebratexxx")); // Try 2
  ASSERT_EQ(object.remaining(), 3);

  ASSERT_FALSE(object.match("Celebrate")); // Locked
  ASSERT_EQ(object.remaining(), 0);
}
TEST(GuesserTest, Happy_test)
{
  Guesser object("Happy");
  ASSERT_TRUE(object.match("Happy")); // Try 2
  ASSERT_EQ(object.remaining(), 0);
}
TEST(GuesserTest, ExtraChar_test)
{
  Guesser object("Password");
  ASSERT_FALSE(object.match("PasswordMotel")); // Try 1
  ASSERT_EQ(object.remaining(), 5);

  ASSERT_FALSE(object.match("PasswordAppleEWQ")); // Try 2
  ASSERT_EQ(object.remaining(), 8);
}
TEST(GuesserTest, LessChar_test)
{
  Guesser object("Secret");
  ASSERT_FALSE(object.match("sec")); // Try 1
  ASSERT_EQ(object.remaining(), 4);

  ASSERT_FALSE(object.match("Secr")); // Try 2
  ASSERT_EQ(object.remaining(), 2);
}
