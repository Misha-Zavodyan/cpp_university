#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "minpos.h"

int minpos(const char *fnam, int *len)
{int k=0,last=0,count,max_c=0,nepos,x; FILE*f;
 f=fopen(fnam,"r");
 if (f==NULL)
  return -1;
 while (fscanf(f,"%d",&x)==1)
 {
   k++;
   if(k==1){
    last=x-1;
    nepos=x-1;
   }
   if(x==last && x>=nepos)
    count+=1;
   else if(x>last){
    count=0;
    nepos=last;
   }
   else if(count>max_c){ 
    max_c=count;
    nepos=last;
   } 
  

  last=x; 
 }
 if(count>max_c) 
    max_c=count;  
 *len=max_c+1;
 fclose(f);
 return 0;
}