#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
 
  double y,u;
  int i,n;
  int check = 0;
  double result[5] = {0.0};
  double sum = 0.0;
  
  for(n = 0 ; n <=4 ; n ++)
  {
    sum = 0.0;
    check = 0;
    for(i = 0 ; i < pow(10,n+1) ; i ++)
    {
      while(check == 0)
      {
        u=((double)rand()/(double)RAND_MAX);
        y=((double)rand()/(double)RAND_MAX)*10.0 -5.0;
        if(u <= ((1/sqrt(2.0*M_PI))*exp(y*y/-2.0))){
          check = 1;
          break;
        }
      }
      sum = sum + ((cos(y) + 5.0));
    }
    result[n] = sum*sqrt(2.0*M_PI)/(pow(10,n+1));
    printf("%d   %.12e\n",(int)pow(10,n+1), result[n]);
  }
  
  
  return -1;



}
