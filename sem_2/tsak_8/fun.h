#pragma once

void PrintList(Slist2*l);
char *wfgets(char **str, size_t *l, FILE *f); 
void ReadList(Slist2 ***l, const char *sf, size_t **size);   
void AllocateMemory(const char *sf,Slist2 ***l,size_t **size,size_t *m);
int CheckIsAver(size_t k, Slist2 *l,size_t n);
int FindColls(Slist2 **l, size_t *size,size_t m,size_t *col);
void DelCol(Slist2 **l, size_t *size,size_t m,size_t col);

