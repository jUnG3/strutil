#include "strutil.h"
#include <gtest/gtest.h>

TEST(StrExplode, explode_empty_delimiter)
{
    char const* src = "GET / HTTP1.1";
    explode_t* r = strexplode(src, "");
    EXPECT_STREQ(r->result[0], src);
    ASSERT_EQ(r->size, 1);
    strexplode_free(r);
}

TEST(StrExplode, explode_empty_src)
{
    char const* src = "";
    explode_t* r = strexplode(src, " ");
    EXPECT_STREQ(r->result[0], src);
    ASSERT_EQ(r->size, 1);
    strexplode_free(r);
}

TEST(StrExplode, explode_1)
{
    char const* src = "Hello World";
    explode_t* r = strexplode(src, " ");
    EXPECT_STREQ(r->result[0], "Hello");
    EXPECT_STREQ(r->result[1], "World");
    ASSERT_EQ(r->size, 2);
    strexplode_free(r);
}

TEST(StrExplode, explode_2)
{
    char const* src = "GET / HTTP1.1";
    explode_t* r = strexplode(src, " ");
    EXPECT_STREQ(r->result[0], "GET");
    EXPECT_STREQ(r->result[1], "/");
    EXPECT_STREQ(r->result[2], "HTTP1.1");
    ASSERT_EQ(r->size, 3);
    strexplode_free(r);
}

TEST(StrExplode, explode_3)
{
    char const* src = "GET / HTTP1.1";
    explode_t* r = strexplode(src, " ");
    explode_t* r1 = strexplode(r->result[2], ".");
    EXPECT_STREQ(r->result[0], "GET");
    EXPECT_STREQ(r->result[1], "/");
    EXPECT_STREQ(r->result[2], "HTTP1.1");
    ASSERT_EQ(r->size, 3);
    EXPECT_STREQ(r1->result[0], "HTTP1");
    EXPECT_STREQ(r1->result[1], "1");
    strexplode_free(r);
    strexplode_free(r1);
}
