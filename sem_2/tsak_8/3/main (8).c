#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>
#include <ctype.h> 
#include "fun.h"
            
int main(void)
{size_t i,m,column,k=-1,*n=NULL; int **v, err=0; 
 if(InputArray("data.dat",&v,&m,&n)!=0){printf("err 1\n"); err=-1;}
 FindAverage(v,m,&column,n);
 if(column!=k) Delete(&v,&n,column,m);
 Print("resa.dat",v,n,m);

 free(n); n=NULL;
 for(i=0;i<m;i++)free(v[i]);
 free(v); v=NULL;
return err;  
}
