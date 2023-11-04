#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>
#include <ctype.h> 
#include "fun.h"
                                                                                 
char *wfgets(char **str, size_t *l, FILE *f)
{char s[256];
 if(fgets(*str,*l,f)==NULL) return NULL;
 while(strlen(*str)==(*l)-1&&(*str)[(*l)-2]!='\n') if(fgets(s,sizeof(s),f)!=NULL)
 {*str=(char*)realloc(*str,(*l)+sizeof(s)-1); strcat(*str,s);(*l)=(*l)+sizeof(s)-1;}
 else break;
 return *str;
}

int InputArray(const char *sf, int ***arr , size_t *m, size_t **n)
{
 char *str, *s; FILE *f; size_t l=10, i, I; int sz, tmp, err=0;
 str=(char*)malloc(l);
 //free(str);
 f=fopen(sf, "r");
 if(f)
 {
  for(*m=0; wfgets(&str, &l, f)!=NULL; (*m)++);
  fclose(f);
 } else err=-1;
 (*arr)=(int**)malloc((*m)*sizeof(int*));
 *n=(size_t*)malloc((*m)*sizeof(size_t)); 
 f=fopen(sf, "r");
 if(f)
 {
  for(i=0; wfgets(&str, &l, f)!=NULL; i++)
  {
   for(I=0; I<2; I++)
   {
    for((*n)[i]=0, s=str; sscanf(s,"%d%n",(I==0?&tmp:(*arr)[i]+(*n)[i]),&sz)==1; s+=sz,(*n)[i]++);
    if(I==0) (*arr)[i]=((*n)[i]==0?NULL:(int*)malloc((*n)[i]*sizeof(int)));
   }
  }
  fclose(f);
  while((*m)>0 && (*n)[(*m)-1]==0)(*m)--;
  free(str);
 } 
 else
 {
  err=-1;
  free(str);
 }
return err;             
}
                                   /*
int InputArray(const char *sf,int ***v,size_t *m,size_t **n)
{char *str, *s; FILE *f; size_t l=10,i,I; int sz,tmp,err=0;
 str=(char*)malloc(l);
 f=fopen(sf,"r");
 if(f)
 {
 for(*m=0;wfgets(&str,&l,f)!=NULL;(*m)++);
 fclose(f);
 } else err=-1;
 (*v)=(int**)malloc((*m)*sizeof(int*));
 *n=(size_t*)malloc((*m)*sizeof(size_t));
 f=fopen(sf,"r");
 if(f)
 {
  for(i=0;wfgets(&str,&l,f)!=NULL;i++) 
   for(I=0;I<2;I++)
   {
    for((*n)[i]=0,s=str;sscanf(s,"%d%n",(I==0?&tmp:(*v)[i]+(*n)[i]),&sz)==1;s+=sz,(*n)[i]++);
    if(I==0) 
     (*v)[i]=((*n)[i]==0?NULL:(int*)malloc((*n)[i]*sizeof(int)));
   }
  fclose(f);
  while((*m)>0&&n[(*m)-1]==0)(*m)--;
  free(str);
 }
 else{ free(str); err=-1;} 
return err;                                                   
}
            




                                 */