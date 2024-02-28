#include "libft.h"
#include <stdio.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define COLOR_RESET "\x1b[0m"

/* Function Tests */
void test_ft_lstnew()
{
    // Test case 1: Node with int content
    int content1 = 42;
    t_list *node1 = ft_lstnew(&content1);
    int result1a = node1 != NULL;
    int result1b = node1->content == &content1;
    int result1c = node1->next == NULL;
    printf("Test 1: ft_lstnew(42) - content: %d, next: %p - %s\n",
           *(int *)(node1->content), node1->next,
           result1a && result1b && result1c ? GREEN "PASS" COLOR_RESET
           	: RED "FAIL" COLOR_RESET);

    // Test case 2: Node with string content
    char *content2 = "Hello, World!";
    t_list *node2 = ft_lstnew(content2);
    int result2a = node2 != NULL;
    int result2b = strcmp((char *)node2->content, content2) == 0;
    int result2c = node2->next == NULL;
    printf("Test 2: ft_lstnew(\"Hello World\") - content: %s, next: %p - %s\n",
           (char *)(node2->content), node2->next,
           result2a && result2b && result2c ? GREEN "PASS" COLOR_RESET
           	: RED "FAIL" COLOR_RESET);

    // Test case 3: Node with NULL content
    t_list *node3 = ft_lstnew(NULL);
    int result3a = node2 != NULL;
    int result3b = node3->content == NULL;
    int result3c = node3->next == NULL;
    printf("Test 3: ft_lstnew(NULL) - content: %p, next: %p - %s\n",
           node3->content, node3->next,
           result3a && result3b && result3c ? GREEN "PASS" COLOR_RESET
           	: RED "FAIL" COLOR_RESET);
}

void test_ft_lstadd_front()
{
    // Test case 1: Add a new node to an empty list
    t_list *list1 = NULL;
    int content1 = 42;
    t_list *new_node1 = ft_lstnew(&content1);
    ft_lstadd_front(&list1, new_node1);
    CU_ASSERT_PTR_EQUAL(list1, new_node1);
    CU_ASSERT_PTR_EQUAL(list1->content, &content1);
    int result list1->next);
    printf("Test 1: ft_lstadd_front(NULL, 42) - List: %p, Content: %d, Next: %p - %s\n",
           (void *)(list1), *(int *)(list1->content), (void *)(list1->next),
           (list1 == new_node1 && list1->content == &content1 && list1->next == NULL) ? GREEN "PASS" COLOR_RESET
                                                                                      : RED "FAIL" COLOR_RESET);

    // Test case 2: Add a new node to a non-empty list
    t_list *list2 = ft_lstnew("Hello");
    t_list *node = list2;
    int content2 = 123;
    t_list *new_node2 = ft_lstnew(&content2);
    ft_lstadd_front(&list2, new_node2);
    CU_ASSERT_PTR_EQUAL(list2, new_node2);
    CU_ASSERT_PTR_EQUAL(list2->content, &content2);
    CU_ASSERT_PTR_EQUAL(list2->next, node);
    CU_ASSERT_PTR_NULL(list2->next->next);
    printf("Test 2: ft_lstadd_front(\"Hello\", 123) - List: %p, Content: %d, Next: %p - %s\n",
           (void *)(list2), *(int *)(list2->content), (void *)(list2->next),
           (list2 == new_node2 && list2->content == &content2 && list2->next == node) ? GREEN "PASS" COLOR_RESET
                                                                                      : RED "FAIL" COLOR_RESET);
    // ft_lstclear(&list1, &free);
    // ft_lstclear(&list2, &free);
}

void test_ft_lstadd_back()
{
    // Test case 1: Add a new node to an empty list
    t_list *list1 = NULL;
    int content1 = 42;
    t_list *new_node1 = ft_lstnew(&content1);
    ft_lstadd_back(&list1, new_node1);
    CU_ASSERT_PTR_EQUAL(list1, new_node1);
    CU_ASSERT_PTR_EQUAL(list1->content, &content1);
    CU_ASSERT_PTR_NULL(list1->next);
    printf("Test 1: ft_lstadd_back(NULL, 42) - List: %p, Content: %d, Next: %p - %s\n",
           (void *)(list1), *(int *)(list1->content), (void *)(list1->next),
           (list1 == new_node1 && list1->content == &content1 && list1->next == NULL) ? GREEN "PASS" COLOR_RESET
                                                                                      : RED "FAIL" COLOR_RESET);

    // Test case 2: Add a new node to a non-empty list
    t_list *list2 = ft_lstnew("Hello");
    t_list *node = list2;
    int content2 = 123;
    t_list *new_node2 = ft_lstnew(&content2);
    ft_lstadd_back(&list2, new_node2);
    CU_ASSERT_PTR_EQUAL(list2, node);
    CU_ASSERT_PTR_EQUAL(list2->next->content, &content2);
    CU_ASSERT_PTR_EQUAL(list2->next, new_node2);
    CU_ASSERT_PTR_NULL(list2->next->next);
    printf("Test 2: ft_lstadd_back(\"Hello\", 123) - List: %p, Content: %s, Next: %p - %s\n",
           (void *)(list2), (char *)(list2->content), (void *)(list2->next),
           (list2 == node && list2->next->content == &content2 && list2->next == new_node2) ? GREEN "PASS" COLOR_RESET
                                                                                            : RED "FAIL" COLOR_RESET);
    // ft_lstclear(&list1, &free);
    // ft_lstclear(&list2, &free);
}

void test_ft_lstsize()
{
    // Test case 1: Count nodes in an empty list
    t_list *list1 = NULL;
    int result1 = ft_lstsize(list1);
    CU_ASSERT_EQUAL(result1, 0);
    printf("Test 1: ft_lstsize(empty list) - Result: %d, Expected: 0 - %s\n",
           result1,
           (result1 == 0) ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

    // Test case 2: Count nodes in a list with one node
    t_list *list2 = ft_lstnew("Hello");
    int result2 = ft_lstsize(list2);
    CU_ASSERT_EQUAL(result2, 1);
    printf("Test 2: ft_lstsize(list with one node) - Result: %d, Expected: 1 - %s\n",
           result2,
           (result2 == 1) ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

    // Test case 3: Count nodes in a list with multiple nodes
    t_list *list3 = ft_lstnew("Node1");
    ft_lstadd_front(&list3, ft_lstnew("Node2"));
    ft_lstadd_front(&list3, ft_lstnew("Node3"));
    int result3 = ft_lstsize(list3);
    CU_ASSERT_EQUAL(result3, 3);
    printf("Test 3: ft_lstsize(list with multiple nodes) - Result: %d, Expected: 3 - %s\n",
           result3,
           (result3 == 3) ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

void test_ft_lstdelone()
{
    // Test case 1: Delete a node with integer content
    int *content1 = malloc(sizeof(int));
    *content1 = 42;
    t_list *node1 = ft_lstnew(content1);
    ft_lstdelone(node1, &free);
    CU_ASSERT_PTR_NULL(node1);
    printf("Test 1: ft_lstdelone(node with int content) - Result: %p, Content: %d - %s\n",
           (void *)node1, sizeof(content1),
           (node1 == NULL) ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

    // Test case 2: Delete a node with string content
    char *content2 = strdup("Hello, World!");
    t_list *node2 = ft_lstnew(content2);
    ft_lstdelone(node2, &free);
    CU_ASSERT_PTR_NULL(node2);
    printf("Test 2: ft_lstdelone(node with string content) - Result: %p, Content: %p - %s\n",
           (void *)node2, (void *)content2,
           (node2 == NULL) ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

    // Test case 3: Try to delete a NULL node
    t_list *node3 = NULL;
    ft_lstdelone(node3, &free);
    CU_ASSERT_PTR_NULL(node3);
    printf("Test 3: ft_lstdelone(NULL node) - Result: %p - %s\n",
           (void *)node3,
           (node3 == NULL) ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
}

int main()
{
    printf(BLUE "test_ft_lstnew\n" COLOR_RESET);
    test_ft_lstnew();
    printf(BLUE "test_ft_lstadd_front\n" COLOR_RESET);
    test_ft_lstadd_front();
    printf(BLUE "test_ft_lstadd_back\n" COLOR_RESET);
    test_ft_lstadd_back();
    print(BLUE "test_ft_lstsize\n" COLOR_RESET);
    test_ft_lstsize();
    printf(BLUE "test_ft_lstdelone\n" COLOR_RESET);
    test_ft_lstdelone();

    return (0);
}
