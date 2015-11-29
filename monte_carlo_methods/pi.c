#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
 
  double x,y,r;
  int i,n;
  int red[5] = {0};
  double pi[5] = {0.0};
  
  for(n = 0 ; n <=4 ; n ++)
  {
    for(i = 0 ; i < pow(10,n+1) ; i ++)
    {
      x = ((double)rand()/(double)RAND_MAX);
      y = ((double)rand()/(double)RAND_MAX);
      if(sqrt(x*x + y*y) <= 1.0)
      {
        red[n] = red[n] + 1;
      }
    }
    pi[n] = 4.0*(double)red[n]/(double)pow(10,n+1);
    printf("%d   %.12e\n",(int)pow(10,n+1), pi[n]);
  }
  

  
  return -1;



}
