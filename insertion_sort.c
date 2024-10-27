#include "insertion_sort.h"
#include <stdio.h>
#include "node.h"

node* isort(node *list) {
    node *sorted_list = NULL; //Initialize sorted_list pointer to point to empty sorted list
    node *current = list; //Initialize current pointer to point to head of the list

    while (current != NULL) { //Go through all nodes
        node *nxt = current->next; //Store next node in list before modifying current's next pointer
        //If sorted list is empty or data in sorted list is not lower than current data
        if (sorted_list == NULL || sorted_list->data >= current->data) {
            current->next = sorted_list; //Current's next-pointer points to first node in sorted list
            sorted_list = current; //Update sorted list to point to current
        }
        //Sorted list is not empty or data in sorted list is lower than current data
        else {
            node *temp = sorted_list; //Initialize pointer temp to point to head in list
            while (temp->next != NULL && temp->next->data < current->data) {
                //Find correct position to insert current in sorted list
                temp = temp->next; //Move to the next node
            }
            //Insert current between temp and temp->next
            current->next = temp->next; //Current points to the same node temp points to
            temp->next = current; //Temp points to current node
        }
        current = nxt; //Move on to the next node in list
    }
    return sorted_list;
}

