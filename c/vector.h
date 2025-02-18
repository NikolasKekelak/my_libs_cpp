//
// Created by nikol on 2/18/2025.
//
#define usi unsigned short int
#define vcap  vector->capacity
#define vsize vector->size
#define vstorage vector->storage
#include <stdbool.h>

void swap(int *a, int *b) {
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}

#ifndef VECTOR_H
#define VECTOR_H

#define new_vector {NULL, 0 , 0}




typedef struct vector{
  int *storage;
  usi size;
  usi capacity;
}VECTOR;

usi size(const VECTOR *vector);
usi capacity(const VECTOR *vector);
bool isEmpty(const VECTOR *vector);
void push_back(VECTOR *vector, int x);
void pop_back(VECTOR *vector);
void push_front(VECTOR *vector, int x);
void insert(VECTOR *vector, int x , int index);
void erase(VECTOR *vector, int index);
int  access(const VECTOR *vector , int index);
int* find_adress(const VECTOR *vector , int index);
int find_index(const VECTOR *vector , int index);
void sort_from_lower(VECTOR *vector);
void sort_from_upper(VECTOR *vector);
void clear(VECTOR *vector);
int count(const VECTOR *vector , int index);

inline usi size(const VECTOR *vector) {
    return vsize;
}

inline usi capacity(const VECTOR *vector) {
    return vcap;
}

inline bool isEmpty(const VECTOR *vector) {
     return vcap==0;
}

inline void push_back(VECTOR *vector, const int x) {
    if (vsize == vcap) {
        unsigned short int new_capacity = (vcap == 0) ? 1 : vcap * 2;;
        vstorage = (int *)realloc(vstorage, new_capacity * sizeof(int));
        vcap = new_capacity;
    }
    vector->storage[vector->size++] = x;
}

inline void push_front(VECTOR *vector, int x) {
    if (vsize == vcap) {
        unsigned short int new_capacity = (vcap == 0) ? 1 : vcap * 2;;
        vstorage = (int *)realloc(vstorage, new_capacity * sizeof(int));
        vcap = new_capacity;
    }
    for(int i = vsize-1  ; i >= 0; i--)
        vstorage[i+1]=vstorage[i];
    vstorage[0]=x;
}

inline void pop_back(VECTOR *vector) {
    vsize--;
    if(vsize==(vcap/4) ) {
        vcap/=4;
        vstorage=(int*)realloc(vstorage, vcap*sizeof(int));
    }

}

inline int  access(const VECTOR *vector , int index) {
    return vstorage[index];
}

inline void clear( VECTOR *vector ) {
    free(vstorage);
    vsize=0;
    vcap=0;
}

static inline void display(const VECTOR *vector) {
    for(int i = 0 ; i < vsize; i++)
        printf("%d\n", vstorage[i] );
}

inline void sort_from_lower(VECTOR *vector) {
    for(int i =0; i< vsize ; i ++)
        for(int j=0; j<vsize-1 ; j++)
            if(vstorage[j]>vstorage[j+1])
                swap(&vstorage[j], &vstorage[j+1]);
}

inline void sort_from_upper(VECTOR *vector) {
    for(int i =0; i< vsize ; i ++)
        for(int j=0; j<vsize-1 ; j++)
            if(vstorage[j]<vstorage[j+1])
                swap(&vstorage[j], &vstorage[j+1]);
}

inline int* find_adress(const VECTOR *vector , const int x) {
    for(int i =0 ; i < vsize ; i ++) {
        if( vstorage[i] == x )
            return vstorage+i;
    }
}

inline int find_index(const VECTOR *vector , const int x) {
    for(int i =0 ; i < vsize ; i ++) {
        if( vstorage[i] == x )
            return i;
    }
    return -1;
}

inline int count(const VECTOR *vector , const int x) {
    int count = 0;
    for(int i =0 ; i < vsize ; i ++)
        if( vstorage[i] == x )
            count++;
    return count;
}

inline void erase(VECTOR *vector, int index) {
    if(index<vsize && vsize>=0 ) {
        int *temp = (int*)calloc(vsize-1, sizeof(int));
        int k=0;
        for(int i = 0 ; i < vsize; i++) {
            if(i==index)
                continue;
            temp[k++]= vstorage [i];
        }
        free(vstorage);
        vstorage = temp;
        vsize--;
    }
    else {
        printf("\nOut of bounds\n");
        exit(1);
    }
}

inline void insert(VECTOR *vector, int x , int index) {
    if(index<vsize && vsize>=0 ) {
        int *temp = (int*)calloc(vsize-1, sizeof(int));
        int k=0;
        for(int i = 0 ; i < vsize; i++) {
            if(i==index)
                temp[k++]=x;
            temp[k++]= vstorage [i];
        }
        free(vstorage);
        vstorage = temp;
    }
    else {
        printf("\nOut of bounds\n");
        exit(1);
    }
}

#endif //VECTOR_H
