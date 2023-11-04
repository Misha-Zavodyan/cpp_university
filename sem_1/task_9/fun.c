#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ann.h"

int fun(int* m, int n,int* len)
{int j=0,i=0,x=0,y=0;
  if(n==0)
   return -1;
 
 for(i=4;i<n;i+=2){
  x=m[i];
  y=m[i+1];

  j=i-2;
  
  while((x<m[j])){
   m[j+2]=m[j]; 
   m[j+3]=m[j+1];
   j-=2;
   if(j<=0)
    break;
  } m[j+2]=x; m[j+3]=y;
 }
 
 
 for(i=2;i<n;i+=2){
 // printf("%d: %d %d, %d %d \n",i,m[0],m[1],m[i],m[i+1]);
  if(m[i]<=m[0]){
   if(m[0]<m[i+1])
    m[0]=m[i+1];
  }
  else {
   *len=0;
   break;
  }
  if(m[0]>=m[1]){
   *len=1;
   break;
  }
 }
 if((*len==0)||(m[0]<m[1]))
   *len=0;

 return 0;
}