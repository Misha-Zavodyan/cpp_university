#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ann.h"

int fun(int* m, int n)
{int j, b;
 if(n==0)
  return -1;
 for(int i=0;i<n;++i)
 {
  if(m[i]>=0)
  {  
   j=i;
   while(m[j-1]<=0){
    b=m[j];
    m[j]=m[j-1];
    m[j-1]=b;
    --j;
   }
  }   
 }

return 0;
}