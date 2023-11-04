#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "fun.h"  
 
int main(void)
{ 
 int err=0,**a=NULL,m,n;
 err=Input_array("data.dat", &a, &m, &n);
 if(err!=0){printf("Can't input array\n");return -2;}
 else
 {
  err=fun(a,&n,m);
  err=Output_array(a,m,n);
  if (err!=0) 
   printf("(((((/n"); 

  free(a); a=NULL;
 }
 
return 0;
}