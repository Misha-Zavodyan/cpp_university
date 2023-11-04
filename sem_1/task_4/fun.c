#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ann.h"

int fun(int* m, int n)
{int b=0;
 if(n==0)
  return -1;
 for(int i=0;i<(n/2);++i)
 {
  b=m[i];
  m[i]=m[n-i-1];
  m[n-i-1]=b;   
 }
return 0;
}