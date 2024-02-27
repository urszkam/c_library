#include "libft.h"
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
//#include "CUnit/Basic.h"

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

static bool arePtrEqual(const void* ptr1, const void* ptr2) {
    return ptr1 == ptr2;
}

static char caesarEncrypt(unsigned int i, char c)
{
       if (c >= 'A' && c <= 'Z')
              c = (c - 'A' + i) % 26 + 'A';
       else if (c >= 'a' && c <= 'z')
              c = (c - 'a' + i) % 26 + 'a';
       return (c);
}

static void a_to_X(unsigned int i, char *c)
{
       if (*c == 'a' && i % 2 == 0)
              *c = 'X';
}

/* Function Tests */

void test_ft_memset()
{
    // Test case 1: filling an empty buffer
    char buffer1[10];
    char expected1[10];

    ft_memset(buffer1, 'A', 3);
    memset(expected1, 'A', 3);
    int result1 = memcmp(buffer1, expected1, sizeof(buffer1)) == 0;
    printf("Test 1: ft_memset(buffer[10], 'A', 3) - Result: %s, Expected: %s - %s\n",
        buffer1, expected1, result1 ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

    // Test case 2: filling an entire buffer with a constant value
    char buffer2[5] = "Test";
    char expected2[5] = "Test";

    ft_memset(buffer2, 'X', sizeof(buffer2) - 1);
    memset(expected2, 'X', sizeof(expected2) - 1);
    int result2 = memcmp(buffer2, expected2, sizeof(buffer2) - 1) == 0;
    printf("Test 2: ft_memset(\"Test\", 'X', sizeof(buffer2) - 1) - Result: %s, Expected: %s - %s\n",
        buffer2, expected2, result2 ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    
    // Test case 3: filling part of a buffer with a constant value
    char buffer3[9] = {'L', 'o', 'v', 'e', ' ', 'Y', 'o', 'u', 0};
    char expected3[9] = {'L', 'o', 'v', 'e', ' ', 'Y', 'o', 'u', 0};

    ft_memset(buffer3 + 3, 'X', 3);
    memset(expected3 + 3, 'X', 3);
    int result3 = memcmp(buffer3, expected3, sizeof(buffer3)) == 0;
    printf("Test 3: ft_memset(\"Love You\" + 3, 'X', 3) - Result: %s, Expected: %s - %s\n",
        buffer3, expected3, result3 ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

void test_ft_bzero()
{
    // Test case 1: zeroing out a non-empty buffer
    char buffer1[10] = "Hello";
    char expected1[10] = "Hello";

    ft_bzero(buffer1, 1);
    bzero(expected1, 1);
    int result1 = memcmp(buffer1, expected1, sizeof(buffer1)) == 0;
    printf("Test 1: ft_bzero(\"Hello\", 1) - Result: %s, Expected: %s - %s\n",
        buffer1+1, expected1+1, result1 ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

    // Test case 2: zeroing out an entire buffer
    char buffer2[5] = "Test";
    char expected2[5] = "Test";

    ft_bzero(buffer2, sizeof(buffer2) - 1);
    bzero(expected2, sizeof(expected2) - 1);
    int result2 = memcmp(buffer2, expected2, sizeof(buffer2)) == 0;
    printf("Test 2: ft_bzero(\"Test\", sizeof(buffer) - 1) - Result: %s, Expected: %s - %s\n",
        buffer2, expected2, result2 ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    
    // Test case 3: zeroing out part of a buffer
    char buffer3[9] = {'L', 'o', 'v', 'e', ' ', 'y', 'o', 'u', 0};
    char expected3[9] = {'L', 'o', 'v', 'e', ' ', 'y', 'o', 'u', 0};

    ft_bzero(buffer3 + 3, 3);
    bzero(expected3 + 3, 3);
    int result3 = memcmp(buffer3, expected3, sizeof(buffer3)) == 0;
    printf("Test 3: ft_bzero(\"Love You\" + 3, 3) - Result: %s, Expected: %s - %s\n",
        buffer3, expected3, result3 ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

void test_ft_memcpy()
{
    char source1[10] = "Hello";
    char destination1[10] = "World";
    char expectedDestination1[10] = "Hello";

    // Test case 1: copying from a non-empty source to a non-empty destination
    ft_memcpy(destination1, source1, 5);
    int result1 = memcmp(destination1, expectedDestination1, sizeof(destination1)) == 0;
    printf("Test 1: ft_memcpy(destination1, source1, 5) - Result: %s\n", result1 ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

    char source2[5] = "Test";
    char destination2[5] = "";
    char expectedDestination2[5] = "Test";

    // Test case 2: copying from a non-empty source to an empty destination
    ft_memcpy(destination2, source2, sizeof(source2));
    int result2 = memcmp(destination2, expectedDestination2, sizeof(destination2)) == 0;
    printf("Test 2: ft_memcpy(destination2, source2, sizeof(source2)) - Result: %s\n", result2 ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    
    // Test case 3: copying from a non-empty source to part of a destination
    char source3[8] = "Partial";
    char destination3[8] = "XXXXXXX";
    char expectedDestination3[8] = "PartXXX";

    ft_memcpy(destination3 + 3, source3, 4);
    int result3 = memcmp(destination3, expectedDestination3, sizeof(destination3)) == 0;
    printf("Test 3: ft_memcpy(destination3 + 3, source3, 4) - Result: %s\n", result3 ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

void test_ft_memmove()
{
    char source1[10] = "Hello";
    char destination1[10] = "World";
    char expectedDestination1[10] = "Hello";

    // Test case 1: moving from a non-empty source to a non-empty destination
    ft_memmove(destination1, source1, 5);
    int result1 = memcmp(destination1, expectedDestination1, sizeof(destination1)) == 0;
    printf("Test 1: ft_memmove(destination1, source1, 5) - Result: %s\n", result1 ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

    char source2[5] = "Test";
    char destination2[5] = "";
    char expectedDestination2[5] = "Test";

    // Test case 2: moving from a non-empty source to an empty destination
    ft_memmove(destination2, source2, sizeof(source2));
    int result2 = memcmp(destination2, expectedDestination2, sizeof(destination2)) == 0;
    printf("Test 2: ft_memmove(destination2, source2, sizeof(source2)) - Result: %s\n", result2 ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    
    // Test case 3: overlapping move from a non-empty source to part of a destination
    char source3[8] = "Partial";
    char destination3[8] = "XXXXXXX";
    char expectedDestination3[8] = "PartXXX";

    ft_memmove(destination3 + 3, source3, 4);
    int result3 = memcmp(destination3, expectedDestination3, sizeof(destination3)) == 0;
    printf("Test 3: ft_memmove(destination3 + 3, source3, 4) - Result: %s\n", result3 ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

void test_ft_isalnum()
{
       // Test case 1: alphabetic char
       int result1 = ft_isalnum('H');
       int expected1 = 1;
       int result = result1 == expected1;
       printf("Test 1: ft_isalnum('H') - Result: %d, Expected: %d - %s\n",
              result1, expected1,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 2: numeric char
       int result2 = ft_isalnum('3');
       int expected2 = 1;
       result = result2 == expected2;
       printf("Test 2: ft_isalnum('3') - Result: %d, Expected: %d - %s\n",
              result2, expected2,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 3: non-alphanum char
       int result3 = ft_isalnum('!');
       int expected3 = 0;
       result = result3 == expected3;
       printf("Test 3: ft_isalnum('!') - Result: %d, Expected: %d - %s\n",
              result3, expected3,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 4: non-alphanum char
       int result4 = ft_isalnum(0);
       int expected4 = 0;
       result = result4 == expected4;
       printf("Test 2: ft_isalnum(0) - Result: %d, Expected: %d - %s\n",
              result4, expected4,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

void test_ft_isalpha()
{
       // Test case 1: lower case char
       int result1 = ft_isalpha('h');
       int expected1 = 1;
       result = result1 == expected1;
       printf("Test 1: ft_isalpha('h') - Result: %d, Expected: %d - %s\n",
              result1, expected1,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 2: upper case char
       int result2 = ft_isalpha('H');
       int expected2 = 1;
       result = result2 == expected2;
       printf("Test 2: ft_isalpha('H') - Result: %d, Expected: %d - %s\n",
              result2, expected2,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 3: non-alpha char
       int result3 = ft_isalpha('9');
       int expected3 = 0;
       result = result3 == expected3;
       printf("Test 3: ft_isalpha('9') - Result: %d, Expected: %d - %s\n",
              result3, expected3,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 4: NULL
       int result4 = ft_isalpha(0);
       int expected4 = 0;
       result = result4 == expected4;
       printf("Test 4: ft_isalpha(0) - Result: %d, Expected: %d - %s\n",
              result4, expected4,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

void test_ft_isascii()
{
       // Test case 1: ascii char: ~
       int result1 = ft_isascii(127);
       int expected1 = 1;
       int result = result1 == expected1;
       printf("Test 1: ft_isascii('~') - Result: %d, Expected: %d - %s\n",
              result1, expected1,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 2: ascii char: \t
       int result2 = ft_isascii('\t');
       int expected2 = 1;
       result = result2 == expected2;
       printf("Test 2: ft_isascii('\\t') - Result: %d, Expected: %d - %s\n",
              result2, expected2,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 3: NULL
       int result3 = ft_isascii(0);
       int expected3 = 1;
       result = result3 == expected3;
       printf("Test 3: ft_isascii(0) - Result: %d, Expected: %d - %s\n",
              result3, expected3,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 4: non-ascii char: below the lower limit
       int result4 = ft_isascii(-20);
       int expected4 = 0;
       result = result4 == expected4;
       printf("Test 4: ft_isascii(-20) - Result: %d, Expected: %d - %s\n",
              result4, expected4,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 5: non-ascii char: above the upper limit
       int result5 = ft_isascii(128);
       int expected5 = 0;
       result = result5 == expected5;
       printf("Test 5: ft_isascii(120) - Result: %d, Expected: %d - %s\n",
              result5, expected5,
              result ? GREEN "PASS" COLOR_RESET  : RED "FAIL" COLOR_RESET);
}

void test_ft_isdigit()
{
       // Test case 1: digit
       int result1 = ft_isdigit('1');
       int expected1 = 1;
       int result = result1 == expected1;
       printf("Test 1: ft_isdigit('9') - Result: %d, Expected: %d - %s\n",
              result1, expected1,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 2: non-digit char
       int result2 = ft_isdigit('H');
       int expected2 = 0;
       result = result2 == expected2;
       printf("Test 2: ft_isdigit('H') - Result: %d, Expected: %d - %s\n",
              result2, expected2,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 3: NULL
       int result3 = ft_isdigit(0);
       int expected3 = 0;
       result = result3 == expected3;
       printf("Test 3: ft_isdigit(0) - Result: %d, Expected: %d - %s\n",
              result3, expected3,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

void test_ft_isprint()
{
       // Test case 1: space
       int result1 = ft_isprint(32);
       int expected1 = isprint(32) != 0;
       int result = result1 == expected1;
       printf("Test 1: ft_isprint(32) - Result: %d, Expected: %d - %s\n",
              result1, expected1,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 2: non-digit char
       int result2 = ft_isprint(126);
       int expected2 = isprint(126) != 0;
       result = result2 == expected2;
       printf("Test 2: ft_isprint(127) - Result: %d, Expected: %d - %s\n",
              result2, expected2,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 3: under the lover limit
       int result3 = ft_isprint('\t');
       int expected3 = isprint('\t') != 0;
       result = result3 == expected3;
       printf("Test 3: ft_isprint('\\t') - Result: %d, Expected: %d - %s\n",
              result3, expected3,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 4: above the upper limit
       int result4 = ft_isprint(128);
       int expected4 = isprint(128) != 0;
       result = result4 == expected4;
       printf("Test 4: ft_isprint(128) - Result: %d, Expected: %d - %s\n",
              result4, expected4,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 5: NULL
       int result5 = ft_isprint(0);
       int expected5 = isprint(0) != 0;
       result = result5 == expected5;
       printf("Test 5: ft_isprint(0) - Result: %d, Expected: %d - %s\n",
              result5, expected5,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

void test_ft_strlen()
{
       // Test case 1: length for a non-empty string
       size_t result1 = ft_strlen("Hello, World!");
       size_t expected1 = strlen("Hello, World!");
       int result = result1 == expected1;
       printf("Test 1: ft_strlen(\"Hello, World!\") - Result: %zu, Expected: %zu - %s\n",
              result1, expected1,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 2: 0 for an empty string
       size_t result2 = ft_strlen("");
       size_t expected2 = strlen("");
       result = result2 == expected2;
       printf("Test 2: ft_strlen(\"\") - Result: %zu, Expected: %zu - %s\n",
              result2, expected2,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

void test_ft_strlcpy()
{
       // Test case 1: Copying a string within the buffer size
       char dest1[10] = "Hello";
       const char *src1 = "World";
       size_t result1 = ft_strlcpy(dest1, src1, sizeof(dest1));
       int result = result1 == 5 && !strcmp(dest1, "World");
       printf("Test 1: ft_strlcpy(\"Hello\", \"World\", 10) - Result: %s, %zu, Expected: World, 5 - %s\n",
              dest1, result1,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 2: Copying an empty string
       char dest2[10] = "Hello";
       const char *src2 = "";
       size_t result2 = ft_strlcpy(dest2, src2, sizeof(dest2));
       result = result2 == 0 && !strcmp(dest2, "");
       printf("Test 2: ft_strlcpy(\"Hello\", \"\", 10) - Result: %s, %zu, Expected: \"\", 0 - %s\n",
              dest2, result2,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 3: Buffer size is less than the source string
       char dest3[5] = "Hello";
       const char *src3 = "World";
       size_t result3 = ft_strlcpy(dest3, src3, 4);
       result = result3 == 5 && !strcmp(dest3, "Wor");
       printf("Test 3: ft_strlcpy(\"Hello\", \"World\", 5) - Result: %s, %zu, Expected: Wor, 5 - %s\n",
              dest3, result3,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

void test_ft_strlcat()
{
       // Test case 1: Concatenate strings within the available size
       char dest1[15] = "Hello";
       const char *src1 = " World";
       size_t result1 = ft_strlcat(dest1, src1, sizeof(dest1));
       int result = result1 == 11 && !strcmp(dest1, "Hello World");
       printf("Test 1: ft_strlcat(\"Hello\", \" World\", 15) - Result: %s, %zu, Expected: %s, %d - %s\n",
              dest1, result1, "Hello World", 11,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 2: Concatenate strings where destination buffer is too small
       char dest2[8] = "Hello";
       const char *src2 = " World";
       size_t result2 = ft_strlcat(dest2, src2, 8);
       result = result2 == 11 && !strcmp(dest2, "Hello W");
       printf("Test 2: ft_strlcat(\"Hello\", \" World\", 8) - Result: %s, %zu, Expected: %s, %d - %s\n",
              dest2, result2, "Hello W", 11,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 3: Concatenate empty source string
       char dest3[10] = "Hello";
       const char *src3 = "";
       size_t result3 = ft_strlcat(dest3, src3, 10);
       result = result3 == 5 && !strcmp(dest3, "Hello");
       printf("Test 3: ft_strlcat(\"Hello\", \"\", 10) - Result: %s, %zu, Expected: %s, %d - %s\n",
              dest3, result3, "Hello", 5,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 4: Concatenate to an empty destination string
       char dest4[15] = "";
       const char *src4 = "Hello World";
       size_t result4 = ft_strlcat(dest4, src4, sizeof(dest4));
       result = result4 == 11 && !strcmp(dest4, "Hello World");
       printf("Test 4: ft_strlcat(\"\", \"Hello World\", 15) - Result: %s, %zu, Expected: %s, %d - %s\n",
              dest4, result4, "Hello World", 11,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 5: Size lower than dest length
       char dest5[15] = "Hello";
       const char *src5 = " World";
       size_t result5 = ft_strlcat(dest5, src5, 3);
       result = result5 == 9 && !strcmp(dest5, "Hello");
       printf("Test 5: ft_strlcat(\"Hello\", \" World\", 3) - Result: %s, %zu, Expected: %s, %d - %s\n",
              dest5, result5, "Hello", 9,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

void test_ft_toupper()
{
       // Test case 1: lower case char
       char result1 = ft_toupper('h');
       char expected1 = toupper('h');
       int result = result1 == expected1;
       printf("Test 1: ft_toupper('h') - Result: %c, Expected: %c - %s\n",
              result1, expected1,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 2: upper case char
       char result2 = ft_toupper('H');
       char expected2 = toupper('H');
       result = result2 == expected2;
       printf("Test 2: ft_toupper('H') - Result: %c, Expected: %c - %s\n",
              result2, expected2,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 3: NULL
       char result3 = ft_toupper(0);
       char expected3 = toupper(0);
       result = result3 == expected3;
       printf("Test 3: ft_toupper(0) - Result: %c, Expected: %c - %s\n",
              result3, expected3,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 4: non-alpha char
       char result4 = ft_toupper('@');
       char expected4 = toupper('@');
       result = result4 == expected4;
       printf("Test 4: ft_toupper(@) - Result: %c, Expected: %c - %s\n",
              result4, expected4,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

void test_ft_tolower()
{
       // Test case 1: upper case
       char result1 = ft_tolower('H');
       char expected1 = tolower('H');
       int result = result1 == expected1;
       printf("Test 1: ft_tolower('H') - Result: %c, Expected: %c - %s\n",
              result1, expected1,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 2: lower case char
       char result2 = ft_tolower('h');
       char expected2 = tolower('h');
       result = result2 == expected2;
       printf("Test 2: ft_tolower('h') - Result: %c, Expected: %c - %s\n",
              result2, expected2,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 3: NULL
       char result3 = ft_tolower(0);
       char expected3 = tolower(0);
       result = result3 == expected3;
       printf("Test 3: ft_tolower(0) - Result: %c, Expected: %c - %s\n",
              result3, expected3,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 4: non-alpha char
       char result4 = ft_tolower('@');
       char expected4 = tolower('@');
       result = result4 == expected4;
       printf("Test 4: ft_tolower('@') - Result: %c, Expected: %c - %s\n",
              result4, expected4,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

void test_ft_strchr()
{
       // Test case 1: existing character
       char *result1 = ft_strchr("Hello World!", 'o');
       char *expected1 = strchr("Hello World!", 'o');
       int result = result1 == expected1;
       printf("Test 1: ft_strchr(\"Hello World!\", 'o') - Result: %p, Expected: %p - %s\n",
              (void *)result1, (void *)expected1,
              (result1 == expected1) ? GREEN "PASS" COLOR_RESET
                                     : RED "FAIL" COLOR_RESET);

       // Test case 2: character not found in the string
       char *result2 = ft_strchr("Hello World!", 'x');
       char *expected2 = strchr("Hello World!", 'x');
       result = result2 == expected2;
       printf("Test 2: ft_strchr(\"Hello World!\", 'x') - Result: %p, Expected: NULL - %s\n",
              (void *)result2, result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 3: char is the only char in the string
       char *result3 = ft_strchr("x", 'x');
       char *expected3 = strchr("x", 'x');
       result = result3 == expected3;
       printf("Test 3: ft_strchr(\"x\", 'x') - Result: %p, Expected: %p - %s\n",
              (void *)result3, (void *)expected3,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 4: char is \0
       char *result4 = ft_strchr("Hello World!", '\0');
       char *expected4 = strchr("Hello World!", '\0');
       result = result4 == expected4;
       printf("Test 4: ft_strchr(\"Hello World!\", 'o') - Result: %p, Expected: %p - %s\n",
              (void *)result4, (void *)expected4,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

void test_ft_strrchr()
{
       // Test case 1: existing character
       char *result1 = ft_strrchr("Hello World!", 'o');
       char *expected1 = strrchr("Hello World!", 'o');
       int result = strcmp(result1, expected1) == 0;
       printf("Test 1: ft_strrchr(\"Hello World!\", 'o') - Result: %s, Expected: %s - %s\n",
              result1, expected1,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 2: character not found in the string
       char *result2 = ft_strrchr("Hello World!", 'x');
       char *expected2 = strrchr("Hello World!", 'x');
       result = result2 == expected2;
       printf("Test 2: ft_strrchr(\"Hello World!\", 'x') - Result: %s, Expected: NULL - %s\n",
              result2,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 3: char is the only char in the string
       char *result3 = ft_strrchr("x", 'x');
       char *expected3 = strrchr("x", 'x');
       result = strcmp(result3, expected3) == 0;
       printf("Test 3: ft_strrchr(\"x\", 'x') - Result: %s, Expected: %s - %s\n",
              result3, expected3,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 4: char is \0
       char *result4 = ft_strrchr("Hello World!", '\0');
       char *expected4 = strrchr("Hello World!", '\0');
       result = strcmp(result4, expected4) == 0;
       printf("Test 4: ft_strrchr(\"Hello World!\", '\\0') - Result: %s, Expected: %s - %s\n",
              result4, expected4,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

void test_ft_strncmp()
{
       // Test case 1: existing character
       int result1 = ft_strncmp("HeLlo", "Hello", 7);
       int expected1 = strncmp("HeLlo", "Hello", 7);
       int result = result1 == expected1;
       printf("Test 1: ft_strncmp(\"HeLlo\", \"Hello\", 7) - Result: %d, Expected: %d - %s\n",
              result1, expected1,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
       // Test case 2: character not found in the string
       int result2 = ft_strncmp("HeLlo", "Hello", 0);
       int expected2 = strncmp("HeLlo", "Hello", 0);
       result = result2 == expected2;
       printf("Test 2: ft_strncmp(\"HeLlo\", \"Hello\", 0) - Result: %d, Expected: %d - %s\n",
              result2, expected2,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 3: intis the only intin the string
       int result3 = ft_strncmp("Hello", "HeLlo", 7);
       int expected3 = strncmp("Hello", "HeLlo", 7);
       result = result3 == expected3;
       printf("Test 3: ft_strncmp(\"Hello\", \"HeLlo\", 7) - Result: %d, Expected: %d - %s\n",
              result3, expected3,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 4: intis \0
       int result4 = ft_strncmp("Hello", "Hello", 7);
       int expected4 = strncmp("Hello", "Hello", 7);
       result = result4 == expected4;
       printf("Test 4: ft_strncmp(\"Hello\", \"Hello\", 7) - Result: %d, Expected: %d - %s\n",
              result4, expected4,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 5: string is NULL
       int result5 = ft_strncmp("", "Hell", 2);
       int expected5 = strncmp("", "Hell", 2);
       result = result5 == expected5;
       printf("Test 5: ft_strncmp(\"\", \"Hell\", 2) - Result: %d, Expected: %d - %s\n",
              result5, expected5,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

void test_ft_memchr()
{
    char buffer1[10] = "Hello";
    char expectedBuffer1[10] = "Hello";

    // Test case 1: finding 'e' in a non-empty buffer
    void* result1 = ft_memchr(buffer1, 'e', 3);
    int position1 = result1 ? (int)((char*)result1 - buffer1) : -1;
    printf("Test 1: ft_memchr(buffer1, 'e', 5) - Result: %s\n", position1 == 1 ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

    char buffer2[5] = "Test";
    char expectedBuffer2[5] = "Test";

    // Test case 2: finding 't' in an entire buffer
    void* result2 = ft_memchr(buffer2, 't', sizeof(buffer2));
    int position2 = result2 ? (int)((char*)result2 - buffer2) : -1;
    printf("Test 2: ft_memchr(buffer2, 't', sizeof(buffer2)) - Result: %s\n", position2 == 3 ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    
    // Test case 3: finding 'i' in part of a buffer
    char buffer3[8] = "Partial";
    char expectedBuffer3[8] = "Partial";

    void* result3 = ft_memchr(buffer3, 'i', 5);
    void* expected3 = memchr(buffer3, 'i', 5);
    printf("Test 3: ft_memchr(buffer3 + 2, 'i', 5) - Result: %s\n", result3 == expected3 ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    
    // Test case 4: finding 'x' in a buffer where it doesn't exist
    void* result4 = ft_memchr(buffer3, 'x', sizeof(buffer3));
    int position4 = result4 ? (int)((char*)result4 - buffer3) : -1;
    printf("Test 4: ft_memchr(buffer3, 'x', sizeof(buffer3)) - Result: %s\n", position4 == -1 ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

void test_ft_memcmp()
{
    char buffer1[10] = "Hello";
    char expectedBuffer1[10] = "Hello";

    // Test case 1: comparing two equal non-empty buffers
    int result1 = ft_memcmp(buffer1, expectedBuffer1, sizeof(buffer1));
    int expected1 = memcmp(buffer1, expectedBuffer1, sizeof(buffer1));
    printf("Test 1: ft_memcmp(buffer1, expectedBuffer1, sizeof(buffer1)) - Result: %s\n", result1 == expected1 ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

    char buffer2[5] = "Test";
    char expectedBuffer2[5] = "tEst";

    // Test case 2: comparing two non-equal buffers
    int result2 = ft_memcmp(buffer2, expectedBuffer2, sizeof(buffer2));
    int expected2 = memcmp(buffer2, expectedBuffer2, sizeof(buffer2));
    printf("Test 2: ft_memcmp(buffer2, expectedBuffer2, sizeof(buffer2)) - Result: %s\n", result2 == expected2 ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    
    // Test case 3: comparing part of two buffers
    char buffer3[8] = "Partial";
    char expectedBuffer3[8] = "Partyal";

    int result3 = ft_memcmp(buffer3, expectedBuffer3, 6);
    int expected3 = memcmp(buffer3, expectedBuffer3, 6);
    printf("Test 3: ft_memcmp(buffer3, expectedBuffer3, 6) - Result: %s\n", result3 == expected3 ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

void test_ft_strnstr()
{
       // Test case 1: substr exists within the buffer
       char *result1 = ft_strnstr("Hello World!", "Hell", 7);
       char *expected1 = "Hello World!";
       CU_ASSERT_PTR_EQUAL(result1, expected1);
       printf("Test 1: ft_strnstr(\"Hello World!\", \"Hell\", 7) - Result: %s, Expected: %s - %s\n",
              result1, expected1,
              (result1 == expected1) ? GREEN "PASS" COLOR_RESET
                                     : RED "FAIL" COLOR_RESET);

       // Test case 2: substr not found in the string
       char *result2 = ft_strnstr("Hello World!", "Woo", 20);
       CU_ASSERT_PTR_NULL(result2);
       printf("Test 2: ft_strnstr(\"Hello World!\", \"Woo\", 20) - Result: %s, Expected: NULL - %s\n",
              result2,
              (result2 == NULL) ? GREEN "PASS" COLOR_RESET
                                : RED "FAIL" COLOR_RESET);

       // Test case 3: substr not found in the string within the buffer size
       char *result3 = ft_strnstr("Hello World!", "World", 9);
       CU_ASSERT_PTR_NULL(result3);
       printf("Test 3: ft_strnstr(\"Hello World!\", \"World\", 9) - Result: %s, Expected: NULL - %s\n",
              result3,
              (result3 == NULL) ? GREEN "PASS" COLOR_RESET
                                : RED "FAIL" COLOR_RESET);

       // Test case 4: char is \0
       char *result4 = ft_strnstr("Hello World!", "", 10);
       char *expected4 = "Hello World!";
       CU_ASSERT_PTR_EQUAL(result4, expected4);
       printf("Test 4: ft_strnstr(\"Hello World!\", \"\", 10) - Result: %s, Expected: %s - %s\n",
              result4, expected4,
              (result4 == expected4) ? GREEN "PASS" COLOR_RESET
                                     : RED "FAIL" COLOR_RESET);

       // Test case 5: char is \0
       char *result5 = ft_strnstr("", "World", 8);
       CU_ASSERT_PTR_NULL(result5);
       printf("Test 5: ft_strnstr(\"\", \"World\", 8) - Result: %s, Expected: NULL - %s\n",
              result5,
              (result5 == NULL) ? GREEN "PASS" COLOR_RESET
                                : RED "FAIL" COLOR_RESET);
}

void test_ft_strjoin()
{
       // Test case 1: non-empty strings
       char *result1 = ft_strjoin("Hello ", "World!");
       char *expected1 = "Hello World!";
       int result = strcmp(result1, expected1) == 0;
       printf("Test 1: ft_strjoin(\"Hello \", \"World!\") - Result: %s, Expected: %s - %s\n",
              result1, expected1,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 2: empty strings
       char *result2 = ft_strjoin("", "");
       char *expected2 = "";
       result = strcmp(result2, expected2) == 0;
       printf("Test 2: ft_strjoin(\"\", \"\") - Result: %s, Expected: %s - %s\n",
              result2, expected2,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
       free(result1);
       free(result2);
}

void test_ft_strtrim()
{
       // Test case 1: existing character
       char *result1 = ft_strtrim("! Hello! !World  ! ", " !");
       char *expected1 = "Hello! !World";
       int result = strcmp(result1, expected1) == 0;
       printf("Test 1: ft_strtrim(\"! Hello! !World  ! \", \" !\") - Result: %s, Expected: %s - %s\n",
              result1, expected1,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 2: character not found in the string
       char *result2 = ft_strtrim("!!Hello! !World!!", "");
       char *expected2 = "!!Hello! !World!!";
       result = strcmp(result2, expected2) == 0;
       printf("Test 2: ft_strtrim(\"!!Hello! !World!!\", \"\") - Result: %s, Expected: %s - %s\n",
              result2, expected2,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 3: character not found in the string
       char *result3 = ft_strtrim("AlohA", "A");
       char *expected3 = "loh";
       result = strcmp(result3, expected3) == 0;
       printf("Test 3: ft_strtrim(\"AlohA\", \"A\") - Result: %s, Expected: %s - %s\n",
              result3, expected3,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 4: character not found in the string
       char *result4 = ft_strtrim(NULL, "ABC");
       result = result4 == NULL;
       printf("Test 4: ft_strtrim(NULL, \"ABC\") - Result: %s, Expected: NULL - %s\n",
              result4,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       free(result1);
       free(result2);
       free(result3);
       free(result4);
}

void test_ft_atoi()
{
       // Test case 1: Positive integer
       int result1 = ft_atoi("\t\v +123");
       int expected1 = atoi("\t\v +123");
       printf("Test 1: ft_atoi(\"\\t\\v +123\") - Result: %d, Expected: %d - %s\n",
              result1, expected1,
              (result1 == expected1) ? GREEN "PASS" COLOR_RESET
                                     : RED "FAIL" COLOR_RESET);

       // Test case 2: Negative integer
       int result2 = ft_atoi("-456abc");
       int expected2 = atoi("-456abc");
       printf("Test 2: ft_atoi(\"-456abc\") - Result: %d, Expected: %d - %s\n",
              result2, expected2,
              (result2 == expected2) ? GREEN "PASS" COLOR_RESET
                                     : RED "FAIL" COLOR_RESET);

       // Test case 3: Zero
       int result3 = ft_atoi("0");
       int expected3 = atoi("0");
       printf("Test 3: ft_atoi(\"0\") - Result: %d, Expected: %d - %s\n",
              result3, expected3,
              (result3 == expected3) ? GREEN "PASS" COLOR_RESET
                                     : RED "FAIL" COLOR_RESET);

       // Test case 4: Non-numeric input
       int result4 = ft_atoi("abc");
       int expected4 = atoi("abc");
       printf("Test 4: ft_atoi(\"abc\") - Result: %d, Expected: %d - %s\n",
              result4, expected4,
              (result4 == expected4) ? GREEN "PASS" COLOR_RESET
                                     : RED "FAIL" COLOR_RESET);

       // Test case 5: Overflow
       int result5 = ft_atoi("2147483648"); // Beyond INT_MAX
       int expected5 = atoi("2147483648");
       printf("Test 5: ft_atoi(\"2147483648\") - Result: %d, Expected: %d - %s\n",
              result5, expected5,
              (result5 == expected5) ? GREEN "PASS" COLOR_RESET
                                     : RED "FAIL" COLOR_RESET);
}

void test_ft_substr()
{
       // Test case 1: Basic substring
       char *result1 = ft_substr("Hello, World!", 7, 5);
       char *expected1 = "World";
       int result = strcmp(result1, expected1) == 0;
       printf("Test 1: ft_substr(\"Hello, World!\", 7, 5) - Result: %s, Expected: %s - %s\n",
              result1, expected1,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 2: Substring exceeding string length
       char *result2 = ft_substr("Testing", 0, 20);
       char *expected2 = "Testing";
       result = strcmp(result2, expected2) == 0;
       printf("Test 2: ft_substr(\"Testing\", 0, 20) - Result: %s, Expected: %s - %s\n",
              result2, expected2,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 3: Substring from an empty string
       char *result3 = ft_substr("", 0, 3);
       char *expected3 = "";
       result = strcmp(result3, expected3) == 0;
       printf("Test 3: ft_substr(\"\", 0, 3) - Result: %s, Expected: %s - %s\n",
              result3, expected3,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 4: Empty substring
       char *result4 = ft_substr("Substring", 5, 0);
       char *expected4 = "";
       result = strcmp(result4, expected4) == 0;
       printf("Test 4: ft_substr(\"Substring\", 5, 0) - Result: %s, Expected: %s - %s\n",
              result4, expected4,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 5: Start exceeding string length
       char *result5 = ft_substr("Substring", 20, 5);
       char *expected5 = "";
       result = strcmp(result5, expected5) == 0;
       printf("Test 5: ft_substr(\"Substring\", 20, 5) - Result: %s, Expected: %s - %s\n",
              result5, expected5,
              result ? GREEN "PASS" COLOR_RESET
                                              : RED "FAIL" COLOR_RESET);
       free(result1);
       free(result2);
       free(result3);
       free(result4);
       free(result5);
}

void test_ft_strmapi()
{
       // Test case 1: Basic Test
       char input1[] = "Hdjik!";
       char expected1[] = "Hello!";
       char *result1 = ft_strmapi(input1, &caesarEncrypt);
       int result = strcmp(result1, expected1) == 0;
       printf("Test 1: ft_strmapi(\"Hdjik!\", &caesarEncrypt) - Result: %s, Expected: %s - %s\n",
              result1, expected1,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 2: Empty String
       char input2[] = "";
       char *result2 = ft_strmapi(input2, &caesarEncrypt);
       result = strcmp(result2, "") == 0;
       printf("Test 2: ft_strmapi(\"\", &caesarEncrypt) - Result: %s, Expected: \"\" - %s\n",
              result2,
              result ? GREEN "PASS" COLOR_RESET
                                       : RED "FAIL" COLOR_RESET);

       free(result1);
       free(result2);
}

void test_ft_striteri()
{
       // Test case 1
       char result1[] = "aaaaaabbbbaa!";
       char *expected1 = "XaXaXabbbbXa!";
       ft_striteri(result1, &a_to_X);
       int result = strcmp(result1, expected1) == 0;
       printf("Test 1: ft_striteri(\"Hdjik!\", &a_to_X) - Result: %s, Expected: %s - %s\n",
              result1, expected1,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 2
       char result2[] = "";
       ft_striteri(result2, &a_to_X);
       result = strcmp(result2, "") == 0;
       printf("Test 2: ft_striteri(\"\", &a_to_X) - Result: %s, Expected: \"\" - %s\n",
              result2, result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

int main()
{
       printf( BLUE "test_ft_isalpha\n" COLOR_RESET);
       test_ft_isalpha();
       printf( BLUE "test_ft_isdigit\n" COLOR_RESET);
       test_ft_isdigit();
       printf( BLUE "test_ft_isalnum\n" COLOR_RESET);
       test_ft_isalnum();
       printf( BLUE "test_ft_isascii\n" COLOR_RESET);
       test_ft_isascii();
       printf( BLUE "test_ft_isprint\n" COLOR_RESET);
       test_ft_isprint();
       printf( BLUE "test_ft_strlen\n" COLOR_RESET);
       test_ft_strlen();
       printf( BLUE "test_ft_memset\n" COLOR_RESET);
       test_ft_memset();
       printf( BLUE "test_ft_bzero\n" COLOR_RESET);
       test_ft_bzero();
       printf( BLUE "test_ft_memcpy\n" COLOR_RESET);
       test_ft_memcpy();
       printf( BLUE "test_ft_memmove\n" COLOR_RESET);
       test_ft_memmove();
       printf( BLUE "test_ft_strlcpy\n" COLOR_RESET);
       test_ft_strlcpy();
       printf( BLUE "test_ft_strlcat\n" COLOR_RESET);
       test_ft_strlcat();
       printf( BLUE "test_ft_toupper\n" COLOR_RESET);
       test_ft_toupper();
       printf( BLUE "test_ft_tolower\n" COLOR_RESET);
       test_ft_tolower();
       printf( BLUE "test_ft_strchr\n" COLOR_RESET);
       test_ft_strchr();
       printf( BLUE "test_ft_strrchr\n" COLOR_RESET);
       test_ft_strrchr();
       printf( BLUE "test_ft_strncmp\n" COLOR_RESET);
       test_ft_strncmp();
       printf( BLUE "test_ft_memchr\n" COLOR_RESET);
       test_ft_memchr();
       printf( BLUE "test_ft_memcmp\n" COLOR_RESET);
       test_ft_memcmp();
       printf( BLUE "test_ft_strnstr\n" COLOR_RESET);
       test_ft_strnstr();
       printf( BLUE "test_ft_atoi\n" COLOR_RESET);
       test_ft_atoi();
       printf( BLUE "test_ft_substr\n" COLOR_RESET);
       test_ft_substr();
       printf( BLUE "test_ft_strjoin\n" COLOR_RESET);
       test_ft_strjoin();
       printf( BLUE "test_ft_strtrim\n" COLOR_RESET);
       test_ft_strtrim();
       // printf( BLUE "test_ft_split\n" COLOR_RESET);
       // test_ft_split();
       // printf( BLUE "test_ft_itoa\n" COLOR_RESET);
       // test_ft_itoa();
       printf( BLUE "test_ft_strmapi\n" COLOR_RESET);
       test_ft_strmapi();
       printf( BLUE "test_ft_striteri\n" COLOR_RESET);
       test_ft_striteri();
       // printf( BLUE "test_ft_putchar_fd\n" COLOR_RESET);
       // test_ft_putchar_fd();
       // printf( BLUE "test_ft_putstr_fd\n" COLOR_RESET);
       // test_ft_putstr_fd();
       // printf( BLUE "test_ft_putendl_fd\n" COLOR_RESET);
       // test_ft_putendl_fd();
       // printf( BLUE "test_ft_putnbr_fd\n" COLOR_RESET);
       // test_ft_putnbr_fd();

       return (0);
}
