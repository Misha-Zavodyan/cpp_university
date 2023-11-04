#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>
#include <ctype.h>                                        
#include "fun.h"


int  iscorrect(char *w) 
{
 int err=0,s=0;
 for(;*w!='\0';w++) 
  {
   if(s==0)
    {  s=1; if (*w!='A') err=-1;}
   else
    {if ((*w<'A')||(*w>'Z')) err=-1;}
   
  } 
return err;
}