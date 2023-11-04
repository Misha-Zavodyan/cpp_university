#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ann.h"

int fun(int* m, int n,int* len)
{int mini,k=0,flag=1;
 if(n==0)
  return -1;
 mini=m[0];
 for(int i=1;i<n;++i)
  if(m[i]<mini)
   mini=m[i];

 for(int i=1;i<n;++i)
 {
  if(m[i-1]>m[i])
   flag=1; 
  if(flag==1){
   if(m[i-1]==m[i])
    k++;
   if(m[i-1]<m[i]){
    flag=0;
   if(k>0){
     for(int j=i;j<n;j++)
      m[j-k]=m[j]; 
    
    
    n=n-k;
    i=i-k;
    k=0;}
    m[i-1]=mini;
      
   }
  } 
 }
 

 if(flag==1){
    n=n-k;
    m[n-1]=mini; 
    k=0; 
  }


   
*len=n;

return 0;
}