#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "zachet.h"

int InputArray(const char *FILENAME,int **arr, int *number, int *N, int *M )
 {
  int max=10, x, i, off; FILE *f;
  f=fopen(FILENAME, "r");
  if(f==NULL) return -1;
  if(fscanf(f, "%d", M)!=1) {fclose(f); return -1;}
  if(fscanf(f, "%d", N)!=1) {fclose(f);  return -1;}
  *arr=(int*)malloc(max*sizeof((*arr)[0])+1);
  *number=0;
  for(*number=0; fscanf(f, "%d", (*arr)+(*number))==1; ++(*number))
   {
     if(*number==max-1){*arr=(int*)realloc(*arr,(max*=2)*sizeof((*arr)[0])+1);}
   }
  x=0;
  off=0;
  if((*N)>(*arr[*number])) {x=(*arr[*number]);}
  else {x=*N;}
  for(i=0; i<x; ++i){arr[i-off]=arr[i]; ++off;}
  *number=*number - x; 
  fclose(f);
  return 0;
 }


int vukiduvanie(int **arr, int *size, int M)
 {
  int off=0, i;
  for(i=0; i<*size; ++i)
   {
    if(*arr[i]==M){ arr[i-off]=arr[i]; ++off;}
   }
  *size-=off;
  return 0;
 }