#include <stdio.h>
#include <math.h>
#include "parameters.h"

double midp(double xi, double h)
{
  return pow( (xi+h*0.5e0),(double)7 );
}

double trap(double xi, double h)
{
  return pow(  xi,   (double)7 )+  pow( (xi+h),(double)7 );
}

double simp(double xi,double  h)
{
  return pow( (xi-h),(double)7)+4*pow(xi, (double)7 )+ pow((xi+h),
            (double)7 );
}
