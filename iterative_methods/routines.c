#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "parameters.h"



void print_matrix(double matrix[3][3])
{
  int i, j;
  for (i = 0 ; i < 3 ; i++)
  {
    for (j = 0; j < 3; j++)
    {
      printf("%.12e ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}



void print_vector(double vector[], int n)
{
  int i;
  printf("\n");
  for(i = 0 ; i < n ; i++)
  {
    printf("%.12e \n",vector[i]);
  }
}

int check_convergence(double A[3][3], double x[3], double b[3])
{
  double temp[3] = {0};
  int i,j;
  int result;
  double err_sum = 0;

  for(i = 0 ; i < 3 ; i ++)
  {
    for(j = 0 ; j <3 ; j++)
    {
      temp[i] =temp[i] + A[i][j] * x[j];
    }
  }
  
  for(i = 0 ; i <3 ; i++)
  {
    err_sum = err_sum + fabs(temp[i] - b[i]);
  }
 
  if(err_sum < 0.000001){result = 1;}
  else{result = 0;}

  return result;
}


double dot_product(double vec1[], double vec2[], int n)
{
  int i;
  double sum = 0.0;
  for(i = 0 ; i < n ; i++)
  {
    sum = sum + vec1[i]*vec2[i];
  }

  return sum;
} 

double proj_coeff(double v1[],double v2[],int n)
{
  double coeff = 0.0;
  int i;
  double temp1,temp2;
  for(i = 0 ; i < n ; i ++)
  {
    temp1 = dot_product(v1,v2,n);
    temp2 = dot_product(v2,v2,n);
    coeff = temp1/temp2;
  }

  return coeff;
}

double norm2(double vec[], int n)
{
  int i;
  double sum = 0.0;
  for(i = 0 ; i < n ; i++)
  {
    sum = sum + vec[i]*vec[i];
  }

  return sqrt(sum);
}



 
