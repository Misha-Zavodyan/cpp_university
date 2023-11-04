#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h> 
#include "fun.h"

int Compare(int *v, size_t n,size_t num)
{size_t i,sum=0; int res;
 for(i=0;i<num;i++) sum+=v[i];
 for(i=num+1;i<n;i++) sum+=v[i];
 if(v[num]*(n-1)==sum) {res=0;}//printf("1");}
 else res=-1;
 return res;
}


void FindAverage(int **v, size_t m, size_t *column,size_t *n)
{size_t maxn=0,i,j; int check=0,a=0;
 for(i=0;i<m;i++) if(maxn<n[i]) maxn=n[i];
// for(i=0;i<maxn;i++,a++); 
 //printf("%d\n",a); a=0; 

 for(j=0;j<maxn;j++)
 {
  for(i=0;i<m;i++) 
  {
   if(n[i]-1<j){check=0;}
   else if(Compare(v[i],n[i],j)!=-1){check=0;}
   else{check=1;break;}
  }                              
  if(check==0){*column=j;a=0;break;}
  else a=1; 
  check=0;
 }
 if(a!=0) *column=-1;
//printf("%d",a);

}

