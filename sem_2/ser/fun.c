#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "fun.h"

int FindString(Slist **l, size_t *size,size_t *m,size_t *str)
{
 size_t i,j,sum=0;
 int v=0;
 *str=-1;


  for(sum=0,v=0,j=0;j<*m;j++)
  {
   GoToFirst(l[j]);  
   for(i=0;i<size[j];i++){GetV(l[j],&v);sum=sum+v;if(i!=size[j]-1) GoToNext(l[j]) ;}
   
   GoToFirst(l[j]);  
   for(i=0;i<size[j];i++){
    GetV(l[j],&v);
     if((size[j])*v==sum){
      *str=j;
      goto gl;
     } 
    if(i!=size[j]-1) GoToNext(l[j]);} 
  sum=0;    
  } 
  
 j=-1;
 if(*str==j)return -1;
  else
   gl: 
   return 0;
}



