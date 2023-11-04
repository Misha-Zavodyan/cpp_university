#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ann.h"
int InputArray1(int mm, int **m, int *n)
{
 int i=0;
  if(fscanf(f,"%d",n)!=1){return -2;}
  *m=(int*)malloc((*n)*sizeof((*m)[0])+1);
  if(*m==NULL){ return -3;}
  for(i=0;i<*n;i++) 
   m[i]=mm;
  return -1;
 return 0;
}