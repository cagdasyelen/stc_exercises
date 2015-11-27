#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "parameters.h"



void gram_schmidt()
{
  //Hardcode your input vectors here
  double v1[3] = {4.0,1.0,-1.0};
  double v2[3] = {0.0,5.0,2.0};
  double v3[3] = {-1.0,4.0,3.0};
  double u1[3] = {0.0};
  double u2[3] = {0.0};
  double u3[3] = {0.0};
  double e1[3] = {0.0};
  double e2[3] = {0.0};
  double e3[3] = {0.0};
  int n = 3;
  //Hardcode ends

  int i;
  double temp_coeff;
  double temp_coeff2;
  double temp_norm;
  //First Vector
  
  for (i = 0 ; i < n ; i ++)
  {
    u1[i] = v1[i];
  }
  temp_norm = norm2(u1, n);
  for(i = 0 ; i < n ; i ++)
  {
    u1[i] = u1[i] / temp_norm;
  }



  //Second Vector
  temp_coeff = proj_coeff(v2,u1,n);
  for(i = 0 ; i <n ; i++)
  {
    u2[i] = v2[i] - (temp_coeff*u1[i]);
  }
  temp_norm = norm2(u2,n);
  for(i = 0 ; i < n ; i ++)
  {
    u2[i] = u2[i] / temp_norm;
  }

  //Third Vector
  temp_coeff = proj_coeff(v3,u1,n);
  temp_coeff2 = proj_coeff(v3,u2,n);
  for(i = 0 ; i < n ; i ++)
  {
    u3[i] = v3[i] - (temp_coeff*u1[i]) - (temp_coeff2*u2[i]);
  }
  temp_norm = norm2(u3,n);
  for(i = 0 ; i < n ; i ++)
  {
    u3[i] = u3[i] / temp_norm;
  }


  //Print

  printf("\n----------PART 2 : Gram_Schmidt----------\n");

  printf("Normalized vectors : \n");
  printf("\nVector e1: \n");
  print_vector(u1,n);
  printf("\nVector e2: \n");
  print_vector(u2,n);
  printf("\nVector e3: \n");
  print_vector(u3,n); 

  printf("\n----------EndOfGram_Schmidt---------\n\n");
   
  
}
