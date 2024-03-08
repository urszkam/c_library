#include "libft.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define COLOR_RESET "\x1b[0m"

/* Initialize and Cleanup Functions */
/*int init_suite()
{
       return 0;
}

int clean_suite()
{
       return 0;
}*/

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

static int  arrcmp(char **arr1, char **arr2)
{
    int i = 0;
    while (arr1[i] && arr2[i])
    {
        if (!arr1[i] || !arr2[i] || strcmp(arr1[i], arr2[i]) != 0)
            return (-1);
        i++;
    }
    return (0);
}

static void free_array(char **arr)
{
    int i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

static void print_arr(char **arr)
{
    int i = 0;
    while (arr[i])
    {
        printf("%s, ", arr[i]);
        i++;
    }
}

/* Function Tests */

void test_ft_memset()
{
    // Test case 2: filling an entire buffer with a constant value
    char buffer2[5] = "Test";
    char expected2[5] = "Test";

    ft_memset(buffer2, 'X', sizeof(buffer2) - 1);
    memset(expected2, 'X', sizeof(expected2) - 1);
    int result2 = memcmp(buffer2, expected2, sizeof(buffer2)) == 0;
    printf("Test 1: ft_memset(\"Test\", 'X', sizeof(buffer2) - 1) - Result: %s, Expected: %s - %s\n",
        buffer2, expected2, result2 ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    
    // Test case 3: filling part of a buffer with a constant value
    char buffer3[9] = {'L', 'o', 'v', 'e', ' ', 'Y', 'o', 'u', 0};
    char expected3[9] = {'L', 'o', 'v', 'e', ' ', 'Y', 'o', 'u', 0};

    ft_memset(buffer3 + 3, 'X', 3);
    memset(expected3 + 3, 'X', 3);
    int result3 = memcmp(buffer3, expected3, sizeof(buffer3)) == 0;
    printf("Test 2: ft_memset(\"Love You\" + 3, 'X', 3) - Result: %s, Expected: %s - %s\n",
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
    // Test case 1: copying from a non-empty source to a non-empty destination
    char source1[10] = "Hello";
    char destination1[10] = "World";
    char expected1[10] = "World";

    ft_memcpy(destination1, source1, 5);
    memcpy(expected1, source1, 5);
    int result1 = memcmp(destination1, expected1, sizeof(destination1)) == 0;
    printf("Test 1: ft_memcpy(\"World\", \"Hello\", 5) - Result: %s, Expected: %s - %s\n",
        destination1, expected1, result1 ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

    // Test case 2: copying from a non-empty source to an empty destination
    char source2[5] = "Test";
    char destination2[5] = "";
    char expected2[5] = "";

    
    ft_memcpy(destination2, source2, sizeof(source2));
    memcpy(expected2, source2, sizeof(source2));
    int result2 = memcmp(destination2, expected2, sizeof(destination2)) == 0;
    printf("Test 2: ft_memcpy(destination2, source2, sizeof(source2)) - Result: %s, Expected: %s - %s\n",
        destination2, expected2, result2 ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    
    // Test case 3: copying from a non-empty source to part of a destination
    char source3[9] = "XXXXXXXX";
    char destination3[9] = "Love You";
    char expected3[9] = "Love You";

    ft_memcpy(destination3 + 3, source3, 4);
    memcpy(expected3 + 3, source3, 4);
    int result3 = memcmp(destination3, expected3, sizeof(destination3)) == 0;
    printf("Test 3: ft_memcpy(\"Love You\" + 3, \"\", 4) - Result: %s, Expected: %s - %s\n",
        destination3, expected3, result3 ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

void test_ft_memmove()
{
    char source1[10] = "Hello";
    char result1[10] = "World";
    char expected1[10] = "World";

    // Test case 1: moving from a non-empty source to a non-empty destination
    ft_memmove(result1 + 1, source1, 5);
    memmove(expected1 + 1, source1, 5);
    int result = memcmp(result1, expected1, sizeof(result1)) == 0;
    printf("Test 1: ft_memmove(destination1 + 1, source1, 5) - Result: %s, Expected: %s - %s\n",
    	result1, expected1, 
    	result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

    char source2[5] = "Test";
    char result2[5] = "";
    char expected2[5] = "";

    // Test case 2: moving from a non-empty source to an empty destination
    ft_memmove(result2, source2, sizeof(source2));
    memmove(expected2, source2, sizeof(source2));
    result = memcmp(result2, expected2, sizeof(result2)) == 0;
    printf("Test 2: ft_memmove(\"\", \"Test\", sizeof(\"Test\")) - Result: %s, Expected: %s - %s\n",
    result2, expected2,
    result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

    // Test case 3: overlapping move from a non-empty source to part of a destination
    char source3[9] = "Love You";
    char result3[8] = "XXXXXXX";
    char expected3[8] = "XXXXXXX";

    ft_memmove(result3 + 3, source3, 3);
    memmove(expected3 + 3, source3, 3);
    result = memcmp(result3, expected3, sizeof(result3)) == 0;
    printf("Test 3: ft_memmove(\"XXXXXXX\" + 3, \"Love You\", 3) - Result: %s, Expected: %s - %s\n",
    	result3, expected3,
    	result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

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
       int result = result1 == expected1;
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
       printf("Test 4: ft_strchr(\"Hello World!\", '\\0') - Result: %p, Expected: %p - %s\n",
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
    // Test case 1: finding 'e' in a non-empty buffer
    char buffer1[10] = "Hello";

    void *result1 = ft_memchr(buffer1, 'e', 3);
    void *expected1 = memchr(buffer1, 'e', 3);
    int result = strcmp((char *) result1, (char *) expected1) == 0;
    printf("Test 1: ft_memchr(\"Hello\", 'e', 5) - Result: %s, Expected: %s - %s\n",
        (char *) result1, (char *) expected1, result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
        
    // Test case 2: finding 't' in an entire buffer
    char buffer2[5] = "Test";

    void* result2 = ft_memchr(buffer2, 't', sizeof(buffer2));
    void* expected2 = memchr(buffer2, 't', sizeof(buffer2));
    result = strcmp((char *) result2, (char *) expected2) == 0;
    printf("Test 2: ft_memchr(\"Test\", 't', sizeof(\"Test\")) - Result: %s, Expected: %s - %s\n",
        (char *) result2,(char *) expected2, result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    
    // Test case 3: finding 'i' in part of a buffer
    char buffer3[9] = "Love You";

    void* result3 = ft_memchr(buffer3, ' ', 5);
    void* expected3 = memchr(buffer3, ' ', 5);
    result = strcmp((char *) result3, (char *) expected3) == 0;
    printf("Test 3: ft_memchr(\"Love You\" + 2, ' ', 5) - Result: %s, Expected: %s - %s\n",
        (char *) result3, (char *) expected3, result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    
    // Test case 4: finding 'x' in a buffer where it doesn't exist
    void* result4 = ft_memchr(buffer3, 'x', sizeof(buffer3));
    void* expected4 = memchr(buffer3, 'x', sizeof(buffer3));
    result = result4 == expected4;
    printf("Test 4: ft_memchr(\"Love You\", 'x', sizeof(\"Love You\")) - Result: %s, Expected: %s - %s\n", 
        (char *) result4, (char *) expected4, result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

void test_ft_memcmp()
{
    // Test case 1: comparing two equal non-empty buffers
    char buffer1[10] = "Hello";
    char compare1[10] = "Hello";

    int result1 = ft_memcmp(buffer1, compare1, sizeof(buffer1));
    int expected1 = memcmp(buffer1, compare1, sizeof(buffer1));
    int result = result1 == expected1;
    printf("Test 1: ft_memcmp(\"Hello\", \"Hello\", sizeof(\"Hello\")) - Result: %d, Expected: %d - %s\n",
        result1, expected1 ,result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

    char buffer2[7] = "Tested";
    char compare2[5] = "Test";

    // Test case 2: comparing part of two buffers
    int result2 = ft_memcmp(buffer2, compare2, 4);
    int expected2 = memcmp(buffer2, compare2, 4);
    result = result2 == expected2;
    printf("Test 2: ft_memcmp(\"Tested\", \"Test\", 4) - Result: %d, Expected: %d - %s\n",
        result1, expected2, result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    
    // Test case 3: comparing non-equal buffers
    char buffer3[12] = "\0I Love You";
    char compare3[18] = "\0I Don't Love You";

    int result3 = ft_memcmp(buffer3, compare3, 6);
    int expected3 = memcmp(buffer3, compare3, 6);
    result = result3 == expected3;
    printf("Test 3: ft_memcmp(\"\\0I Love You\", \"\\0I Don't Love You\", 6) - Result: %d, Expected: %d - %s\n",
        result3, expected3, result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
        
    // Test case 4: comparing non-equal buffers
    char buffer4[5] = "Hall";
    char compare4[5] = "Hell";

    int result4 = ft_memcmp(buffer4, compare4, 6);
    int expected4 = memcmp(buffer4, compare4, 6);
    result = result4 == expected4;
    printf("Test 4: ft_memcmp(\"Hall\", \"Hell\", 6) - Result: %d, Expected: %d - %s\n",
        result4, expected4, result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

    // Test case 5: comparing 0 chars
    int result5 = ft_memcmp(buffer3, compare3, 0);
    int expected5 = memcmp(buffer3, compare3, 0);
    result = result5 == expected5;
    printf("Test 5: ft_memcmp(\"\\0I Love You\", \"\\0I Don't Love You\", 0) - Result: %d, Expected: %d - %s\n",
        result5, expected5, result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

void test_ft_strnstr()
{
       // Test case 1: substr exists within the buffer
       char *result1 = ft_strnstr("Hello World!", "ell", 7);
       char *expected1 = "ello World!";
       int result = strcmp(result1, expected1) == 0;
       printf("Test 1: ft_strnstr(\"Hello World!\", \"ell\", 7) - Result: %s, Expected: %s - %s\n",
              result1, expected1,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 2: substr not found in the string
       char *result2 = ft_strnstr("Hello World!", "Woo", 20);
       result = result2 == NULL;
       printf("Test 2: ft_strnstr(\"Hello World!\", \"Woo\", 20) - Result: %s, Expected: NULL - %s\n",
              result2,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 3: substr not found in the string within the buffer size
       char *result3 = ft_strnstr("Hello World!", "World", 9);
       result = result3 == NULL;
       printf("Test 3: ft_strnstr(\"Hello World!\", \"World\", 9) - Result: %s, Expected: NULL - %s\n",
              result3,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 4: char is \0
       char *result4 = ft_strnstr("Hello World!", "\0", 20);
       char *expected4 = "Hello World!";
       result = strcmp(result4, expected4) == 0;
       printf("Test 4: ft_strnstr(\"Hello World!\", \"\\0\", 20) - Result: %s, Expected: %s - %s\n",
              result4, expected4,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 5: char is \0
       char *result5 = ft_strnstr("", "World", 8);
       result = result5 == NULL;
       printf("Test 5: ft_strnstr(\"\", \"World\", 8) - Result: %s, Expected: NULL - %s\n",
              result5,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
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

void test_ft_split()
{
    // Test case 1: Multiple words, multiple separators
    char *str1 = ",Hello,World,,This,is,a,,,,,,test,";
    char charset1 = ',';
    char **result1 = ft_split(str1, charset1);
    char *expected1[] = {"Hello", "World", "This", "is", "a", "test", 0};
    int result = arrcmp(result1, expected1) == 0;
    printf("Test 1: ft_split(\",Hello,World,,This,is,a,,,,,,test,\", ',') - Result: {");
    print_arr(result1);
    printf("NULL}, Expected: {");
    print_arr(expected1);
    printf("NULL} %s\n", result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    free_array(result1);
    
    // Test case 2: Multiple words, single separator
    char *str2 = "    I   Love You  ";
    char charset2 = ' ';
    char **result2 = ft_split(str2, charset2);
    char *expected2[] = {"I", "Love", "You", 0};
    result = arrcmp(result2, expected2) == 0;
    printf("Test 2: ft_split(\"    I   Love You  \", ' ') - Result: {");
    print_arr(result2);
    printf("NULL}, Expected: {");
    print_arr(expected2);
    printf("NULL} %s\n", result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    free_array(result2);
    
    // Test case 3: Single word
    char *str3 = "42Warsaw";
    char charset3 = '-';
    char **result3 = ft_split(str3, charset3);
    char *expected3[] = {"42Warsaw", 0};
    result = arrcmp(result3, expected3) == 0;
    printf("Test 3: ft_split(\"42Warsaw\", '-') - Result: {");
    print_arr(result3);
    printf("NULL}, Expected: {");
    print_arr(expected3);
    printf("NULL} %s\n", result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    free_array(result3);
    
    // Test case 4: Empty string
    char *str4 = "";
    char charset4 = '.';
    char **result4 = ft_split(str4, charset4);
    char *expected4[] = {0};
    result = arrcmp(result4, expected4) == 0;
    printf("Test 4: ft_split(\"\", '.') - Result: {");
    print_arr(result4);
    printf("NULL}, Expected: {");
    print_arr(expected4);
    printf("NULL} %s\n", result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    free_array(result4);
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

void test_ft_calloc()
{
    // Test case 1: Allocating and initializing memory for integers
    size_t size1 = 5;
    size_t elem_size1 = sizeof(int);
    void *result1 = ft_calloc(size1, elem_size1);
    void *expected1 = calloc(size1, elem_size1);
    int result = memcmp(result1, expected1, size1 * elem_size1) == 0;
    printf("Test 1: ft_calloc(5, sizeof(int)) - Result: %s\n",
        result ? GREEN "Pass" COLOR_RESET : RED "Fail" COLOR_RESET);
    free(result1);
    free(expected1);

    // Test case 2: Allocating and initializing memory for characters
    size_t size2 = 8;
    size_t elem_size2 = sizeof(char);
    char *result2 = ft_calloc(size2, elem_size2);
    char *expected2 = calloc(size2, elem_size2);
    result = memcmp(result2, expected2, size2 * elem_size2) == 0;
    printf("Test 2: ft_calloc(8, sizeof(char)) - Result: %s\n",
        result ? GREEN "Pass" COLOR_RESET : RED "Fail" COLOR_RESET);
    free(result2);
    free(expected2);

    // Test case 3: Allocating and initializing memory for a custom struct
    typedef struct {
        int value;
        char symbol;
    } CustomStruct;

    size_t size3 = 3;
    size_t elem_size3 = sizeof(CustomStruct);
    CustomStruct *result3 = ft_calloc(size3, elem_size3);
    CustomStruct *expected3 = calloc(size3, elem_size3);
    result = memcmp(result3, expected3, size3 * elem_size3) == 0;
    printf("Test 2: ft_calloc(3, sizeof(CustomStruct)) - Result: %s\n",
        result ? GREEN "Pass" COLOR_RESET : RED "Fail" COLOR_RESET);
    free(result3);
    free(expected3);
}

void test_ft_strdup()
{
    // Test case 1: Basic string duplication
    char str1[] = "Hello, World!";
    char *result1 = ft_strdup(str1);
    char *expected1 = strdup(str1);
    int result = strcmp(expected1, result1) == 0;
    printf("Test 1: ft_strdup(\"Hello, World!\") - Result: %s, Expected: %s - %s\n", result1, expected1,
        result ? GREEN "Pass" COLOR_RESET : RED "Fail" COLOR_RESET);
    free(result1);
    free(expected1);

    // Test case 2: Empty string
    char str2[] = "";
    char *result2 = ft_strdup(str2);
    char *expected2 = strdup(str2);
    result = strcmp(expected2, result2) == 0;
    printf("Test 2: ft_strdup(\"\") - Result: %s, Expected: %s - %s\n", result2, expected2,
        result ? GREEN "Pass" COLOR_RESET : RED "Fail" COLOR_RESET);
    free(result2);
    free(expected2);

    // Test case 3: String with spaces
    char str3[] = "   Spaces   ";
    char *result3 = ft_strdup(str3);
    char *expected3 = strdup(str3);
    result = strcmp(expected3, result3) == 0;
    printf("Test 3: ft_strdup(\"   Spaces   \") - Result: %s, Expected: %s - %s\n", 
    	result3, expected3,
        result ? GREEN "Pass" COLOR_RESET : RED "Fail" COLOR_RESET);
    free(result3);
    free(expected3);
    
    // Test case 4: String with special characters
    char str4[] = "!@#";
    char *result4 = ft_strdup(str4);
    result = strcmp(str4, result4) == 0;
    printf("Test 4: ft_strdup(\"!@#\") - Result: %s, Expected: %s - %s\n", result4, str4,
        result ? GREEN "Pass" COLOR_RESET : RED "Fail" COLOR_RESET);
    free(result4);
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
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
       free(result1);
       free(result2);
       free(result3);
       free(result4);
       free(result5);
}

void test_ft_itoa()
{
    // Test case 1: Positive number
    int num1 = 12345;
    char *result1 = ft_itoa(num1);
    printf("Test 1: ft_itoa(%d) - Result: %s - %s\n", num1, result1,
        num1 == atoi(result1) ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    free(result1);

    // Test case 2: Negative number
    int num2 = -98765;
    char *result2 = ft_itoa(num2);
    printf("Test 2: ft_itoa(%d) - Result: %s - %s\n", num2, result2,
        num2 == atoi(result2) ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    free(result2);

    // Test case 3: Zero
    int num3 = 0;
    char *result3 = ft_itoa(num3);
    printf("Test 3: ft_itoa(%d) - Result: %s - %s\n", num3, result3,
        num3 == atoi(result3) ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    free(result3);

    // Test case 4: Minimum integer value
    int num4 = -2147483648;
    char *result4 = ft_itoa(num4);
    printf("Test 4: ft_itoa(%d) - Result: %s - %s\n", num4, result4,
        num4 == atoi(result4) ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    free(result4);

    // Test case 5: Maximum integer value
    int num5 = 2147483647;
    char *result5 = ft_itoa(num5);
    printf("Test 5: ft_itoa(%d) - Result: %s - %s\n", num5, result5,
        num5 == atoi(result5) ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    free(result5);
       
    // Test case 6: One
    int num6 = 1;
    char *result6 = ft_itoa(num6);
    printf("Test 6: ft_itoa(%d) - Result: %s - %s\n", num6, result6,
        num6 == atoi(result6) ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    free(result6);
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
       printf("Test 1: ft_striteri(\"aaaaaabbbbaa\", &a_to_X) - Result: %s, Expected: %s - %s\n",
              result1, expected1,
              result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

       // Test case 2
       char result2[] = "";
       ft_striteri(result2, &a_to_X);
       result = strcmp(result2, "") == 0;
       printf("Test 2: ft_striteri(\"\", &a_to_X) - Result: %s, Expected: \"\" - %s\n",
              result2, result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

void test_ft_putchar_fd()
{
    //Test 1: Output to a .txt file
    int fd1 = open("char.txt", O_WRONLY | O_CREAT);
    char c1 = 'a';
    ft_putchar_fd(c1, fd1);
    close(fd1);
    fd1 = open("char.txt", O_RDONLY | O_CREAT);
    char* result1 = (char*)calloc(5, sizeof(char));
    int x = read(fd1, result1, 5);
    int result = c1 == result1[0];
    printf("Test 1: ft_putchar_fd('a', fd), Result: %s, Expected: %c - %s\n",
        result1, c1, result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    close(fd1);
    free(result1);
    
    //Test 2: Stdout
    char c2 = '\t';
    ft_putchar_fd(c2, 1);
    printf("Test 2: ft_putchar_fd('\t', 1): if this line starts with tab, stdout is working\n");
}

void test_ft_putstr_fd()
{
    //Test 1: Output to a .txt file
    int fd1 = open("str.txt", O_WRONLY | O_CREAT);
    char *str1 = "Hello World!";
    ft_putstr_fd(str1, fd1);
    close(fd1);
    fd1 = open("str.txt", O_RDONLY | O_CREAT);
    char* result1 = (char*)calloc(strlen(str1) + 1, sizeof(char));
    int x = read(fd1, result1, strlen(str1));
    int result = strcmp(result1, str1) == 0;
    printf("Test 1: ft_putstr_fd(\"Hello World!\", fd), Result: %s, Expected: %s - %s\n",
        result1, str1, result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    close(fd1);
    free(result1);
    
    //Test 2: Stdout
    char *str2 = "\t~~~~!";
    ft_putstr_fd(str2, 1);
    printf("Test 2: ft_putstr_fd('\\t~~~~!', 1): if this line starts with tab, stdout is working\n");
}

void test_ft_putendl_fd()
{
    //Test 1: Output to a .txt file
    int fd1 = open("endl.txt", O_WRONLY | O_CREAT);
    char *str1 = "Hello World!";
    char *expected1 = "Hello World!\n";
    ft_putendl_fd(str1, fd1);
    close(fd1);
    fd1 = open("endl.txt", O_RDONLY | O_CREAT);
    char* result1 = (char*) calloc(20, sizeof(char));
    int x = read(fd1, result1, 20);
    int result = strcmp(result1, expected1) == 0;
    printf("Test 1: ft_putendl_fd(\"-12345\", fd) - %s\n",
        result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    close(fd1);
    free(result1);
    
    //Test 1: Output empty string to a .txt file
    int fd2 = open("endl.txt", O_WRONLY | O_CREAT);
    char *str2 = "";
    char *expected2 = "\n";
    ft_putendl_fd(str2, fd2);
    close(fd2);
    fd1 = open("endl.txt", O_RDONLY | O_CREAT);
    char* result2 = (char*) calloc(10, sizeof(char));
    x = read(fd2, result2, strlen(str2)+1);
    result = strcmp(result2, expected2) == 0;
    printf("Test 2: ft_putendl_fd(\"-2147483648\", fd) - %s\n",
        result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    close(fd2);
    free(result2);
    
    //Test 2: Stdout
    char *str3 = " ";
    int n3 = atoi(str3);
    ft_putendl_fd(str3, 1);
    printf("Test 3: ft_putendl_fd(\"\", 1): if there's an empty line above, stdout is working\n");
}

void test_ft_putnbr_fd()
{
    //Test 1: Output to a .txt file
    int fd1 = open("nbr.txt", O_WRONLY | O_CREAT);
    char *str1 = "-12345";
    int n1 = atoi(str1);
    ft_putnbr_fd(n1, fd1);
    close(fd1);
    fd1 = open("nbr.txt", O_RDONLY | O_CREAT);
    char* result1 = (char*) calloc(10, sizeof(char));
    int x = read(fd1, result1, strlen(str1));
    int result = strcmp(result1, str1) == 0;
    printf("Test 1: ft_putnbr_fd(\"-12345\", fd), Result: %s, Expected: %s - %s\n",
        result1, str1, result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    close(fd1);
    free(result1);
    
    //Test 2: Output min int to a .txt file
    int fd2 = open("nbr.txt", O_WRONLY | O_CREAT);
    char *str2 = "-2147483648";
    int n2 = atoi(str2);
    ft_putnbr_fd(n2, fd2);
    close(fd2);
    fd1 = open("nbr.txt", O_RDONLY | O_CREAT);
    char* result2 = (char*) calloc(13, sizeof(char));
    x = read(fd2, result2, strlen(str2));
    result = strcmp(result2, str2) == 0;
    printf("Test 2: ft_putnbr_fd(\"-2147483648\", fd), Result: %s, Expected: %s - %s\n",
        result2, str2, result ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    close(fd2);
    free(result2);
    
    //Test 3: Stdout
    char *str3 = "111111";
    int n3 = atoi(str3);
    ft_putnbr_fd(n3, 1);
    printf("Test 3: ft_putnbr_fd(\"111111\", 1): if this line starts with 111111, stdout is working\n");
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
       printf( BLUE "test_ft_calloc\n" COLOR_RESET);
       test_ft_calloc();
       printf( BLUE "test_ft_strdup\n" COLOR_RESET);
       test_ft_strdup();       
       printf( BLUE "test_ft_substr\n" COLOR_RESET);
       test_ft_substr();
       printf( BLUE "test_ft_strjoin\n" COLOR_RESET);
       test_ft_strjoin();
       printf( BLUE "test_ft_strtrim\n" COLOR_RESET);
       test_ft_strtrim();
       printf( BLUE "test_ft_split\n" COLOR_RESET);
       test_ft_split();
       printf( BLUE "test_ft_itoa\n" COLOR_RESET);
       test_ft_itoa();
       printf( BLUE "test_ft_strmapi\n" COLOR_RESET);
       test_ft_strmapi();
       printf( BLUE "test_ft_striteri\n" COLOR_RESET);
       test_ft_striteri();
       printf( BLUE "test_ft_putchar_fd\n" COLOR_RESET);
       test_ft_putchar_fd();
       printf( BLUE "test_ft_putstr_fd\n" COLOR_RESET);
       test_ft_putstr_fd();
       printf( BLUE "test_ft_putendl_fd\n" COLOR_RESET);
       test_ft_putendl_fd();
       printf( BLUE "test_ft_putnbr_fd\n" COLOR_RESET);
       test_ft_putnbr_fd();

       return (0);
}
