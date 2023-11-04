#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ann.h"

int upr(int* m, int n)
{
 for(int i=1;i<n;++i){
 if(m[i]!=m[i-1]){
  if (m[i]>m[i-1]){
   for(int j=i;j<n;++j)
    if (m[i]<m[i-1])
     return 0;
   return 1;
  }
  else
  {
   for(int j=i;j<n;++j)
   if (m[i]>m[i-1])
     return 0;
   return 1;
  }
 }
 }
return 1;
}
