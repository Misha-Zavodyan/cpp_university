#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ann.h"
int main(void)
{
 int err,n,i=0;struct otr *m=NULL;
printf("1\n"); 
 err=InputArray1("t.txt", &m, &n);
printf("Uraaa2\n");
 if(err!=0)
 {
  printf("Can't input array\n");
  //err=-2;
 }
 else
 {       
  //err=fun(m,n);
  err=0;
  if(err==-1)
   printf("0 elemen\n");
  if(err!=0)
   printf("Can't solve problem\n");
  if(err==0)
  {
   printf("J\n");
   for(i=0;i<n;++i)
    printf("%d %d \n",m[i].a,m[i].b);
  }
  printf("JJ\n");
   for(i=0;i<n;++i)
    printf("%d %d \n",m[i].a,m[i].b);
   

  free(m); 
  m=NULL;
 }
return 0;
}