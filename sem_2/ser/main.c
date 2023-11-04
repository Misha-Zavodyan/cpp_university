#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "fun.h"

int main(void)
{
  Slist **l=NULL;
  size_t m,*size,i,str;
  int err=0;
  AllocateMemory("data.dat",&l,&size,&m);
  
  if(m!=0)
  { 
   for(i=0;i<m;i++) l[i]=Create();              
   ReadList(&l,"data.dat", &size);

   if(FindString(l,size,&m,&str)==0) 
   {  
   GoToFirst(l[str]);
   for(i=0;i<size[str];i++)
   {DeleteCur(l[str]);GoToNext(l[str]);}
   }

   for(i=0;(i<m);i++) if(i!=str)  PrintList(l[i]);
   for(i=0;(i<m);i++) if(i!=str)  Delete((&l)[i]);
   free(size);free(l);
 }
 else err=-1;
return err; 
}       