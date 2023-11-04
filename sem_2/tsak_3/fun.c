#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h> 
#include "fun.h"

int Fun(int **a, size_t *m, size_t *n)
{
 size_t i=0,j=0;
 int N=0;
 int err=0;
 size_t sum=0; 

 N=-1;



 for (i=0;i<*m;i++)    
 {   
  for (j=0;j<n[i];j++) {sum=sum+a[i][j];}
  
  for (j=0;j<n[i];j++)
  {
   if((n[i])*(a[i][j])==sum) {N=i;goto gg;}  
  }
 sum=0;
 }
 gg:;
   
  if(N!=(-1))
  {
   for(i=N;i<*m-1;i++)
    {n[i]=n[i+1]; a[i]=a[i+1];}
     *m=*m-1;
  }
  else err=-1;
  return err;
}