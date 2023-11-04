#pragma once

void PrintList(Slist*l);
char *wfgets(char **str, size_t *l, FILE *f); 
void ReadList(Slist ***l, const char *sf, size_t **size);   
void AllocateMemory(const char *sf,Slist ***l,size_t **size,size_t *m);
int Sum( Slist *l,size_t n);
int FindString(Slist **l, size_t *size,size_t *m,size_t *str);


