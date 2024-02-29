#include "libft.h"
#include <stdio.h>
#include <string.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define COLOR_RESET "\x1b[0m"

void	free_node(void *content)
{
	(void *) content;
	return ;
}

void	*map_int(void *i)
{
    int *result = (int *)malloc(sizeof(int));
    if (result) 
    {
        *result = (*(int *)i) * 2;
    }
    return result;
}

void	print_int(void *i)
{
    int result = (*(int *)i) * 2;
    printf("%d, ", result);
}

/* Function Tests */
void test_ft_lstnew()
{
    // Test case 1: Node with int content
    int content1 = 42;
    t_list *node1 = ft_lstnew(&content1);
    int result1a = node1 != NULL;
    int result1b = node1->content == &content1;
    int result1c = node1->next == NULL;
    printf("Test 1: ft_lstnew(42) - content: %d, next: %s - %s\n",
           *(int *)(node1->content), (char *)node1->next,
           result1a && result1b && result1c ? GREEN "PASS" COLOR_RESET
           	: RED "FAIL" COLOR_RESET);

    // Test case 2: Node with string content
    char *content2 = strdup("Hello, World!");
    t_list *node2 = ft_lstnew(content2);
    int result2a = node2 != NULL;
    int result2b = strcmp((char *)node2->content, content2) == 0;
    int result2c = node2->next == NULL;
    printf("Test 2: ft_lstnew(\"Hello World\") - content: %s, next: %s - %s\n",
           (char *)(node2->content), (char *)node2->next,
           result2a && result2b && result2c ? GREEN "PASS" COLOR_RESET
           	: RED "FAIL" COLOR_RESET);

    // Test case 3: Node with NULL content
    t_list *node3 = ft_lstnew(NULL);
    int result3a = node2 != NULL;
    int result3b = node3->content == NULL;
    int result3c = node3->next == NULL;
    printf("Test 3: ft_lstnew(NULL) - content: %s, next: %s - %s\n",
           (char *)node3->content, (char *)node3->next,
           result3a && result3b && result3c ? GREEN "PASS" COLOR_RESET
           : RED "FAIL" COLOR_RESET);
        ft_lstclear(&node1, &free_node);
 	ft_lstclear(&node2, &free);          
	ft_lstclear(&node3, &free);
}

void test_ft_lstadd_front()
{
    // Test case 1: Add a new node to an empty list
    t_list *list1 = NULL;
    char *content1 = strdup("Hello World!");
    t_list *new_node1 = ft_lstnew(content1);
    ft_lstadd_front(&list1, new_node1);
    int result1a = list1 == new_node1;
    int result1b = strcmp((char *)list1->content, content1) == 0;
    int result1c = list1->next == NULL;
    printf("Test 1: ft_lstadd_front(NULL, \"Hello World\") - First node: %s - %s\n",
           (char *)(list1->content),
           result1a && result1b && result1c ? GREEN "PASS" COLOR_RESET 
           : RED "FAIL" COLOR_RESET);

    // Test case 2: Add a new node to a non-empty list
    char *content1a = strdup("Hello");
    t_list *list2 = ft_lstnew(content1a);
    t_list *node = list2;
    char *content2 = strdup("World");
    t_list *new_node2 = ft_lstnew(content2);
    ft_lstadd_front(&list2, new_node2);
    int result2a = list2 == new_node2;
    int result2b = strcmp((char *)list2->content, content2) == 0;
    int result2c = list2->next == node;
    int result2d = list2->next->next == NULL;
    printf("Test 2: ft_lstadd_front(\"Hello\", \"World\") - First node: %s, Sec node: %s - %s\n",
           (char *)(list2->content), (char *)(list2->next->content),
           result2a && result2b && result2c && result2d ? GREEN "PASS" COLOR_RESET 
           : RED "FAIL" COLOR_RESET);
    ft_lstclear(&list1, &free);
    ft_lstclear(&list2, &free);
}

void test_ft_lstadd_back()
{
    // Test case 1: Add a new node to an empty list
    t_list *list1 = NULL;
    int content1 = 42;
    t_list *new_node1 = ft_lstnew(&content1);
    ft_lstadd_back(&list1, new_node1);
    int result1a = list1 == new_node1;
    int result1b = list1->content == &content1;
    int result1c = list1->next == NULL;
    printf("Test 1: ft_lstadd_back(NULL, 42) - First node: %d, Sec node: %p - %s\n",
           *(int *)(list1->content), (void *)(list1->next),
           result1a && result1b && result1c ? GREEN "PASS" COLOR_RESET 
           : RED "FAIL" COLOR_RESET);

    // Test case 2: Add a new node to a non-empty list
    t_list *list2 = ft_lstnew("Hello");
    t_list *node = list2;
    int content2 = 123;
    t_list *new_node2 = ft_lstnew(&content2);
    ft_lstadd_back(&list2, new_node2);
    int result2a = list2 == node;
    int result2b = list2->next->content == &content2;
    int result2c = list2->next == new_node2;
    int result2d = list2->next->next == NULL;
    printf("Test 2: ft_lstadd_back(\"Hello\", 123) - First node: %s, Sec node: %d - %s\n",
           (char *)(list2->content), *(int *)(list2->next->content),
           result2a && result2b && result2c && result2d ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    ft_lstclear(&list1, &free_node);
    ft_lstclear(&list2, &free_node);
}

void test_ft_lstlast()
{
    // Test case 1: Add a new node to an empty list
    t_list *list1 = NULL;
    int content1 = 42;
    t_list *new_node1 = ft_lstnew(&content1);
    ft_lstadd_back(&list1, new_node1);
    t_list *last1 = ft_lstlast(list1);
    int result1a = last1 == new_node1;
    int result1b = last1->content == &content1;
    int result1c = last1->next == NULL;
    printf("Test 1: ft_lstlast(list with one node) - Last content: %d, Next: %s - %s\n",
           *(int *)(last1->content), (char *)(list1->next),
           result1a && result1b && result1c ? GREEN "PASS" COLOR_RESET 
           : RED "FAIL" COLOR_RESET);

    // Test case 2: Add a new node to a non-empty list
    t_list *list2 = ft_lstnew("Hello");
    t_list *node = list2;
    int content2 = 123;
    t_list *new_node2 = ft_lstnew(&content2);
    ft_lstadd_back(&list2, new_node2);
    t_list *last2 = ft_lstlast(list2);
    int result2a = last2 == new_node2;
    int result2b = last2->content == &content2;
    int result2c = list2->next == last2;
    int result2d = last2->next == NULL;
    printf("Test 2: ft_lstlast(list with two nodes) - Last node: %d, Next: %s - %s\n",
           *(int *)(last2->content), (char *)(last2->next),
           result2a && result2b && result2c && result2d ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    ft_lstclear(&list1, &free_node);
    ft_lstclear(&list2, &free_node);
}

void test_ft_lstmap()
{
    // Test case 1: Add a new node to an empty list
    t_list *list1 = NULL;
    int content1 = 1;
    int content2 = 2;
    t_list *new_node1 = ft_lstnew(&content1);
    t_list *new_node2 = ft_lstnew(&content2);
    ft_lstadd_back(&list1, new_node1);
    ft_lstadd_back(&list1, new_node2);
    t_list *list2 = ft_lstmap(list1, &map_int, &free_node);
    int result1a = *(int *)list2->content == *(int *)list1->content * 2;
    int result1b = *(int *)list2->next->content == *(int *)list1->next->content * 2;
    printf("Test 1: ft_lstmap(list with two int nodes: 1,2) - Contents: %d %d, Expected: 2, 4 - %s\n",
           *(int *)(list2->content), *(int *)(list2->next->content),
           result1a && result1b ? GREEN "PASS" COLOR_RESET 
           : RED "FAIL" COLOR_RESET);
    ft_lstclear(&list1, &free_node);
    ft_lstclear(&list2, &free);
}

void test_ft_lstiter()
{
    // Test case 1: Add a new node to an empty list
    t_list *list1 = NULL;
    int content1 = 1;
    int content2 = 2;
    t_list *new_node1 = ft_lstnew(&content1);
    t_list *new_node2 = ft_lstnew(&content2);
    ft_lstadd_back(&list1, new_node1);
    ft_lstadd_back(&list1, new_node2);
    printf("Test 1: ft_lstiteri(list with two int nodes: 1,2) - Contents: ");
    ft_lstiter(list1, &print_int); 
    printf("Expected: 2, 4\n");
    ft_lstclear(&list1, &free_node);
}

void test_ft_lstsize()
{
    // Test case 1: Count nodes in an empty list
    t_list *list1 = NULL;
    int result1 = ft_lstsize(list1);
    printf("Test 1: ft_lstsize(empty list) - Result: %d, Expected: 0 - %s\n",
           result1,
           (result1 == 0) ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    ft_lstclear(&list1, &free);
    
    // Test case 2: Count nodes in a list with one node
    char *content1 = strdup("Hello");
    t_list *list2 = ft_lstnew(content1);
    int result2 = ft_lstsize(list2);
    printf("Test 2: ft_lstsize(list with one node) - Result: %d, Expected: 1 - %s\n",
           result2,
           (result2 == 1) ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    ft_lstclear(&list2, &free);
    
    // Test case 3: Count nodes in a list with multiple nodes
    char *content1a = strdup("Node1");
    char *content2 = strdup("Node2");
    char *content3 = strdup("Node3");
    t_list *list3 = ft_lstnew(content1a);
    ft_lstadd_front(&list3, ft_lstnew(content2));
    ft_lstadd_front(&list3, ft_lstnew(content3));
    int result3 = ft_lstsize(list3);
    printf("Test 3: ft_lstsize(list with multiple nodes) - Result: %d, Expected: 3 - %s\n",
           result3,
           (result3 == 3) ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);
    ft_lstclear(&list3, &free);
}

void test_ft_lstclear()
{
    // Test case 1: Delete a node with string content
    char *content2 = strdup("Hello, World!");
    t_list *node2 = ft_lstnew(content2);
    ft_lstclear(&node2, &free);
    printf("Test 1: ft_lstclear(node with string content) - Result: %p %s\n", node2, 
           (node2 == NULL) ? GREEN "PASS" COLOR_RESET : RED "FAIL" COLOR_RESET);

    // Test case 3: Try to delete a NULL node
    t_list *node3 = ft_lstnew(NULL);
    ft_lstclear(&node3, &free);
    printf("Test 2: ft_lstclear(NULL node) - Result: %p %s\n", node3,
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
    printf(BLUE "test_ft_lstlast\n" COLOR_RESET);
    test_ft_lstlast();
    printf(BLUE "test_ft_lstsize\n" COLOR_RESET);
    test_ft_lstsize();
    printf(BLUE "test_ft_lstmap\n" COLOR_RESET);
    test_ft_lstmap();
    printf(BLUE "test_ft_lstiter\n" COLOR_RESET);
    test_ft_lstiter();
    printf(BLUE "test_ft_lstclear\n" COLOR_RESET);
    test_ft_lstclear();

    return (0);
}
