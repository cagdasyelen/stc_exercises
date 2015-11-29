#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
 
  double temp, x;
  int i;
  FILE *f = fopen("rand_exp.dat", "w");
  
  for(i = 0 ; i < 100000 ; i ++){
    //random numbers are taken between 0-(1/3) to make log part negative
    //so that we can have x larger than 0
    temp = ((double)rand()/(double)RAND_MAX)*(1.0/3.0);
    x = -3.0*log(3.0*temp);
    fprintf(f,"%.12e\n",x);
  }

  fclose(f);

  return -1;



}
