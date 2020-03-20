#include <CUnit/Basic.h>
#include <CUnit/Basic.h>
#include "trim_test.c"
#include "strexplode_test.c"

int main()
{
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error(); // Sets the basic run mode, CU_BRM_VERBOSE will show maximum output of run details
    }

    CU_pSuite pSuite = NULL;

    // Add a suite to the registry
    pSuite = CU_add_suite("strutil", 0, 0);

    // Always check if add was successful
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_add_test(pSuite, "explode_1_test", explode_1_test);
    CU_add_test(pSuite, "explode_2_test", explode_1_test);
    CU_add_test(pSuite, "explode_empty_delimiter_test", explode_empty_delimiter_test);
    CU_add_test(pSuite, "explode_empty_src_test", explode_empty_src_test);

    CU_add_test(pSuite, "trim_empty_string_test", trim_empty_string_test);
    CU_add_test(pSuite, "trim_begining_test", trim_begining_test);
    CU_add_test(pSuite, "trim_ending_test", trim_ending_test);
    CU_add_test(pSuite, "trim_both_test", trim_both_test);

    // Sets the basic run mode, CU_BRM will show maximum output of run details
    // Other choices are: CU_BRM_SILENT and CU_BRM_NORMAL
    CU_basic_set_mode(CU_BRM_VERBOSE);

    // Configure filename
    CU_set_output_filename("bin/Test");

    // Run the tests and show the run summary
    CU_basic_run_tests();
    CU_automated_run_tests();
    return CU_get_error();
}
