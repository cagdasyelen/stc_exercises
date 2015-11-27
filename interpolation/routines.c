#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "parameters.h"



void print_matrix(double matrix[64])
{
  int i, j;
  for (i = 0 ; i < 8 ; i++)
  {
    for (j = 0; j < 8; j++)
    {
      printf("%.12e ", matrix[8*i + j]);
    }
    printf("\n");
  }
  printf("\n");
}



void print_vector(double vector[8])
{
  int i;
  printf("\n");
  for(i = 0 ; i < 8 ; i++)
  {
    printf("%.12e \n",vector[i]);
  }
}
