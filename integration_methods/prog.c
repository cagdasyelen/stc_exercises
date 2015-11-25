#include <stdio.h>
#include <math.h>
#include <time.h>
#include "parameters.h"


int main()
{
  double x_start = 0;
  double x_end = 1.000000;
  int N[7] = {11, 101, 1001, 10001, 100001, 1000001, 10000001};
  int M = 0;
  double midp_i=0, trap_i=0, simp_i=0 ;
  double midp_err, trap_err, simp_err;
  double h;
  int i,j;
  double xi;
  time_t start, stop ;
  double midp_time, trap_time, simp_time;

  printf("M - midp_result  -  trap_result  -  simp_result  -  midp_err  -  trap_err  -  simp_err  -  midp_time  -  trap_time  -  simp_time\n");

  for(i=0 ; i< 7 ; i++)
  {
    M = N[i];
    h = (x_end - x_start)/(M-1.000000000000);
    midp_i = 0 , midp_err = 0;
    trap_i = 0 , trap_err = 0;
    simp_i = 0 , simp_err = 0;
    
    start = clock();
    for(j=0 ; j<M-1 ; j++ )
    {
      xi = x_start + h*j;
      midp_i = midp_i + h*midp(xi, h);
    }
    stop = clock();
    midp_time = stop - start;
    
    start = clock();
    for(j=0 ; j<M-1 ; j++)
    {
      xi = x_start + h*j;
      trap_i = trap_i + (h/2.0)*trap(xi,h);
    }
    stop = clock();
    trap_time = stop - start;

    start = clock();
    for(j=1 ; j< M-1 ; j++)
    {
      xi = x_start +h*j;
      simp_i = simp_i + (h/6)*simp(xi, h);
    }
    stop = clock();
    simp_time = stop - start;

    midp_err = midp_i - 0.125000000000;
    trap_err = trap_i - 0.125000000000;
    simp_err = simp_i - 0.125000000000;

    printf("%d, %.12lf, %.12lf,  %.12lf, %.12lf, %.12lf, %.12lf, %.6lf, %.6lf, %.6lf\n", M, midp_i, trap_i, simp_i, midp_err, trap_err, simp_err, midp_time,trap_time,simp_time);
    
  }

  return -1;
}
