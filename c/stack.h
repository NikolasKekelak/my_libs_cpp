#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#ifndef STACK_H
#define STACK_H

typedef struct stack{
    int size;
    int *storage;
}STACK;

void push(STACK *stack , int element );
void pop( STACK *stack );
void free_stack(STACK *stack);
int top( STACK stack );
bool isEmpty(STACK stack);

void push(STACK *stack , int element ){
     assert(stack->size>=0);
     stack->storage = (int*)realloc(stack->storage, (stack->size+1)*sizeof(int));
     stack->storage[stack->size]=element;
     stack->size++;

}

void pop(STACK *stack){
    stack->storage = (int*)realloc(stack->storage, (stack->size-1)*sizeof(int));
    stack->size--;
}

void free_stack(STACK *stack){
    free(stack->storage);
}

int top(STACK stack){
    return stack.storage[stack.size-1];
}

bool isEmpty(STACK stack){
    return stack.size==0;
}

void full_stack(STACK stack) {
    for(int i = 0 ; i < stack.size ; i++)
        printf(" %d, ",stack.storage[i]);
}
#endif //STACK_H
