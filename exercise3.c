/*
 * Exercise 3: Queue Implementation using Singly-Linked Lists
 * Assignment 8 - IPFCE 2025
 * 
 * Implement a queue using singly-linked lists.
 * The queue should maintain FIFO (First-In, First-Out) order.
 */
/* Node structure for the queue */

#include <stdlib.h>
#include "./include/exercise3.h"
/* 
 * Initialize an empty queue
 * q: pointer to the queue structure
 * 
 * Post-condition: queue is empty with front and rear set to NULL
 */
void initialize(queue *q) {
    /* TODO: Initialize the queue */
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
}

/* 
 * Insert item x at the back of queue q
 * q: pointer to the queue structure
 * x: item to be inserted
 * 
 * Pre-condition: queue is not full
 * Post-condition: x is added to the rear of the queue
 */
void enqueue(queue *q, int x) {
    /* TODO: Implement enqueue */
    node *new = malloc(sizeof(node));
    new->data = x;
    new->next = NULL;
    if (q->count == 0)
    {
        q->front = new;
        q->rear = new;
    }
    else
    {
        q->rear->next = new;
        q->rear = new;
    } 
    q->count++;
}

/* 
 * Return (and remove) the front item from queue q
 * q: pointer to the queue structure
 * 
 * Pre-condition: queue must not be empty
 * Post-condition: front item is removed and returned
 */
int dequeue(queue *q) {
    /* TODO: Implement dequeue */
    assert(q->count > 0);
    int x = q->front->data;
    node *temp = q->front->next;
    free(q->front);
    q->front = temp;
    q->count--;
    if (q->count == 0)
    {
        q->front = NULL;
        q->rear = NULL;
    }
    
    return x; 
}

/* 
 * Check if the queue is empty
 * q: pointer to the queue structure
 * Returns: true if queue is empty, false otherwise
 */
bool empty(const queue *q) {
    /* TODO: Implement empty check */
    
    return (q->count == 0); 
}

/* 
 * Check if the queue is full
 * q: pointer to the queue structure
 * Returns: true if queue is full, false otherwise
 */
bool full(const queue *q) {
    /* TODO: Implement full check */
    return false;
}

/* Helper function to print the queue */
void print_queue(const queue *q) {
    printf("Queue (front to rear): ");
    node *current = q->front;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" <- ");
        }
        current = current->next;
    }
    printf("\n");
}