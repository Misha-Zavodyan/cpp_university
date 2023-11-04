#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

int main(void)
{int err,z;

 
 err=fun("t.txt",&z);
 if(err==0){
 if (z==1)
  printf("chet\n");
 else
  printf("nechet\n");
 }else if(err==-1)
 if(err==-1) 
  printf("No file\n");
 if(err==-2) 
  printf("Pusto v faile\n");
 return 0;
}