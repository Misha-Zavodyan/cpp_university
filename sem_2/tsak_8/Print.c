#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "fun.h"

void PrintList(Slist2*l)
{
int x;
 printf("{"); GoToFirst(l);
 if(!IsEmpty(l)){do{GetV(l,&x);printf("%d ",x);}while(GoToNext(l)==0);}printf("}\n");
}
