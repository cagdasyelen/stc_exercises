#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "parameters.h"


void gauss_seidel()
{
  double A[3][3] = { {1.0, 1.0, 2.0},
                     {2.0, 3.0, 5.0},
                     {3.0, 3.0, 6.0}};
  double L[3][3] = { {1.0, 0.0, 0.0},
                     {2.0, 3.0, 0.0},
                     {3.0, 3.0, 6.0}};
  double L1[3][3] = { {1.0, 0.0, 0.0},
                     {-2.0/3.0, 1.0/3.0, 0.0},
                     {-1.0/6.0, -1.0/6.0, 1.0/6.0}};
  double U[3][3] = { {0.0, 1.0, 2.0},
                     {0.0, 0.0, 5.0},
                     {0.0, 0.0, 0.0}};

  double b[3] = {12.0, 27.0, 36.0};
  double x[3] = {0.0};
  double temp1[3] = {0};
  double temp2[3] = {0};
  double temp3[3] = {0};
  double b_check[3] = {0};
  int check = 0;
  int count = 0;
  int i,j;


  printf("\n----------Question2_Gauss-Seidel : ----------\n\n");
  while((check==0) && (count < 250))
  {
    for(i = 0 ; i < 3 ; i++)
    {
      temp1[i] = 0.0;
      temp2[i] = 0.0;
      temp3[i] = 0.0;
    }   

    for(i = 0 ; i < 3 ; i++)
    {
      for(j = 0 ; j <3 ; j++)
      {
        temp1[i] = temp1[i] +  U[i][j] * x[j];
      }
      temp2[i] = b[i] - temp1[i];
    }

    for(i = 0 ; i < 3 ; i++)
    {
      for(j = 0 ; j < 3 ; j++)
      {
        temp3[i] = temp3[i] + L1[i][j]*temp2[j];
      }
      x[i] = temp3[i];
    }
    
    count = count + 1;
    check = check_convergence(A,x,b);
    
  }

  for(i = 0 ; i <3 ; i++)
  {
    for(j = 0 ; j <3 ; j++)
    {
      b_check[i] = b_check[i] + A[i][j]*x[j];
    }
  }

  if(count == 250){printf("Gauss-Seidel is failed! (Maximum number of iterations is reached)\n");}
  else
  {
    printf("Gauss-Seidel Method is converged in %d iterations.\n", count);
    printf("Solution,  x: \n");
    print_vector(x,3);
  }
  printf("\n----------EndOfGauss_SeidelMethod----------\n\n");
}
