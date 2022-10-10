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
}

while (previous->next != NULL) {

    if ((current)->data < previous->data) {

        temp_node = current;
        temp_node_next = (current)->next;

        previous->next=(current)->next;


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
    previous = current;
    current = previous->next;
    
}


}
