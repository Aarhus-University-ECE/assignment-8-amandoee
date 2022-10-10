#include "list_queue.h"


void init_queue(queue *q)
{
  // Add your init_queue
  q->front = NULL;
  q->rear = NULL;
  q->size = 0;

}

int empty(queue *q)
{
  // Add your empty function  
  if (q->size == 0) {
    return 1;
  } else {
    return 0;
  }

}

void enqueue(queue *q, int x)
{
  // Add your enqueue function
  qnode *new_in_queue = malloc(sizeof(qnode));

  new_in_queue->data=x;

  if (q->rear == NULL) {
    q->rear = new_in_queue;
    q->rear->next=NULL;
    q->front = new_in_queue;
  } else {

    q->rear->next=new_in_queue;
    q->rear=new_in_queue;
  }

  q->size+=1;

}

int dequeue(queue *q)
{
  // Add your dequeue function

  int front_value = q->front->data;

  q->front=q->front->next;

  q->size-=1;

  if (q->size == 0) {
    q->rear = NULL;
  }
  
  return front_value;
}


//When enqueueing flere værdier, fejl i rækkefølge.