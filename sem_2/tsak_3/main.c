#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>
#include <ctype.h> 
#include "fun.h"
            
int main(void)
{
 size_t i,m,*n=NULL; 
 int **a, err=0; 
 if(InputArray("data.dat",&a,&m,&n)!=0)
 {printf("error, invalid input"); err=-1;}

 if(err!=-1)
 {
 err=Fun(a,&m,n);
 if(err==-1) printf("there is no such number");
 Print("data.res",a,n,m);
 }
 free(n); n=NULL;
 for(i=0;i<m;i++)free(a[i]);
 free(a); a=NULL;
return err;  
}

