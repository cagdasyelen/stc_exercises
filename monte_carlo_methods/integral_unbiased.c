#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
 
  double x;
  int i,n;
  double result[5] = {0.0};
  double sum = 0.0;
  
  for(n = 0 ; n <=4 ; n ++)
  {
    sum = 0.0;
    for(i = 0 ; i < pow(10,n+1) ; i ++)
    {
      x = ((double)rand()/(double)RAND_MAX)*10.0 -5.0;
      sum = sum + (exp(x*x/-2.0)*(cos(x) + 5.0));
    }
    result[n] = sum/pow(10,n);
    printf("%d   %.12e\n",(int)pow(10,n+1), result[n]);
  }
  

  
  return -1;



}
