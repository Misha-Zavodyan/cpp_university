#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cmnoh.h"

int main(void)
{int len,err;
 len=0;
 
 err=cmnoh("t.txt", &len);
 if(err==0)
  printf("Otvet: %d",len);
 else if(err==-1)
  printf("No file\n");

 return 0;
}