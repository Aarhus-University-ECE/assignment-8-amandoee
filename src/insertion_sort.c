#include "insertion_sort.h"
#include "linked_list.h"



void sort(linked_list *llPtr)
{
 // Add your sort function here

node_t *temp_node = NULL;
node_t *temp_node_next = NULL;

node_t *previous = llPtr->head;
node_t *current = previous->next;

if (llPtr->head==NULL) {
    printf("den er tom.... Kan ikke sortere");
    return;
}

//Loop, as long as there is a next node defined/allocated
while (previous->next != NULL) {

    //If the current node is smaller than the previous node, find correct placement.
    if (current->data < previous->data) {


        //Connect the previous node to the next node of the current node
        temp_node = current;
        temp_node_next = current->next;

        previous->next=current->next;

        node_t *placement =llPtr->head;
        while (placement->next->data < temp_node->data) {
            placement = placement->next;
        }

        if (llPtr->head==placement) {

            temp_node->next=llPtr->head;
            llPtr->head = temp_node;

        } else {
            temp_node->next = placement->next;
            placement->next = temp_node;
        }
        

        
    }
    //Increment the pointers to the next node
    previous = current;
    current = previous->next;
    
}


}
