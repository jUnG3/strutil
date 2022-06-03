#include "strexplode_test.h"
#include <CUnit/CUnit.h>
#include <strutil.h>

void
explode_empty_delimiter_test()
{
    char* src = "GET / HTTP1.1";
    explode_t* r = strexplode(src, "");
    CU_ASSERT_STRING_EQUAL(r->result[0], src);
    CU_ASSERT_EQUAL(r->size, 1);
    strexplode_free(r);
}

void
explode_empty_src_test()
{
    char* src = "";
    explode_t* r = strexplode(src, " ");
    CU_ASSERT_STRING_EQUAL(r->result[0], src);
    CU_ASSERT_EQUAL(r->size, 1);
    strexplode_free(r);
}

void
explode_1_test()
{
    char* src = "Hello World";
    explode_t* r = strexplode(src, " ");
    CU_ASSERT_STRING_EQUAL(r->result[0], "Hello");
    CU_ASSERT_STRING_EQUAL(r->result[1], "World");
    CU_ASSERT_EQUAL(r->size, 2);
    strexplode_free(r);
}

void
explode_2_test()
{
    char* src = "GET / HTTP1.1";
    explode_t* r = strexplode(src, " ");
    CU_ASSERT_STRING_EQUAL(r->result[0], "GET");
    CU_ASSERT_STRING_EQUAL(r->result[1], "/");
    CU_ASSERT_STRING_EQUAL(r->result[2], "HTTP1.1");
    CU_ASSERT_EQUAL(r->size, 3);
    strexplode_free(r);
}

void
explode_3_test()
{
    char* src = "GET / HTTP1.1";
    explode_t* r = strexplode(src, " ");
    explode_t* r1 = strexplode(r->result[2], ".");
    CU_ASSERT_STRING_EQUAL(r->result[0], "GET");
    CU_ASSERT_STRING_EQUAL(r->result[1], "/");
    CU_ASSERT_STRING_EQUAL(r->result[2], "HTTP1.1");
    CU_ASSERT_EQUAL(r->size, 3);
    CU_ASSERT_STRING_EQUAL(r1->result[0], "HTTP1");
    CU_ASSERT_STRING_EQUAL(r1->result[1], "1");
    strexplode_free(r);
    strexplode_free(r1);
}
