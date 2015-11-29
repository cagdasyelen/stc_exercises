#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
 
  double u,y;
  double c = 2.5;
  int i = 0;
  FILE *f = fopen("rand_normal.dat", "w");
  
  while(i < 100000){
    u = ((double)rand()/(double)RAND_MAX);
    y = ((double)rand()/(double)RAND_MAX)*10.0 - 5.0;
    if(u <= ((1/sqrt(2.0*M_PI))*exp(y*y/-2.0))){
      i++;
      fprintf(f,"%.12e\n",y);
    }
  }

  fclose(f);

  return -1;



}
