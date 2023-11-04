#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "zachet.h"

int main(void)
 {
  int err=0, *arr=NULL, number=0, M, N, i;
  err=InputArray("data.txt", &arr, &number, &N, &M);
    if(err==-1){printf("ERROR\n");}
    else if(err==0)
     {
       vukiduvanie(&arr, &number, M);
       for(i=0;i<number ;++i){printf("arr[%d]=%d\n", i, arr[i]);}
     }
  getchar();
  free(arr);
  arr=NULL;
  return err;
 }