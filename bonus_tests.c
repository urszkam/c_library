#include "libft.h"
#include <stdio.h>
#include "CUnit/Basic.h"

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define COLOR_RESET "\x1b[0m"

/* Initialize and Cleanup Functions */
int init_suite()
{
    return 0;
}

int clean_suite()
{
    return 0;
}

/* Function Tests */
void test_()
{
    // Test case 1:
    char *result1 = ;
    char *expected1 = ;
    CU_ASSERT_PTR_EQUAL(result1, expected1);
    printf("Test 1:  - Result: %p, Expected: %p - %s\n",
           (void *)result1, (void *)expected1,
           (result1 == expected1) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);
}

int main()
{
    // Initialize CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }

    // Add your test suite
    CU_pSuite suite = CU_add_suite("Bonus Functions", init_suite, clean_suite);
    if (NULL == suite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add your test functions to the suite
    CU_add_test(suite, BLUE "test_ft_isalnum\n" COLOR_RESET, test_ft_isalnum);

    // Run the tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}