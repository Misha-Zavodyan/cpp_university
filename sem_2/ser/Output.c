#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "fun.h"

void PrintList(Slist*l)
{
 int v;
 GoToFirst(l);
 if(!IsEmpty(l))
  {
   do{GetV(l,&v);printf("%d ",v);} while(GoToNext(l)==0);
  }
 printf("\n");
}
