#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ann.h"
int InputArray1(const char *sf,int **m,int *n)
{int nmax=2,err=0;FILE*f;
 f=fopen(sf,"r");
 if(f==NULL) err=-1;
 else
 {
   *n=0;
   *m=(int*)malloc(nmax*sizeof((*m)[0])+1);
   if(*m==NULL) {err=-2;}
  else
  {
   for(*n=0; (fscanf(f,"%d",(*m)+(*n))==1)&&(*m!=NULL);(*n)++) if(*n==nmax-1)
   {
    *m=(int*)realloc(*m,(nmax=nmax*2)*sizeof(*m[0]));
    if(*n>1)
    if((*n)%2==0){
     if(*m[(*n)-2]>*m[(*n)-1])
      return -10; 
    if(*m==NULL) err=-2;
   }} 
   fclose(f);
   err=0;
  }
 }
 if(*n%2==1)
  err=-11;
 return err;
}