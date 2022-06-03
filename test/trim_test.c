#include "trim_test.h"
#include <CUnit/CUnit.h>
#include <strutil.h>

void
trim_empty_string_test()
{
    char* empty = "";
    char* expected = "";
    CU_ASSERT_STRING_EQUAL(trim(empty), expected);
}

void
trim_begining_test()
{
    char* src = " \n\v\f\r\tHello World";
    char* expected = "Hello World";
    CU_ASSERT_STRING_EQUAL(trim(src), expected);
}

void
trim_ending_test()
{
    char* src = "Hello World \n\v\f\r\t";
    char* expected = "Hello World";
    CU_ASSERT_STRING_EQUAL(trim(src), expected);
}

void
trim_both_test()
{
    char* src = "\n\v\f\r\t Hello World \n\v\f\r\t";
    char* expected = "Hello World";
    CU_ASSERT_STRING_EQUAL(trim(src), expected);
}
