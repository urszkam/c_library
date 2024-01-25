#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "CUnit/Basic.h"

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define COLOR_RESET   "\x1b[0m"

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

void test_ft_isalnum() {
    // Test case 1: alphabetic char
    int result1 = ft_isalnum('H');
    int expected1 = 1;
    CU_ASSERT_EQUAL_FATAL(result1, expected1);
    printf("Test 1: ft_isalnum('H') - Result: %d, Expected: %d - %s\n",
        result1, expected1, (result1 == expected1) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 2: numeric char
    int result2 = ft_isalnum('3');
    int expected2 = 0;
    CU_ASSERT_EQUAL_FATAL(result2, expected2);
    printf("Test 2: ft_isalnum(\"Hello World123!!!\") - Result: %d, Expected: %d - %s\n",
        result2, expected2, (result2 == expected2) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 3: non-alphanum char
    int result3 = ft_isalnum('!');
    int expected3 = 0;
    CU_ASSERT_EQUAL_FATAL(result3, expected3);
    printf("Test 3: ft_isalnum(!) - Result: %d, Expected: %d - %s\n",
        result3, expected3, (result3 == expected3) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 4: empty char
    int result4 = ft_isalnum('');
    int expected4 = 0;
    CU_ASSERT_EQUAL_FATAL(result4, expected4);
    printf("Test 4: ft_isalnum('') - Result: %d, Expected: %d - %s\n",
        result4, expected4, (result4 == expected4) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 4: non-alphanum char
    int result4 = ft_isalnum('!');
    int expected4 = 0;
    CU_ASSERT_EQUAL_FATAL(result4, expected4);
    printf("Test 2: ft_isalnum('!') - Result: %d, Expected: %d - %s\n",
        result4, expected4, (result4 == expected4) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);
}

void test_ft_isalpha() {
    // Test case 1: lower case char
    int result1 = ft_isalpha('h');
    int expected1 = 1;
    CU_ASSERT_EQUAL_FATAL(result1, expected1);
    printf("Test 1: ft_isalpha('h') - Result: %d, Expected: %d - %s\n",
        result1, expected1, (result1 == expected1) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 2: upper case char
    int result2 = ft_isalpha('H');
    int expected2 = 1;
    CU_ASSERT_EQUAL_FATAL(result2, expected2);
    printf("Test 2: ft_isalpha('H') - Result: %d, Expected: %d - %s\n",
        result2, expected2, (result2 == expected2) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 3: non-alpha char
    int result3 = ft_isalpha('9');
    int expected3 = 0;
    CU_ASSERT_EQUAL_FATAL(result3, expected3);
    printf("Test 3: ft_isalpha('9') - Result: %d, Expected: %d - %s\n",
        result3, expected3, (result3 == expected3) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 4: NULL
    int result4 = ft_isalpha(0);
    int expected4 = 0;
    CU_ASSERT_EQUAL_FATAL(result4, expected4);
    printf("Test 4: ft_isalpha(0) - Result: %d, Expected: %d - %s\n",
        result4, expected4, (result4 == expected4) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);
}

void test_ft_isascii() {
    // Test case 1: ascii char: ~
    int result1 = ft_isascii(127);
    int expected1 = 1;
    CU_ASSERT_EQUAL_FATAL(result1, expected1);
    printf("Test 1: ft_isascii('~') - Result: %d, Expected: %d - %s\n",
        result1, expected1, (result1 == expected1) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 2: ascii char: \t
    int result2 = ft_isascii('\t');
    int expected2 = 1;
    CU_ASSERT_EQUAL_FATAL(result2, expected2);
    printf("Test 2: ft_isascii('\t') - Result: %d, Expected: %d - %s\n",
        result2, expected2, (result2 == expected2) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 3: NULL
    int result3 = ft_isascii(0);
    int expected3 = 1;
    CU_ASSERT_EQUAL_FATAL(result3, expected3);
    printf("Test 3: ft_isascii(0) - Result: %d, Expected: %d - %s\n",
        result3, expected3, (result3 == expected3) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 4: non-ascii char: below the lower limit
    int result4 = ft_isascii(-20);
    int expected4 = 0;
    CU_ASSERT_EQUAL_FATAL(result4, expected4);
    printf("Test 4: ft_isascii(-20) - Result: %d, Expected: %d - %s\n",
        result4, expected4, (result4 == expected4) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 5: non-ascii char: above the upper limit
    int result5 = ft_isascii(128);
    int expected5 = 0;
    CU_ASSERT_EQUAL_FATAL(result5, expected5);
    printf("Test 5: ft_isascii(120) - Result: %d, Expected: %d - %s\n",
        result5, expected5, (result5 == expected5) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);
}

void test_ft_isdigit() {
    // Test case 1: digit
    int result1 = ft_isdigit('9');
    int expected1 = 1;
    CU_ASSERT_EQUAL_FATAL(result1, expected1);
    printf("Test 1: ft_isdigit('9') - Result: %d, Expected: %d - %s\n",
        result1, expected1, (result1 == expected1) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 2: non-digit char
    int result2 = ft_isdigit('H');
    int expected2 = 0;
    CU_ASSERT_EQUAL_FATAL(result2, expected2);
    printf("Test 2: ft_isdigit('H') - Result: %d, Expected: %d - %s\n",
        result2, expected2, (result2 == expected2) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 3: NULL
    int result3 = ft_isdigit(0);
    int expected3 = 0;
    CU_ASSERT_EQUAL_FATAL(result3, expected3);
    printf("Test 3: ft_isdigit(0) - Result: %d, Expected: %d - %s\n",
        result3, expected3, (result3 == expected3) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);
}

void test_ft_isprint() {
    // Test case 1: space
    int result1 = ft_isprint(32);
    int expected1 = 1;
    CU_ASSERT_EQUAL_FATAL(result1, expected1);
    printf("Test 1: ft_isprint(32) - Result: %d, Expected: %d - %s\n",
        result1, expected1, (result1 == expected1) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 2: non-digit char
    int result2 = ft_isprint(127);
    int expected2 = 1;
    CU_ASSERT_EQUAL_FATAL(result2, expected2);
    printf("Test 2: ft_isprint(127) - Result: %d, Expected: %d - %s\n",
        result2, expected2, (result2 == expected2) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 3: under the lover limit
    int result3 = ft_isprint('\t');
    int expected3 = 0;
    CU_ASSERT_EQUAL_FATAL(result3, expected3);
    printf("Test 3: ft_isprint('\t') - Result: %d, Expected: %d - %s\n",
        result3, expected3, (result3 == expected3) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 4: above the upper limit
    int result4 = ft_isprint(128);
    int expected4 = 0;
    CU_ASSERT_EQUAL_FATAL(result4, expected4);
    printf("Test 4: ft_isprint(128) - Result: %d, Expected: %d - %s\n",
        result4, expected4, (result4 == expected4) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 5: NULL
    int result5 = ft_isprint(0);
    int expected5 = 0;
    CU_ASSERT_EQUAL_FATAL(result5, expected5);
    printf("Test 5: ft_isprint(0) - Result: %d, Expected: %d - %s\n",
        result5, expected5, (result5 == expected5) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);
}

void test_ft_strlen() {
    // Test case 1: Check if ft_strlen returns the correct length for a non-empty string
    size_t result1 = ft_strlen("Hello, World!");
    size_t expected1 = 13;
    CU_ASSERT_EQUAL_FATAL(result1, expected1);
    printf("Test 1: ft_strlen(\"Hello, World!\") - Result: %zu, Expected: %zu - %s\n",
        result1, expected1, (result1 == expected1) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 2: Check if ft_strlen returns 0 for an empty string
    size_t result2 = ft_strlen("");
    size_t expected2 = 0;
    CU_ASSERT_EQUAL_FATAL(result2, expected2);
    printf("Test 2: ft_strlen(\"\") - Result: %zu, Expected: %zu - %s\n", 
        result2, expected2, (result2 == expected2) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 3: NULLing
    size_t result3 = ft_strlen(0);
    size_t expected3 = 0;
    CU_ASSERT_EQUAL_FATAL(result3, expected3);
    printf("Test 3: ft_strlen(0) - Result: %zu, Expected: %zu - %s\n", 
        result3, expected3, (result3 == expected3) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);
}

void test_ft_toupper() {
    // Test case 1: lower case
    char result1 = ft_toupper('h');
    char expected1 = toupper('h');
    CU_ASSERT_EQUAL_FATAL(result1, expected1);
    printf("Test 1: ft_toupper('h') - Result: %c, Expected: %c - %s\n",
        result1, expected1, (result1 == expected1) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 2: non-digit char
    char result2 = ft_toupper('H');
    char expected2 = toupper('H');
    CU_ASSERT_EQUAL_FATAL(result2, expected2);
    printf("Test 2: ft_toupper('H') - Result: %c, Expected: %c - %s\n",
        result2, expected2, (result2 == expected2) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 3: NULL
    char result3 = ft_toupper(0);
    char expected3 = toupper(0);
    CU_ASSERT_EQUAL_FATAL(result3, expected3);
    printf("Test 3: ft_toupper(0) - Result: %c, Expected: %c - %s\n",
        result3, expected3, (result3 == expected3) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 4: non-alpha char
    char result4 = ft_toupper('@');
    char expected4 = toupper('@');
    CU_ASSERT_EQUAL_FATAL(result4, expected4);
    printf("Test 4: ft_toupper(0) - Result: %c, Expected: %c - %s\n",
        result4, expected4, (result4 == expected4) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);
}

void test_ft_strchr() {
    // Test case 1: existing character
    char* result1 = ft_strchr("Hello World!", 'o');
    char* expected1 = strchr("Hello World!", 'o');
    CU_ASSERT_PTR_EQUAL_FATAL(result1, expected1);
    printf("Test 1: ft_strchr(\"Hello World!\", 'o') - Result: %p, Expected: %p - %s\n",
        (void*)result1, (void*)expected1, (result1 == expected1) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 2: character not found in the string
    char* result2 = ft_strchr("Hello World!", 'x');
    CU_ASSERT_PTR_NULL_FATAL(result2);
    printf("Test 2: ft_strchr(\"Hello World!\", 'x') - Result: %p, Expected: NULL - %s\n",
        (void*)result2, (result2 == NULL) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 3: char is the only char in the string
    char* result3 = ft_strchr("x", 'x');
    char* expected3 = strchr("x", 'x');
    CU_ASSERT_PTR_EQUAL_FATAL(result3, expected3);
    printf("Test 3: ft_strchr(\"x\", 'x') - Result: %p, Expected: %p - %s\n",
        (void*)result1, (void*)expected1, (result1 == expected1) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 4: char is the \0 sing
    char* result4 = ft_strchr("Hello World!", '\0');
    char* expected4 = strchr("Hello World!", '\0');
    CU_ASSERT_PTR_EQUAL_FATAL(result4, expected4);
    printf("Test 4: ft_strchr(\"Hello World!\", 'o') - Result: %p, Expected: %p - %s\n",
        (void*)result4, (void*)expected4, (result4 == expected4) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 5: string is NULL
    char* result5 = ft_strchr(0, 'o');
    char* expected5 = strchr(0, 'o');
    CU_ASSERT_PTR_EQUAL_FATAL(result5, expected5);
    printf("Test 5: ft_strchr(NULL, 'o') - Result: %p, Expected: %p - %s\n",
        (void*)result5, (void*)expected5, (result5 == expected5) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);
}

void test_ft_strrchr() {
    // Test case 1: existing character
    char* result1 = ft_strrchr("Hello World!", 'o');
    char* expected1 = strrchr("Hello World!", 'o');
    CU_ASSERT_PTR_EQUAL_FATAL(result1, expected1);
    printf("Test 1: ft_strrchr(\"Hello World!\", 'o') - Result: %p, Expected: %p - %s\n",
        (void*)result1, (void*)expected1, (result1 == expected1) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 2: character not found in the string
    char* result2 = ft_strrchr("Hello World!", 'x');
    CU_ASSERT_PTR_NULL_FATAL(result2);
    printf("Test 2: ft_strrchr(\"Hello World!\", 'x') - Result: %p, Expected: NULL - %s\n",
        (void*)result2, (result2 == NULL) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 3: char is the only char in the string
    char* result3 = ft_strrchr("x", 'x');
    char* expected3 = strrchr("x", 'x');
    CU_ASSERT_PTR_EQUAL_FATAL(result3, expected3);
    printf("Test 3: ft_strrchr(\"x\", 'x') - Result: %p, Expected: %p - %s\n",
        (void*)result1, (void*)expected1, (result1 == expected1) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 4: char is the \0 sing
    char* result4 = ft_strrchr("Hello World!", '\0');
    char* expected4 = strrchr("Hello World!", '\0');
    CU_ASSERT_PTR_EQUAL_FATAL(result4, expected4);
    printf("Test 4: ft_strrchr(\"Hello World!\", 'o') - Result: %p, Expected: %p - %s\n",
        (void*)result4, (void*)expected4, (result4 == expected4) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);

    // Test case 5: string is NULL
    char* result5 = ft_strrchr(0, 'o');
    char* expected5 = strrchr(0, 'o');
    CU_ASSERT_PTR_EQUAL_FATAL(result5, expected5);
    printf("Test 5: ft_strrchr(NULL, 'o') - Result: %p, Expected: %p - %s\n",
        (void*)result5, (void*)expected5, (result5 == expected5) ? GREEN "PASS" : RED "FAIL", COLOR_RESET);
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
    CU_add_test(suite, "test_ft_isalnum", test_ft_isalnum);
    CU_add_test(suite, "test_ft_isalpha", test_ft_isalpha);
    CU_add_test(suite, "test_ft_isascii", test_ft_isascii);
    CU_add_test(suite, "test_ft_isdigit", test_ft_isdigit);
    CU_add_test(suite, "test_ft_isprint", test_ft_isdigit);

    // Run the tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}