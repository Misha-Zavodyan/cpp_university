#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "fun.h"

char *wfgets(char **str, size_t *l, FILE *f)
{char s[256];
 if(fgets(*str,*l,f)==NULL) return NULL;
 while(strlen(*str)==(*l)-1&&(*str)[(*l)-2]!='\n') if(fgets(s,sizeof(s),f)!=NULL)
 {*str=(char*)realloc(*str,(*l)+sizeof(s)-1); strcat(*str,s);(*l)=(*l)+sizeof(s)-1;}
 else break;
 return *str;
}
//=========================                                                                                                      
void AllocateMemory(const char *sf,Slist2 ***l,size_t **size,size_t *m)
{FILE  *f; char *str;size_t k=10;
 str=(char*)malloc(k); 
 f=fopen(sf,"r"); 
 if(f){
  for(*m=0; wfgets(&str, &k, f)!=NULL; (*m)++);
  fclose(f);
  (*size)=(size_t*)malloc((*m)*sizeof(size_t)); 
  (*l)=(Slist2**)malloc((*m)*sizeof(Slist2));  
 }else *m=0;   
}
//==============================
void ReadList(Slist2 ***l, const char *sf, size_t **size)
{int v,sz; FILE  *f; char *str, *s;size_t k=10,i;
 str=(char*)malloc(k); 
 f=fopen(sf,"r");
 if(f){                                                                                               
  for(i=0; wfgets(&str, &k, f)!=NULL; i++) for(s=str,(*size)[i]=0;sscanf(s,"%d%n",&v,&sz)==1;s+=sz,(*size)[i]++) {GoToLast((*l)[i]);InsertAfter((*l)[i],v);}    
 }
 fclose(f);      
}
