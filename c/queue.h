#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>


#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue{
    int size;
    int *storage;
}QUEUE;

void push(QUEUE *queue , int element );
void pop( QUEUE *queue );
void free_queue(QUEUE *queue);
int top( QUEUE queue );
bool isEmpty( QUEUE queue );

void push(QUEUE *queue , const int element ){
    assert(queue->size>=0);
    queue->storage = (int*)realloc(queue->storage, (queue->size+1)*sizeof(int));
    queue->storage[queue->size]=element;
    queue->size++;
}

void pop( QUEUE *queue ){
    int *temp = (int*)calloc(queue->size-1, sizeof(int));
    queue->size--;
    for(int i = 0 ; i < queue->size ; i++)
      temp[i]=queue->storage[i+1];
    free(queue->storage);
    queue->storage = temp;
}

void free_stack(QUEUE *queue){
    free(queue->storage);
}

int front(QUEUE queue){
    return queue.storage[queue.size-1];
}

int back(QUEUE queue){
    return queue.storage[queue.size-1];
}

bool isEmpty(QUEUE queue){
    return queue.size==0;
}


#endif //QUEUE_H
