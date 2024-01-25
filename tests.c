#include "libft.h"
#include <stdio.h>
#include <ctype.h>
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

void test_ft_isalnum()
{
    // Test case 1: alphabetic char
    int result1 = ft_isalnum('H');
    int expected1 = 1;
    CU_ASSERT_EQUAL(result1, expected1);
    printf("Test 1: ft_isalnum('H') - Result: %d, Expected: %d - %s\n",
           result1, expected1,
           (result1 == expected1) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 2: numeric char
    int result2 = ft_isalnum('3');
    int expected2 = 1;
    CU_ASSERT_EQUAL(result2, expected2);
    printf("Test 2: ft_isalnum('3') - Result: %d, Expected: %d - %s\n",
           result2, expected2,
           (result2 == expected2) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 3: non-alphanum char
    int result3 = ft_isalnum('!');
    int expected3 = 0;
    CU_ASSERT_EQUAL(result3, expected3);
    printf("Test 3: ft_isalnum('!') - Result: %d, Expected: %d - %s\n",
           result3, expected3,
           (result3 == expected3) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 4: non-alphanum char
    int result4 = ft_isalnum(0);
    int expected4 = 0;
    CU_ASSERT_EQUAL(result4, expected4);
    printf("Test 2: ft_isalnum(0) - Result: %d, Expected: %d - %s\n",
           result4, expected4,
           (result4 == expected4) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);
}

void test_ft_isalpha()
{
    // Test case 1: lower case char
    int result1 = ft_isalpha('h');
    int expected1 = 1;
    CU_ASSERT_EQUAL(result1, expected1);
    printf("Test 1: ft_isalpha('h') - Result: %d, Expected: %d - %s\n",
           result1, expected1,
           (result1 == expected1) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 2: upper case char
    int result2 = ft_isalpha('H');
    int expected2 = 1;
    CU_ASSERT_EQUAL(result2, expected2);
    printf("Test 2: ft_isalpha('H') - Result: %d, Expected: %d - %s\n",
           result2, expected2,
           (result2 == expected2) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 3: non-alpha char
    int result3 = ft_isalpha('9');
    int expected3 = 0;
    CU_ASSERT_EQUAL(result3, expected3);
    printf("Test 3: ft_isalpha('9') - Result: %d, Expected: %d - %s\n",
           result3, expected3,
           (result3 == expected3) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 4: NULL
    int result4 = ft_isalpha(0);
    int expected4 = 0;
    CU_ASSERT_EQUAL(result4, expected4);
    printf("Test 4: ft_isalpha(0) - Result: %d, Expected: %d - %s\n",
           result4, expected4,
           (result4 == expected4) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);
}

void test_ft_isascii()
{
    // Test case 1: ascii char: ~
    int result1 = ft_isascii(127);
    int expected1 = 1;
    CU_ASSERT_EQUAL(result1, expected1);
    printf("Test 1: ft_isascii('~') - Result: %d, Expected: %d - %s\n",
           result1, expected1,
           (result1 == expected1) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 2: ascii char: \t
    int result2 = ft_isascii('\t');
    int expected2 = 1;
    CU_ASSERT_EQUAL(result2, expected2);
    printf("Test 2: ft_isascii('\\t') - Result: %d, Expected: %d - %s\n",
           result2, expected2,
           (result2 == expected2) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 3: NULL
    int result3 = ft_isascii(0);
    int expected3 = 1;
    CU_ASSERT_EQUAL(result3, expected3);
    printf("Test 3: ft_isascii(0) - Result: %d, Expected: %d - %s\n",
           result3, expected3,
           (result3 == expected3) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 4: non-ascii char: below the lower limit
    int result4 = ft_isascii(-20);
    int expected4 = 0;
    CU_ASSERT_EQUAL(result4, expected4);
    printf("Test 4: ft_isascii(-20) - Result: %d, Expected: %d - %s\n",
           result4, expected4,
           (result4 == expected4) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 5: non-ascii char: above the upper limit
    int result5 = ft_isascii(128);
    int expected5 = 0;
    CU_ASSERT_EQUAL(result5, expected5);
    printf("Test 5: ft_isascii(120) - Result: %d, Expected: %d - %s\n",
           result5, expected5,
           (result5 == expected5) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);
}

void test_ft_isdigit()
{
    // Test case 1: digit
    int result1 = ft_isdigit('9');
    int expected1 = 1;
    CU_ASSERT_EQUAL(result1, expected1);
    printf("Test 1: ft_isdigit('9') - Result: %d, Expected: %d - %s\n",
           result1, expected1,
           (result1 == expected1) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 2: non-digit char
    int result2 = ft_isdigit('H');
    int expected2 = 0;
    CU_ASSERT_EQUAL(result2, expected2);
    printf("Test 2: ft_isdigit('H') - Result: %d, Expected: %d - %s\n",
           result2, expected2,
           (result2 == expected2) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 3: NULL
    int result3 = ft_isdigit(0);
    int expected3 = 0;
    CU_ASSERT_EQUAL(result3, expected3);
    printf("Test 3: ft_isdigit(0) - Result: %d, Expected: %d - %s\n",
           result3, expected3,
           (result3 == expected3) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);
}

void test_ft_isprint()
{
    // Test case 1: space
    int result1 = ft_isprint(32);
    int expected1 = isprint(32) != 0;
    CU_ASSERT_EQUAL(result1, expected1);
    printf("Test 1: ft_isprint(32) - Result: %d, Expected: %d - %s\n",
           result1, expected1,
           (result1 == expected1) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 2: non-digit char
    int result2 = ft_isprint(126);
    int expected2 = isprint(126) != 0;
    CU_ASSERT_EQUAL(result2, expected2);
    printf("Test 2: ft_isprint(127) - Result: %d, Expected: %d - %s\n",
           result2, expected2,
           (result2 == expected2) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 3: under the lover limit
    int result3 = ft_isprint('\t');
    int expected3 = isprint('\t') != 0;
    CU_ASSERT_EQUAL(result3, expected3);
    printf("Test 3: ft_isprint('\\t') - Result: %d, Expected: %d - %s\n",
           result3, expected3,
           (result3 == expected3) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 4: above the upper limit
    int result4 = ft_isprint(128);
    int expected4 = isprint(128) != 0;
    CU_ASSERT_EQUAL(result4, expected4);
    printf("Test 4: ft_isprint(128) - Result: %d, Expected: %d - %s\n",
           result4, expected4,
           (result4 == expected4) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 5: NULL
    int result5 = ft_isprint(0);
    int expected5 = isprint(0) != 0;
    CU_ASSERT_EQUAL(result5, expected5);
    printf("Test 5: ft_isprint(0) - Result: %d, Expected: %d - %s\n",
           result5, expected5,
           (result5 == expected5) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);
}

void test_ft_strlen()
{
    // Test case 1: length for a non-empty string
    size_t result1 = ft_strlen("Hello, World!");
    size_t expected1 = strlen("Hello, World!");
    CU_ASSERT_EQUAL(result1, expected1);
    printf("Test 1: ft_strlen(\"Hello, World!\") - Result: %zu, Expected: %zu - %s\n",
           result1, expected1,
           (result1 == expected1) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 2: 0 for an empty string
    size_t result2 = ft_strlen("");
    size_t expected2 = strlen("");
    CU_ASSERT_EQUAL(result2, expected2);
    printf("Test 2: ft_strlen(\"\") - Result: %zu, Expected: %zu - %s\n",
           result2, expected2,
           (result2 == expected2) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);
}

void test_ft_toupper()
{
    // Test case 1: lower case char
    char result1 = ft_toupper('h');
    char expected1 = toupper('h');
    CU_ASSERT_EQUAL(result1, expected1);
    printf("Test 1: ft_toupper('h') - Result: %c, Expected: %c - %s\n",
           result1, expected1,
           (result1 == expected1) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 2: upper case char
    char result2 = ft_toupper('H');
    char expected2 = toupper('H');
    CU_ASSERT_EQUAL(result2, expected2);
    printf("Test 2: ft_toupper('H') - Result: %c, Expected: %c - %s\n",
           result2, expected2,
           (result2 == expected2) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 3: NULL
    char result3 = ft_toupper(0);
    char expected3 = toupper(0);
    CU_ASSERT_EQUAL(result3, expected3);
    printf("Test 3: ft_toupper(0) - Result: %c, Expected: %c - %s\n",
           result3, expected3,
           (result3 == expected3) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 4: non-alpha char
    char result4 = ft_toupper('@');
    char expected4 = toupper('@');
    CU_ASSERT_EQUAL(result4, expected4);
    printf("Test 4: ft_toupper(@) - Result: %c, Expected: %c - %s\n",
           result4, expected4,
           (result4 == expected4) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);
}

void test_ft_tolower()
{
    // Test case 1: upper case
    char result1 = ft_tolower('H');
    char expected1 = tolower('H');
    CU_ASSERT_EQUAL(result1, expected1);
    printf("Test 1: ft_tolower('H') - Result: %c, Expected: %c - %s\n",
           result1, expected1,
           (result1 == expected1) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 2: lower case char
    char result2 = ft_tolower('h');
    char expected2 = tolower('h');
    CU_ASSERT_EQUAL(result2, expected2);
    printf("Test 2: ft_tolower('h') - Result: %c, Expected: %c - %s\n",
           result2, expected2,
           (result2 == expected2) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 3: NULL
    char result3 = ft_tolower(0);
    char expected3 = tolower(0);
    CU_ASSERT_EQUAL(result3, expected3);
    printf("Test 3: ft_tolower(0) - Result: %c, Expected: %c - %s\n",
           result3, expected3,
           (result3 == expected3) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 4: non-alpha char
    char result4 = ft_tolower('@');
    char expected4 = tolower('@');
    CU_ASSERT_EQUAL(result4, expected4);
    printf("Test 4: ft_tolower('@') - Result: %c, Expected: %c - %s\n",
           result4, expected4,
           (result4 == expected4) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);
}

void test_ft_strchr()
{
    // Test case 1: existing character
    char *result1 = ft_strchr("Hello World!", 'o');
    char *expected1 = strchr("Hello World!", 'o');
    CU_ASSERT_PTR_EQUAL(result1, expected1);
    printf("Test 1: ft_strchr(\"Hello World!\", 'o') - Result: %p, Expected: %p - %s\n",
           (void *)result1, (void *)expected1,
           (result1 == expected1) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 2: character not found in the string
    char *result2 = ft_strchr("Hello World!", 'x');
    CU_ASSERT_PTR_NULL_FATAL(result2);
    printf("Test 2: ft_strchr(\"Hello World!\", 'x') - Result: %p, Expected: NULL - %s\n",
           (void *)result2, (result2 == NULL) ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

    // Test case 3: char is the only char in the string
    char *result3 = ft_strchr("x", 'x');
    char *expected3 = strchr("x", 'x');
    CU_ASSERT_PTR_EQUAL(result3, expected3);
    printf("Test 3: ft_strchr(\"x\", 'x') - Result: %p, Expected: %p - %s\n",
           (void *)result3, (void *)expected3,
           (result3 == expected3) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 4: char is \0
    char *result4 = ft_strchr("Hello World!", '\0');
    char *expected4 = strchr("Hello World!", '\0');
    CU_ASSERT_PTR_EQUAL(result4, expected4);
    printf("Test 4: ft_strchr(\"Hello World!\", 'o') - Result: %p, Expected: %p - %s\n",
           (void *)result4, (void *)expected4,
           (result4 == expected4) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);
}

void test_ft_strrchr()
{
    // Test case 1: existing character
    char *result1 = ft_strrchr("Hello World!", 'o');
    char *expected1 = strrchr("Hello World!", 'o');
    CU_ASSERT_PTR_EQUAL(result1, expected1);
    printf("Test 1: ft_strrchr(\"Hello World!\", 'o') - Result: %p, Expected: %p - %s\n",
           (void *)result1, (void *)expected1,
           (result1 == expected1) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 2: character not found in the string
    char *result2 = ft_strrchr("Hello World!", 'x');
    CU_ASSERT_PTR_NULL_FATAL(result2);
    printf("Test 2: ft_strrchr(\"Hello World!\", 'x') - Result: %p, Expected: NULL - %s\n",
           (void *)result2,
           (result2 == NULL) ? GREEN "PASS" COLOR_RESET
                             : RED "FAIL" COLOR_RESET);

    // Test case 3: char is the only char in the string
    char *result3 = ft_strrchr("x", 'x');
    char *expected3 = strrchr("x", 'x');
    CU_ASSERT_PTR_EQUAL(result3, expected3);
    printf("Test 3: ft_strrchr(\"x\", 'x') - Result: %p, Expected: %p - %s\n",
           (void *)result3, (void *)expected3,
           (result3 == expected3) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 4: char is \0
    char *result4 = ft_strrchr("Hello World!", '\0');
    char *expected4 = strrchr("Hello World!", '\0');
    CU_ASSERT_PTR_EQUAL(result4, expected4);
    printf("Test 4: ft_strrchr(\"Hello World!\", 'o') - Result: %p, Expected: %p - %s\n",
           (void *)result4, (void *)expected4,
           (result4 == expected4) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);
}

void test_ft_strncmp()
{
    // Test case 1: existing character
    int result1 = ft_strncmp("HeLlo", "Hello", 7);
    int expected1 = strncmp("HeLlo", "Hello", 7);
    CU_ASSERT_EQUAL(result1, expected1);
    printf("Test 1: ft_strncmp(\"HeLlo\", \"Hello\", 7) - Result: %d, Expected: %d - %s\n",
           result1, expected1,
           (result1 == expected1) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);
    // Test case 2: character not found in the string
    int result2 = ft_strncmp("HeLlo", "Hello", 0);
    int expected2 = strncmp("HeLlo", "Hello", 0);
    CU_ASSERT_EQUAL(result2, expected2);
    printf("Test 2: ft_strncmp(\"HeLlo\", \"Hello\", 0) - Result: %d, Expected: %d - %s\n",
           result2, expected2,
           (result2 == expected2) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 3: intis the only intin the string
    int result3 = ft_strncmp("Hello", "HeLlo", 7);
    int expected3 = strncmp("Hello", "HeLlo", 7);
    CU_ASSERT_EQUAL(result3, expected3);
    printf("Test 3: ft_strncmp(\"Hello\", \"HeLlo\", 7) - Result: %d, Expected: %d - %s\n",
           result3, expected3,
           (result3 == expected3) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 4: intis \0
    int result4 = ft_strncmp("Hello", "Hello", 7);
    int expected4 = strncmp("Hello", "Hello", 7);
    CU_ASSERT_EQUAL(result4, expected4);
    printf("Test 4: ft_strncmp(\"Hello\", \"Hello\", 7) - Result: %d, Expected: %d - %s\n",
           result4, expected4,
           (result4 == expected4) ? GREEN "PASS" COLOR_RESET
                                  : RED "FAIL" COLOR_RESET);

    // Test case 5: string is NULL
    int result5 = ft_strncmp("", "Hell", 2);
    int expected5 = strncmp("", "Hell", 2);
    CU_ASSERT_EQUAL(result5, expected5);
    printf("Test 5: ft_strncmp(\"\", \"Hell\", 2) - Result: %d, Expected: %d - %s\n",
           result5, expected5,
           (result5 == expected5) ? GREEN "PASS" COLOR_RESET
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
    CU_pSuite suite = CU_add_suite("Suite Name", init_suite, clean_suite);
    if (NULL == suite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add your test functions to the suite
    CU_add_test(suite, BLUE "test_ft_isalnum\n" COLOR_RESET, test_ft_isalnum);
    CU_add_test(suite, BLUE "test_ft_isalpha\n" COLOR_RESET, test_ft_isalpha);
    CU_add_test(suite, BLUE "test_ft_isascii\n" COLOR_RESET, test_ft_isascii);
    CU_add_test(suite, BLUE "test_ft_isdigit\n" COLOR_RESET, test_ft_isdigit);
    CU_add_test(suite, BLUE "test_ft_isprint\n" COLOR_RESET, test_ft_isprint);
    CU_add_test(suite, BLUE "test_ft_toupper\n" COLOR_RESET, test_ft_toupper);
    CU_add_test(suite, BLUE "test_ft_tolower\n" COLOR_RESET, test_ft_tolower);
    CU_add_test(suite, BLUE "test_ft_strlen\n" COLOR_RESET, test_ft_strlen);
    CU_add_test(suite, BLUE "test_ft_strchr\n" COLOR_RESET, test_ft_strchr);
    CU_add_test(suite, BLUE "test_ft_strrchr\n" COLOR_RESET, test_ft_strrchr);
    CU_add_test(suite, BLUE "test_ft_strncmp\n" COLOR_RESET, test_ft_strncmp);

    // Run the tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}