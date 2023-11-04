#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ann.h"
int main(void)
{
 int err,*m=NULL,n;
 err=InputArray1("t.txt", &m, &n);
 if(err!=0)
 {
  printf("Can't input array\n");
  err=-2;
 }
 else
 {
  err=fun(m,n);
  if(err==-1)
   printf("0 elemen\n");
  else if(err!=0)
   printf("Can't solve problem\n");
  else 
  {
   printf("\n");
   for(int i=0;i<n;++i)
     printf("%d; ",m[i]);
  }
   printf("\n");
  free(m); 
  m=NULL;
 }
return 0;
}