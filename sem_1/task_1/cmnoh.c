#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cmnoh.h"

int cmnoh(const char *fnam, int *len)
{int x;int m[6]={0}; FILE*f;
 f=fopen(fnam,"r");
 *len=0;
 if (f==0)
  return -1;
 while (fscanf(f,"%d",&x)==1)
  if (x>=1 && x<=5)
   m[x]=1; 
   
 for(int i=0;i<=5;++i)
  *len+=m[i];  
 
 fclose(f);
 return 0;
}