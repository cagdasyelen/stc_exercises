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

  int num_samples;
  int upper = M;
  int lower = 0;



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

  //Calculating the error tolerance
  printf("Calculating the error tolerance by sampling and averaging 10 different samples...\n\n");
  double threshold_sum = 0.0;
  double err_threshold;
  for(i = 1 ; i <= 10 ; i ++)
  {
    train(data,coeff,i*(M/10),alpha );
    threshold_sum = threshold_sum + calculate_cost(data,coeff);
    reset_coeff(coeff);
  }
  err_threshold = threshold_sum/10.0;
  printf("Error tolerance : %f \n\n",err_threshold);



  //First Stage
  printf("Finding a point near local minimum by using binary search...\n\n");

  double temp_cost;
  int secure_loop = 0;
  while(lower + 2 < upper)
  {
      if(secure_loop > 20)
      {
        break;
        printf("It did nit converge! Secure loop parameter caused to break the loop...\n");
      }
      secure_loop ++;
      temp_cost = 0.0;
      num_samples = (lower + upper) /2 ;
      for(j = 0 ; j < 5 ; j ++)
      {
        train(data,coeff, num_samples,alpha);
        temp_cost = temp_cost + calculate_cost(data, coeff);
        reset_coeff(coeff);
      }
      temp_cost = temp_cost/5.0;
      printf("Log: For %d number of random samples, the cost is : %f\n", num_samples, temp_cost);
      if(temp_cost > err_threshold){lower = num_samples;}
      else{upper = num_samples;}
  }

  //Second stage
  printf("\nFinding the minimum point near %d number of samples...\n\n", num_samples);
  
  double min = err_threshold*10.0;
  int min_index = num_samples;
  for(i= (num_samples-(M/50)) ; i <=(num_samples + (M/50)) ; i ++)
  {
    temp_cost = 0.0;
    for (j = 0 ; j < 5 ; j ++)
    {
      train(data, coeff, i, alpha);
      temp_cost = temp_cost + calculate_cost(data,coeff);
      reset_coeff(coeff);
    }
    temp_cost = temp_cost / 5.0;
    printf("Log: For %d number of random samples, the cost is %f\n", i, temp_cost);
    if(temp_cost < min)
    {
      min = temp_cost;
      min_index = i;
    }
  }
  printf("\nMinimum cost is reached by using %d number of samples!\n\n",min_index);

  printf("Exiting...\n");
  


}
