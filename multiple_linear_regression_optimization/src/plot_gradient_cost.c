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

  FILE *f2 = fopen("../data/gradient_cost.dat", "w");
  count = 0;
  //First Stage
  printf("Calculation is started...\n\n");
  reset_coeff(coeff);


  int rand_num;
  double sum = 0.0;
  int m = M/2;
  double hypothesis = 0.0;
  int rand_nums[M]= {0};
  double cost[100000] = {0.0};

  for(i = 0 ; i < m ; i ++)
  {
    rand_nums[i] = rand() % M;
  }

  while(count < 10000)
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
    cost_iteration(data, coeff, cost, count);
    fprintf(f2,"%.12e\n", cost[count]);
    count = count +1;
  }


  printf("\n\n The cost iteration data for gradient descent algorithm are written into gradient_cost.dat file!\n\nExiting..\n");
  fclose(f2);



}
