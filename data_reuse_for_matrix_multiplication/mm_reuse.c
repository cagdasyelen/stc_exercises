#include <stdio.h>
#include <time.h>
#include <math.h>


int main()
{
  int i,j,k;
  int N = 2000;
  double A[2000][2000];
  double B[2000][2000];
  double C[2000][2000];
  double sum;

  for(i = 0 ; i < N ; i ++)
  {
    for(j = 0 ; j < N ; j ++)
    {
      A[i][j] = 1.0;
      B[i][j] = 1.0;
    }
  }

  for(i = 0 ; i <N ; i ++)
  {
    for(j = 0 ; j < N ; j++)
    {
      sum = 0;
      for(k = 0 ; k < N ; k ++)
      {
        sum = sum + A[i][k] * B[k][j];
      }
      C[i][j] = sum;
    }
  }
  return -1;
}
