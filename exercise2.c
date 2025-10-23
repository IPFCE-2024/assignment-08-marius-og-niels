/*
 * Exercise 2: Insertion Sort for Singly Linked List
 * Assignment 8 - IPFCE 2025
 * 
 * Implement insertion sort for a singly linked list of integers.
 * The list should be sorted in-place from smallest to largest.
 * No new nodes should be allocated - only pointers should be changed.
 */

#include "exercise2.h"

/* 
 * Sort a singly linked list in-place using insertion sort
 * list: pointer to the first node of the list
 * 
 * The function should sort the list by rearranging pointers,
 * not by creating new nodes or swapping data values.
 * Returns pointer to the new head of the sorted list.
 */


void swap(int a, int b, int* x, int n)
{
  /* pre-condition */
  /* a and b are within bounds of x array */
  assert (0 <= a && a < n &&
          0 <= b && b < n);

  /* post-condition */
  int t; /* temporary variable for swapping */
  t = x[a];
  x[a] = x[b];
  x[b] = t;
}

node* isort(int n, int* x)
{
   int i;  /* counter variable */
   int j;  /* counter variable */

   /* pre-condition */
   assert (0 <= n);

   /* post-condition: x[0..n] is sorted */
   for(i = 1; i < n; i = i + 1)
   {
     /* invariant: x[0..i-1] is sorted */
     j = i;
       /* insert next element j into 
        * ordered position
        */
     for(; j > 0; j = j - 1)
     {
       if(x[j] > x[j-1])
         break; /* jth element is in correct position */
       else
         swap(j, j-1, x, n);
     }
   }
}

/* Helper function to print the list */
void print_list(node* list) {
    node* current = list;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" -> NULL\n");
}

/* Helper function to create a node */
node *create_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (!new_node)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Helper function to free the list */
void free_list(node *list)
{
    node *current = list;
    node *next_node;

    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}
