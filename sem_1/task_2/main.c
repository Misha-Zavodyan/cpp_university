#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "minpos.h"

int main(void)
{int len=0,err;
 
 err=minpos("t.txt", &len);
 if(err==0)
  printf("Ansver: len=%d \n",len);
 else if(err==-1)
  printf("No file\n");

 return 0;
}