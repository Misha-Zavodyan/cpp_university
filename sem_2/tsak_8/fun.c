#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "fun.h"
int CheckIsAver(size_t k, Slist2 *l,size_t n)
{size_t i;int t=0,x=0,v=0,N,res;
 GoToFirst(l);  
 if(k!=1) for(i=1;i<k;i++){GetV(l,&x);t+=x; l->cur=l->cur->next;}
 GetV(l,&v);
 if(k!=n) for(i=k;i<n;i++){l->cur=l->cur->next;GetV(l,&x);t+=x;}
 N=(int)n;
 if(v*(N-1)==t) res=1;
 else res=0;
return res;   
}

int FindColls(Slist2 **l, size_t *size,size_t m,size_t *col)
{size_t i,j,MAXsize=0; int res;

 for(i=0;i<m;i++) if(size[i]>MAXsize) MAXsize=size[i]; 
 if(MAXsize!=1)
  for(i=0;i<MAXsize;i++){
   for(j=0;j<m;j++){
    if(size[j]<i+1)res=1; 
    else{
     if(CheckIsAver(i+1,l[j],size[j])==1) res=1;
     else{res=0;break;}
    }
   }
   if(res==1){ *col=i;break;}
  } 
 else res=0;
return res;   
}

void DelCol(Slist2 **l, size_t *size,size_t m,size_t col)
{size_t i,j;
 for(i=0;i<m;i++)
  if(size[i]>=col){
   GoToFirst(l[i]);
   for(j=0;j<col;j++)l[i]->cur=l[i]->cur->next;
   DeleteCur(l[i]);
  }
}
