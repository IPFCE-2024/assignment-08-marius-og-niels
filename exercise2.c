/*
 * Exercise 2: Insertion Sort for Singly Linked List
 * Assignment 8 - IPFCE 2025
 * 
 * Implement insertion sort for a singly linked list of integers.
 * The list should be sorted in-place from smallest to largest.
 * No new nodes should be allocated - only pointers should be changed.
 */

#include "exercise2.h"
#include <stdio.h>

/* 
 * Sort a singly linked list in-place using insertion sort
 * list: pointer to the first node of the list
 * 
 * The function should sort the list by rearranging pointers,
 * not by creating new nodes or swapping data values.
 * Returns pointer to the new head of the sorted list.
 */


node* isort(node* list) {
    // Null liste
    node* sorted = NULL;  

    // Bliver ved indtil enden af listen
    while (list != NULL) {

        // Gem node og ryk videre til næste
        node* current = list;
        list = list->next; 

        // Hvis den sorteret liste er tom, eller den første værdi er større end eller lig den aktuelle
        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } 
        else {
            node* temp = sorted;
            
            // rykkere igennem indtil den finder en "data" større end current "data"
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }


            current->next = temp->next;
            temp->next = current;
        } 
    }


    return sorted; 
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
