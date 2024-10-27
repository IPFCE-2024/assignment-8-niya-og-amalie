#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// Opgave 3
void initialize(queue *q) {
    //Initialize queue
    q->front = NULL; //Set front pointer (pointer to first node) to NULL
    q->rear = NULL; //Set rear pointer (pointer to last node) to NULL
    q->size = 0; //Start off with an empty queue
}

bool empty(const queue *q) {
    //Chck if queue is empty
    return q->size == 0; //Return true if size is 0
}

bool full(const queue *q) {
    //Check if queue is empty
    return false; //Queue can't be full as it is based on a singly-linked list
}

void enqueue(queue *q, int x) {
    //Add an element to the queue
    node *new_node = (node *)malloc(sizeof(node)); //Allocate memory for a new node
    if (new_node == NULL) {
        printf("Memory allocation failed\n"); //Print error message if allocation fails
        return;
    }
    new_node->data = x; //Set data of new node
    new_node->next = NULL; //Set the next pointer of new node to NULL (new node is at the end of the queue)

    if (q->rear == NULL) {
        q->front = new_node; //If queue is empty set front to point to the new node (new node is the first en queue)
    } else {
        q->rear->next = new_node; //Otherwise set the last node (rear) to point to new node
    }
    q->rear = new_node; //Set rear node to new node
    q->size++; //Increment size of queue to include new node
}

int dequeue(queue *q) {
    //Remove an element from the queue
    if (empty(q)) {
        printf("Queue is empty\n"); //Print error message if queue is empty
        return -1;  // REturn a sentinel value for empty queue
    }
    int value = q->front->data; //Get data from first node
    node *temp = q->front; //Temporarily store the front node
    q->front = q->front->next; //Move front pointer to the next node
    free(temp); //Free memory of the old node

    if (q->front == NULL) {
        q->rear = NULL; //If queue is now empty set rear to NULL
    }
    q->size--; //Decrement size of queue
    return value; //Return value of removed node
}

// Opgave 4
void push(int element, node **head) {
    node *new_node = (node *)malloc(sizeof(node)); // Allocate memory for a new node
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = element; // Set data of the new node
    new_node->next = *head; // Set the next pointer of the new node to the current head
    *head = new_node; // Update head to point to the new node
}

int pop(node **head) {
    if (*head == NULL) {
        printf("Stack is empty\n");
        return -1; // Return a sentinel value to indicate the stack is empty
    }
    int value = (*head)->data; // Get data from the current head
    node *temp = *head; // Temporarily store the current head
    *head = (*head)->next; // Move head to the next node
    free(temp); // Free memory of the old head node
    return value; // Return the data of the popped node
}

void enqueueStack(queue *q, int x) {
     push(x, &(q->front)); // Push element to the front stack
    q->size++; // Increment size of the queue
}

int dequeueStack(queue *q) {
    if (q->rear == NULL) {
        while (q->front != NULL) {
            int element = pop(&(q->front)); // Pop elements from front stack
            push(element, &(q->rear)); // Push them to the rear stack
        }
    }
    int value = pop(&(q->rear)); // Pop the top element from rear stack
    if (value != -1) {
        q->size--; // Decrement size of the queue
    }
    return value; // Return the dequeued value
}