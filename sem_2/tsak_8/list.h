#pragma once
typedef struct SItem_
{
 int v;
 struct SItem_ *next, *prev;
}SItem;
typedef struct Slist_
{
 SItem *cur,*last,*first;
}Slist2;


//----------------------
Slist2 *Create(void);
int IsEmpty(Slist2 *l);
void Delete(Slist2 **l);
int DeleteCur(Slist2 *l);
void GoToFirst(Slist2 *l);
void GoToLast(Slist2 *l);
int GoToNext(Slist2 *l);
int GetV(Slist2 *l, int *v);
void InsertAfter(Slist2 *l, int v);



