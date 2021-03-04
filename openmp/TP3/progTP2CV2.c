#include <stdio.h>
#include<stdlib.h>
#include <omp.h>

#define NBTHREADS 4

long fibo(int n)
{
  long fnm1, fnm2;
  if ( n < 2 )
    return(n);
  else {
    fnm1 = fibo(n-1);
    fnm2 = fibo(n-2);
    return(fnm1 + fnm2);
  }
}

long fiboPar(int n)
{
  long fnm1, fnm2;
  if ( n < 2 )
    return(n);
  else {
    fnm1 = fiboPar(n-1);
    fnm2 = fiboPar(n-2);
    return(fnm1 + fnm2);
  }
}

int main(void)
{
  int n;
  long resultS, resultP;

  double start, end, timeS, timeP;
  n =40;

  start=omp_get_wtime();
  resultS = fibo(n);
  end=omp_get_wtime();
  timeS=(end-start);

  start=omp_get_wtime();
  resultP = fiboPar(n);
  end=omp_get_wtime();
  timeP=(end-start);

  printf("Version seq : finonacci(%d) = %ld\n", n, resultS);
  printf("Version par : finonacci(%d) = %ld\n", n, resultP);
  printf ("temps d'execution seq : %g \n",timeS);
  printf ("temps d'execution par : %g \n",timeP);
  printf ("A : %g \n",timeS/timeP);
  printf ("E : %g \n",timeS/(timeP*NBTHREADS));

  return 0;
}
