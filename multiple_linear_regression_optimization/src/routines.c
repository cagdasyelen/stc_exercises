#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "parameters.h"

#define N 14
#define M 506

void train(double data[][N], double coeff[N],  int m, double alpha)
{
  int i,j,k;
  int rand_num;
  double sum = 0.0;
  int n = 0;
  double hypothesis = 0.0;
  int rand_nums[M]= {0};

  for(i = 0 ; i < m ; i ++)
  {
    rand_nums[i] = rand() % M;
  }

  while(n < 10000)
  {
    for(j=0  ; j < N ; j ++)
    {
      sum = 0;
      for(i = 0 ; i <m ; i ++)
      {

        hypothesis = 0.0;
        for(k = 1 ; k < N ; k ++)
        {
          hypothesis = hypothesis + (coeff[k]*data[rand_nums[i]][k-1]);
        }
        hypothesis = hypothesis + coeff[0]; // x0 is always 1

        sum = sum + (( hypothesis - data[rand_nums[i]][N-1])*data[rand_nums[i]][j-1]);

      }
      coeff[j] = coeff[j] - alpha*(1.0/m)*sum;
    }
    n = n +1;
  }
}

void reset_coeff(double coeff[N])
{
  int i;
  for(i = 0 ; i < N ; i ++){coeff[i]=0.0;}
}




double calculate_cost(double data[][N],double coeff[N])
{
  int i,j;
  double hypothesis = 0.0;
  double err = 0.0;

  for(i = 0 ; i < M ; i ++)
  {
    hypothesis = coeff[0];
    for(j = 1 ; j < N ; j ++)
    {
      hypothesis = hypothesis + coeff[j]*data[i][j-1];
    }
    err = err + pow((hypothesis - data[i][N-1]),2 );
  }

  return sqrt(err);

}

void cost_iteration(double data[][N],double coeff[N], double cost_fn[10000], int index )
{
  int i,j;
  double hypothesis = 0.0;
  double err = 0.0;

  for(i = 0 ; i < M ; i ++)
  {
    hypothesis = coeff[0];
    for(j = 1 ; j < N ; j ++)
    {
      hypothesis = hypothesis + coeff[j]*data[i][j-1];
    }
    err = err + pow((hypothesis - data[i][N-1]),2 );
  }

  cost_fn[index] = sqrt(err);

}
