#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"
#include "fun.h"
                                                                
int Input(const char *sff,struct Student **s, size_t *n)                                     
{ FILE *f;
  char str[1024],check[512],*name,*sf;
  int err=0,del,group;
  double rating;
  size_t i=0; 

 f=fopen(sff,"r"); 
 if(f!=NULL)
 {                                   
  *s=(struct Student*)malloc((*n)*sizeof(**s));

  for(i=0;i<*n;i++)
  {            
    if((fgets(str,sizeof(str),f)!=NULL)&&(sscanf(str,"%lg %d %s",&rating, &group,check)==3))
    {  
     if((sf=strchr(str,'\n'))!=NULL) *sf='\0';
     del=group%10;       
     name=strrchr(str,del+'0');*name=' ';   
     (*s)[i].rating=rating;
     (*s)[i].group=group; 
     strcpy(((*s)[i].name),name);                                           
    }
    else {err=-2; break;}
  }

 }
 else err=-1;
 if(err==0) *n=i;                                                                                                       
 fclose(f); 

return err;        
}

  