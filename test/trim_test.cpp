#include "strutil.h"
#include <gtest/gtest.h>

TEST(Trim, empty_string_test)
{
    char const* src = "";
    char const* expected = "";
    char* result = trim(src);
    EXPECT_STREQ(result, expected);
    free(result);
}

TEST(Trim, trim_begining_test)
{
    char const* src = " \n\v\f\r\tHello World";
    char const* expected = "Hello World";
    char* result = trim(src);
    EXPECT_STREQ(result, expected);
    free(result);
}

TEST(Trim, trim_ending_test)
{
    char const* src = "Hello World \n\v\f\r\t";
    char const* expected = "Hello World";
    char* result = trim(src);
    EXPECT_STREQ(result, expected);
    free(result);
}

TEST(Trim, trim_both_test)
{
    char const* src = "\n\v\f\r\t Hello World \n\v\f\r\t";
    char const* expected = "Hello World";
    char* result = trim(src);
    EXPECT_STREQ(result, expected);
    free(result);
}
