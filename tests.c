#include "libft.h"
#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"

/* Initialize and Cleanup Functions */
int init_suite() {
    // Your initialization code, if any
    return 0;
}

int clean_suite() {
    // Your cleanup code, if any
    return 0;
}

/* Function Tests */ 
void test_ft_isalpha() {
    // Test case 1: Check if ft_isalpha returns the correct int for an alphabetic string
    size_t result1 = ft_isalpha("Hello");
    size_t expected1 = 1;
    CU_ASSERT_EQUAL_FATAL(result1, expected1);
    printf("Test 1: ft_isalpha(\"Hello\") - Result: %d, Expected: %d - %s\n",
        result1, expected1, (result1 == expected1) ? "PASS" : "FAIL");

    // Test case 2: Check if ft_isalpha returns the correct int for a non-alphabetic string
    size_t result2 = ft_isalpha("Hello World!!!");
    size_t expected2 = 0;
    CU_ASSERT_EQUAL_FATAL(result2, expected2);
    printf("Test 2: ft_isalpha(\"Hello World!!!\") - Result: %d, Expected: %d - %s\n",
        result2, expected2, (result2 == expected2) ? "PASS" : "FAIL");

    // Test case 3: Check if ft_isalpha returns the correct int for a NULL
    size_t result3 = ft_strlen(0);
    size_t expected3 = 0;
    CU_ASSERT_EQUAL_FATAL(result3, expected3);
    printf("Test 3: ft_isalpha(0) - Result: %d, Expected: %d - %s\n",
        result3, expected3, (result3 == expected3) ? "PASS" : "FAIL");

}

void test_ft_strlen() {
    // Test case 1: Check if ft_strlen returns the correct length for a non-empty string
    size_t result1 = ft_strlen("Hello, World!");
    size_t expected1 = 13;
    CU_ASSERT_EQUAL_FATAL(result1, expected1);
    printf("Test 1: ft_strlen(\"Hello, World!\") - Result: %zu, Expected: %zu - %s\n",
        result1, expected1, (result1 == expected1) ? "PASS" : "FAIL");

    // Test case 2: Check if ft_strlen returns 0 for an empty string
    size_t result2 = ft_strlen("");
    size_t expected2 = 0;
    CU_ASSERT_EQUAL_FATAL(result2, expected2);
    printf("Test 2: ft_strlen(\"\") - Result: %zu, Expected: %zu - %s\n", 
        result2, expected2, (result2 == expected2) ? "PASS" : "FAIL");

    // Add more test cases as needed
}

void test_ft_strrchr() {
    // Test case 1: Check if ft_strrchr returns the correct pointer for an existing character
    char* result1 = ft_strrchr("Hello World!", 'o');
    char* expected1 = strrchr("Hello World!", 'o');
    CU_ASSERT_PTR_EQUAL_FATAL(result1, expected1);
    printf("Test 1: ft_strrchr(\"Hello World!\", 'o') - Result: %p, Expected: %p - %s\n",
        (void*)result1, (void*)expected1, (result1 == expected1) ? "PASS" : "FAIL");

    // Test case 2: Check if ft_strrchr returns NULL for a character not found in the string
    char* result2 = ft_strrchr("Hello World!", 'x');
    CU_ASSERT_PTR_NULL_FATAL(result2);
    printf("Test 2: ft_strrchr(\"Hello World!\", 'x') - Result: %p, Expected: NULL - %s\n",
        (void*)result2, (result2 == NULL) ? "PASS" : "FAIL");
}

int main() {
    // Initialize CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    // Add your test suite
    CU_pSuite suite = CU_add_suite("Suite Name", init_suite, clean_suite);
    if (NULL == suite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add your test functions to the suite
    CU_add_test(suite, "test_ft_strlen", test_ft_strlen);
    CU_add_test(suite, "test_ft_strrchr", test_ft_strrchr);
    CU_add_test(suite, "test_ft_isalpha", test_ft_isalpha);

    // Run the tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}