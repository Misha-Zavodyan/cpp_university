#pragma once
typedef struct SItem_
{
 int v;
 struct SItem_ *next, *prev;
}SItem;

typedef struct Slist_
{
 SItem *cur,*last,*first;
}Slist;


Slist *Create(void);
int IsEmpty(Slist *l);
int Delete(Slist **l);
int DeleteCur(Slist *l);
void GoToFirst(Slist *l);
void GoToLast(Slist *l);
int GoToNext(Slist *l);
int GetV(Slist *l, int *v);
void InsertAfter(Slist *l, int v);



