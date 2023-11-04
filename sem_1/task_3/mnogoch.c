#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mnogoch.h"

int mnogoch(const char *fnam, int *x, int *x_der, int *x_sum)
{int kf=0,sum_kf=0; FILE*f;
 f=fopen(fnam,"r");
 if (f==NULL)
  return -1;
 while (fscanf(f,"%d",&kf)==1)
 {
  *x_sum=kf+(*x_sum * *x);
  

  *x_der=*x_der**x + sum_kf;
  sum_kf=kf+(sum_kf * *x);
  }  
 
 fclose(f);
 return 0;
}