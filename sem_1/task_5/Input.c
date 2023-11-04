#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ann.h"
int InputArray1(const char *sf, int **m, int *n)
{
 int i=0; FILE *f;
 f=fopen(sf,"r");
 if(f!=NULL)
 {
  if(fscanf(f,"%d",n)!=1){fclose(f);return -2;}
  *m=(int*)malloc((*n)*sizeof((*m)[0])+1);
  if(*m==NULL){fclose(f); return -3;}
  for(i=0;i<*n;i++) if(fscanf(f,"%d",(*m)+i)!=1){free(*m);*m=NULL;fclose(f);return -4;}
  fclose(f);
 }
 else return -1;
 return 0;
}