#include <stdio.h>
#include<stdlib.h>

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

int main(void)
{
  int n;
  long result;
  n =40;
  result = fibo(n);
  printf("finonacci(%d) = %ld\n", n, result );

  return 0;
}
