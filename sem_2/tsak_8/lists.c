#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "fun.h"

Slist2 *Create(void){Slist2  *l; l=(Slist2*)malloc(sizeof(Slist2));l->cur=l->last=l->first=NULL; return l;}
int IsEmpty(Slist2 *l){return l->cur==NULL;}
void Delete(Slist2 **l){GoToFirst(*l); while(!IsEmpty(*l))DeleteCur(*l); if(*l){free(*l);}l=NULL;}
int DeleteCur(Slist2 *l)
{SItem *cur;
 if(IsEmpty(l))return -1;
 cur=l->cur;
 if(cur->prev!=NULL){cur->prev->next=cur->next; l->cur=cur->prev;} else{l->first=cur->next;l->cur=cur->next;}
 if(cur->next!=NULL){cur->next->prev=cur->prev; l->cur=cur->next;} else{l->last=cur->prev;l->cur=cur->prev;}
 free(cur);
return 0;
}
void GoToFirst(Slist2 *l){l->cur=l->first;}
void GoToLast(Slist2 *l){l->cur=l->last;}
int GoToNext(Slist2 *l){if(l->cur==NULL||l->cur->next==NULL)return -1; l->cur=l->cur->next; return 0;}
int GetV(Slist2 *l, int *v){if(IsEmpty(l))return -1;*v=l->cur->v;return 0;}
void InsertAfter(Slist2 *l, int v)
{SItem *i;
 i=(SItem*)malloc(sizeof(SItem)); i->v=v; i->next=i->prev=NULL;
 if(IsEmpty(l))l->cur=l->first=l->last=i;
 else{
  i->prev=l->cur; i->next=l->cur->next;
  l->cur->next=i;
  if(i->next!=NULL)i->next->prev=i;else l->last=i;
 }
}
