#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>
#include <ctype.h> 
#include "fun.h"

void Delete(int ***v, size_t **n,size_t column, size_t m)
{size_t i,j;
 for(i=0;i<m;i++)
 {
  if((*n)[i]-1>column) 
  {
   for(j=column;j<(*n)[i];j++) (*v)[i][j]=(*v)[i][j+1];
   
  }
  (*n)[i]--;  
 }          
}
