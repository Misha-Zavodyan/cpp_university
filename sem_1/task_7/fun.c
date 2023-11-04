#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fun.h"

int fun(const char *fnam,int*z)
{int x=0,c=0; FILE*f;
 f=fopen(fnam,"r");
 if (f==NULL)
  return -1;
 if(fscanf(f,"%d",&x)!=1){fclose(f);return -2;}
 for(int k=0;k<32; k++)
  if(x&(1<<k))
   c++;
   
 if((c%2)==0)
  *z=1;
 else
  *z=0;
 
 fclose(f);
 return 0;
}