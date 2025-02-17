#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix{
  int **pole;
  int m;
  int n;
}MATRIX;

void malloc_matrix(MATRIX *mat, int m , int n ){
  mat->pole = (int**)calloc(m, sizeof(int*));
  for(int i =0 ; i < m ; i++)
    mat->pole[i] = (int*)calloc(n, sizeof(int));
  mat->m= m;
  mat->n= n;
}

void free_matrix(MATRIX *mat){
     for(int i = 0; i<mat->m ; i++){
         free(mat->pole[i]);
     }
     free(mat->pole);
     mat->pole=NULL;
     mat->m=0;
     mat->n=0;
}

void display_matrix(const MATRIX *mat){
    for(int i =0 ; i < mat->m ; i++)
      {
          printf("[ ");
          for(int j =0 ; j < mat->n; j++)
            printf("%3d", mat->pole[i][j]);
          printf(" ]\n");
      }
}

MATRIX add_matrix(const MATRIX *m1 ,const MATRIX *m2) {
       assert(m1->pole!=NULL && m2->pole!=NULL);
       MATRIX result;
       assert(m1->m==m2->m);
       assert(m1->n==m2->n);
       malloc_matrix(&result, m1->m, m2->n);
       for(int i=0 ; i<result.m ; i++)
         for(int j =0; j<result.n; j++)
           result.pole[i][j]=m1->pole[i][j]+m2->pole[i][j];
       return result;
}

MATRIX substract_matrix(const MATRIX *m1 , const MATRIX *m2) {
  assert(m1->pole!=NULL && m2->pole!=NULL);
  MATRIX result;
  assert(m1->m==m2->m);
  assert(m1->n==m2->n);
  malloc_matrix(&result, m1->m, m1->n);
  for(int i=0 ; i<result.m ; i++)
    for(int j =0; j<result.n; j++)
      result.pole[i][j]=m1->pole[i][j]-m2->pole[i][j];
  return result;
}

MATRIX multiply_matrix(const MATRIX *m1,const MATRIX *m2) {
  assert(m1->pole!=NULL && m2->pole!=NULL);
  assert(m1->n == m2->m);
  MATRIX result;
  malloc_matrix(&result, m1->m, m2->n);
  for (int i = 0; i < m1->m; i++)
    for (int j = 0; j < m2->n; j++)
      for (int k = 0; k < m1->n; k++)
        result.pole[i][j] += m1->pole[i][k] * m2->pole[k][j];
  return result;
}

MATRIX minor(const MATRIX *mat,const int row,const int col) {
  assert(mat->pole!=NULL);

  MATRIX matrix;
  malloc_matrix(&matrix, mat->m - 1, mat->n - 1);

  int new_i = 0, new_j = 0;
  for (int i = 0; i < mat->m; i++) {
    if (i == row) continue;
    new_j = 0;
    for (int j = 0; j < mat->n; j++) {
      if (j == col) continue;
      matrix.pole[new_i][new_j] = mat->pole[i][j];
      new_j++;
    }
    new_i++;
  }

  return matrix;
}

int determinant(const MATRIX *mat) {
  assert(mat->m == mat->n);
  if (mat->m == 1)
    return mat->pole[0][0];
  int sum = 0;
  for (int i = 0; i < mat->m; i++) {
    MATRIX xnor = minor(mat, 0, i);
    sum += pow(-1, i) * mat->pole[0][i] * determinant(&xnor);
    free_matrix(&xnor);
  }
  return sum;
}


#endif //MATRIX_H
