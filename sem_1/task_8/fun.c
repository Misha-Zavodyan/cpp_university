#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ann.h"

int fun(int* m, int n)
{int x=0,j=0;
 if(n==0)
  return -1;
 
 for(int i=1;i<n;++i){
  x=m[i];
  j=i-1;
  for(int j=j+1;j>n;--j)
  while((x<m[j])){
   m[j+1]=m[j]; 
   j--;
   if(j<=-1)
    break;
  } m[j+1]=x;
 }           
   
  

return 0;
}