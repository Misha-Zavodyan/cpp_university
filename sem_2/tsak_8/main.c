#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "fun.h"

int main(void)
{Slist2 **l=NULL;size_t m,*size,i,col; int err=0;
 AllocateMemory("data.dat",&l,&size,&m);
 if(m!=0){ 
  for(i=0;i<m;i++) l[i]=Create();               
  ReadList(&l,"data.dat", &size);        
  if(FindColls(l,size,m,&col)==1) DelCol(l,size,m,col);
  for(i=0;i<m;i++) PrintList(l[i]);
  for(i=0;i<m;i++) Delete((&l)[i]);
  free(size);free(l);
 }
 else err=-1;
return err; 
}       