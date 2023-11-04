#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "fun.h"

int fun(int **a, int *m, int n)
{ int i,j,maxim=0,maxim_count=0,maxim_i=0,maxim_i_old=-1;
 if((n==0)||(*m==0))
  return 0;
 else
  maxim=a[0][0];
 for(i=0;i<n;i++)
 {
  for(maxim=a[i][0],maxim_i_old=maxim_i,maxim_i=0,maxim_count=0,j=0;j<*m;j++)
  {
   if(a[i][j]>maxim)
   {
    maxim=a[i][j];
    maxim_i=j;
    maxim_count=1;
   } else if(a[i][j]==maxim)
    maxim_count+=1; 
  }
  if((maxim_count>1)||((i>0)&&(maxim_i!=maxim_i_old)))
   return 0; 
 }

 *m=(*m)-1;
 for(i=0;i<n;i++)
  memmove(a[i]+maxim_i,a[i]+maxim_i+1,((*m)-maxim_i)*sizeof(a[0][0]));
 return 0;
}