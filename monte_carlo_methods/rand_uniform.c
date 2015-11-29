#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
 
  double temp;
  int i;
  FILE *f = fopen("rand_uniform.dat", "w");
  
  for(i = 0 ; i < 100000 ; i ++){
    temp = (((double)rand()/(double)RAND_MAX)*10.0) - 5.0;
    fprintf(f,"%.12e\n",temp);
  }

  fclose(f);

  return -1;



}
