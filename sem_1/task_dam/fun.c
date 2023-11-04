#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ann.h"

int fun(const char *fnam,int *mm,int*n)
{int x,maxim,k,N;
 if(fscanf(f,"%d",&N)!=1)
  return -1;
 col=1;
 k=1;
 while (fscanf(f,"%d",&x)==1)
 {
  k++;
  if(x>maxim)
   {
    col=0;
    maxim=x;  
   }
  }   
 }
 if(k>N){
  *n=k;
 }else{
  *n=N;
 }
 *mm=maxim;
return 0;
}