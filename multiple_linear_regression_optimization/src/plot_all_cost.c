#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "parameters.h"

//Number of features + 1(Desired value)
#define N 14
//Number of samples
#define M 506

#define DEBUG 0


int main()
{

  double data[M][N] = {0.0};
  double coeff[N]={0.0};
  double cost[M] = {0.0};
  double alpha = 0.000001; 
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  char *token = NULL;
  char **tokens;
  int count = 0;

  int i,j,k;

  srand(time(NULL)); 


  //Read data.csv file and pass the data to 2d array called data
  FILE *f = fopen("../data/data.csv", "r");
  if(f == NULL){
    printf("Failed to read file!\nExiting...\n");
    return -1;
  }

  while((read = getline(&line, &len, f)) != -1){
    count++;
    if(DEBUG == 1){
      printf("Retrieved line of length %zu Count : %d:\n", read, count);
      printf("%s", line);
    }
    
    token = strtok(line, ",");
    sscanf(token, "%lf", &data[count-1][0]);
    for(i = 1 ; i < N; i ++)
    {
      token = strtok(NULL,",");
      sscanf(token, "%lf", &data[count-1][i]);
    }
  }
  fclose(f);
  if(DEBUG==1){
    printf("Data Matrix: \n");
    for (i=0; i<M; i++)
    {
      for(j=0; j<N; j++)
        printf("%lf  ", data[i][j]);
      printf("\n");
    }
  }

  FILE *f2 = fopen("../data/all_cost.dat", "w");
  double temp_cost = 0.0;
  //First Stage
  printf("Calculation is started...\n\n");
  reset_coeff(coeff);
  for(i = 1 ; i <= M ; i ++)
  {
    for(j = 0 ; j < 5 ; j ++)
    {
      train(data, coeff, i, alpha);
      temp_cost = temp_cost + calculate_cost(data, coeff);
      reset_coeff(coeff);
    }
    cost[i -1] = temp_cost/5.0;
    temp_cost = 0.0;
    fprintf(f2, "%.12e\n",cost[i-1]);
    printf("For %d samples, the cost is %f\n", i,cost[i-1]);
  }
  
  printf("\n\n The cost data for %d different samples are written into all_cost.dat file!\n\nExiting..\n", M);
  fclose(f2);



}
