#include <stdlib.h>
#include <stdio.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node {
    int num;
    struct node* next;
} NODE;

void append(NODE** head, const int number) {
    if(*head == NULL) {
        *head = (NODE*)malloc(sizeof(NODE));
        (*head)->next = NULL;
        (*head)->num = number;
        return;
    }
    append(&(*head)->next , number);
}

void display(NODE* head) {
    if(head == NULL) return;
    printf("%d " , head->num);
    display(head->next);
}

void reverse_display( NODE* head ){
    if(head == NULL) return;
    display(head->next);
    printf("%d " , head->num);
}

void free_NODE(NODE **head) {
    if(*head == NULL)
        return;
    free_NODE(&(*head)->next);
    free(*head);
    *head=NULL;
}

void reverse_k_node(NODE* head, int k) {
    static int current = 0;
    static int size =0;
    if(head== NULL) {
        size=current;
        printf("\n%d\n",size);
        return;
    }
    current++;
    reverse_k_node(head->next, k);
    if(current==(size-k) )
        printf("%d\n", head->num);
    current--;
}

#endif //LINKED_LIST_H