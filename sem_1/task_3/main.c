#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mnogoch.h"

int main(void)
{int x=0,x_sum=0,x_der=0,err;
 
 printf("Enter your X: \n");
 scanf("%d",&x);
 
 err=mnogoch("t.txt", &x, &x_der, &x_sum);
 if(err==0)
  printf("Ansver: x=%d, polinomial in x = %d, derivative in X = %d \n",x,x_sum,x_der);
 else if(err==-1)
  printf("No file\n");

 return 0;
}