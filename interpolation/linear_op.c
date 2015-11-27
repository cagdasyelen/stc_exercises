#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern void dgesv( int* n, int* nrhs, double* a, int* lda, int* ipiv, double* b, int* ldb, int* info );

extern void dgemm(char* transa, char* transb, int* m, int* n, int* k, double* alpha, double* a, int* lda, double* b, int* ldb, double* beta, double* c, int* ldc );

extern void dgemv(char* trans, int* m, int* n, double* alpha, double* a, int* lda, double* x, int* incx, double* beta, double*y, int* incy);

int main()
{
  int n=8, m=8, k=8, nhrs=8, lda=8, ldb=8, ldc=8, info;
  char *transa = "N";
  char *transb = "N";
  double alpha = 1.0, beta=0.0;
  int ipiv[8];
  double x[8];
  double x7[8];
  double B[64];
  double B2[64];
  double I1[64];
  double I2[64];
  int i,j;
  int incx = 1;
  int incy = 1;



  //-------Part I------------------------------------------------------------------
  printf("---------------------------PART I-------------------------  \n\n");


  for(i = 0 ; i < 8 ; i++)
  {
    x[i] = 0.0 + 1.0*(i/7.0);
    x7[i] = pow(x[i],7);
  }


  for(i = 0 ; i < 8 ; i++)
  {
    for(j = 0 ; j < 8 ; j++)
    {
      B[8*i + j] = pow(x[i], j);
      B2[8*i + j]= pow(x[i], j);
      if(i==j)
      {
        I1[8*i + j] = 1.0;
        I2[8*i + j] =1.0;
      }
      else
      {
        I1[8*i + j] = 0.0;
        I2[8*i + j] = 0.0;
      }
    }
  }

  printf("B: \n");

  print_matrix(B2);

  dgesv(&n, &nhrs, B2, &lda, ipiv, I1, &ldb, &info );

  if(info !=0)
  {
    printf("U(%i, %i) = 0 & B is singular\n", info, info);
    printf("Error!\n");
    return -1;
  }

  printf("\nInverse of B: \n");

  print_matrix(I1);

  dgemm(transa, transb, &m, &n, &k, &alpha, I1, &lda, B, &ldb, &beta, I2, &ldc );

  printf("\n B * (Inverse of B) : \n");

  print_matrix(I2);
  //-------Part II------------------------------------------------------------------

  printf("---------------------------PART II-------------------------  \n\n");

  double w1[8] = {0};
  double b1[8];
  double nValue1 = 0;
  double aValue1;
  for(i = 0 ; i < 8 ; i ++)
  {
    b1[i] = pow(0.5,i);
  } 

  dgemv(transa, &m, &n, &alpha, I1, &lda, b1, &incx, &beta, w1, &incy );

  printf("w:\n");
  print_vector(w1);

  for (i = 0 ; i <8 ; i++)
  {
    nValue1 = nValue1 + x7[i] * w1[i]; 
  }
  aValue1 = pow(0.5, 7);
  printf("\nNumerical Result : %.12e\n", nValue1);
  printf("Analytical Result: %.12e\n", aValue1);
  printf("Absolute Err : %.12e\n\n", fabs(nValue1-aValue1));


  //-------Part III------------------------------------------------------------------

  printf("---------------------------PART III-------------------------  \n\n");

  double w2[8] = {0};
  double b2[8] ;
  double nValue2 = 0;
  double aValue2;
  
  b2[0] = 0;
  for(i = 1 ; i < 8 ; i ++)
  {
    b2[i] =(double) i* pow(0.5,i-1);
  } 

  dgemv(transa, &m, &n, &alpha, I1, &lda, b2, &incx, &beta, w2, &incy );


  printf("w:\n");
  print_vector(w2);

  for (i = 0 ; i <8 ; i++)
  {
    nValue2 = nValue2 + x7[i] * w2[i]; 
  }
  aValue2 =7.0* pow(0.5, 6);
  printf("\nNumerical Result : %.12e\n", nValue2);
  printf("Analytical Result: %.12e\n", aValue2);
  printf("Absolute Err : %.12e\n\n", fabs(nValue2-aValue2));


  //-------Part IV------------------------------------------------------------------

  printf("---------------------------PART IV-------------------------  \n\n");

  double w3[8] = {0};
  double b3[8];
  double nValue3 = 0;
  double aValue3;

  b3[0] = 0;
  b3[1] = 0;
  for(i = 2 ; i < 8 ; i ++)
  {
    b3[i] =(i-1)*i*pow(0.5,i-2);
  } 

  dgemv(transa, &m, &n, &alpha, I1, &lda, b3, &incx, &beta, w3, &incy );


  printf("w:\n");
  print_vector(w3);

  for (i = 0 ; i <8 ; i++)
  {
    nValue3 = nValue3 + x7[i] * w3[i]; 
  }
  aValue3 =42*pow(0.5, 5);
  printf("\nNumerical Result : %.12e\n", nValue3);
  printf("Analytical Result: %.12e\n", aValue3);
  printf("Absolute Err : %.12e\n\n", fabs(nValue3-aValue3));


  //-------Part V------------------------------------------------------------------

  printf("---------------------------PART V-------------------------  \n\n");

  double w4[8] = {0};
  double b4[8];
  double nValue4 = 0;
  double aValue4;

  for(i = 0 ; i < 8 ; i ++)
  {
    b4[i] =pow(0.5,i+1)/(i+1);
  } 

  dgemv(transa, &m, &n, &alpha, I1, &lda, b4, &incx, &beta, w4, &incy );


  printf("w:\n");
  print_vector(w4);

  for (i = 0 ; i <8 ; i++)
  {
    nValue4 = nValue4 + x7[i] * w4[i]; 
  }
  aValue4 =pow(0.5, 8)/8.0;
  printf("\nNumerical Result : %.12e\n", nValue4);
  printf("Analytical Result: %.12e\n", aValue4);
  printf("Absolute Err : %.12f\e\n", fabs(nValue4-aValue4));

  return -1;
}
