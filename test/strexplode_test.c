#include <CUnit/CUnit.h>
#include <CUnit/Automated.h>
#include <strutil.h>
#include <stdio.h>

void explode_empty_delimiter_test()
{
    char *src = "GET / HTTP1.1";
    explode_t *r = strexplode(src, "");
    CU_ASSERT_STRING_EQUAL(r->result[0], src);
    CU_ASSERT_EQUAL(r->size, 1);
}

void explode_empty_src_test()
{
    char *src = "";
    explode_t *r = strexplode(src, " ");
    CU_ASSERT_STRING_EQUAL(r->result[0], src);
    CU_ASSERT_EQUAL(r->size, 1);
}

void explode_1_test()
{
    char *src = "Hello World";
    explode_t *r = strexplode(src, " ");
    CU_ASSERT_STRING_EQUAL(r->result[0], "Hello");
    CU_ASSERT_STRING_EQUAL(r->result[1], "World");
    CU_ASSERT_EQUAL(r->size, 2);
}

void explode_2_test()
{
    char *src = "GET / HTTP1.1";
    explode_t *r = strexplode(src, " ");
    CU_ASSERT_STRING_EQUAL(r->result[0], "GET");
    CU_ASSERT_STRING_EQUAL(r->result[1], "/");
    CU_ASSERT_STRING_EQUAL(r->result[2], "HTTP1.1");
    CU_ASSERT_EQUAL(r->size, 3);
}
