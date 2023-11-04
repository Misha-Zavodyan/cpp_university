#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"
#include "fun.h"


int fun(size_t *n1,struct Student **s1)
{
 size_t i,j;
 char nname[512];
 int swp;
 double sswp;
  
 for(i=0;i<*n1;i++)
 {
  for(j=i+1;j<*n1;j++)
  {
   if( ((*s1)[i].group==(*s1)[j].group) && (strcmp((*s1)[i].name,(*s1)[j].name ))==0)
   {
     
    (*s1)[i].group=(*s1)[*n1-1].group;
    (*s1)[i].rating=(*s1)[*n1-1].rating; 
    strcpy( ((*s1)[i].name),(*s1)[*n1-1].name );
    *n1=*n1-1;
    i=0;  
   } 
  }
 }
for(i=0;i<*n1;i++)
 {
  for(j=i+1;j<*n1;j++)
  {

   if((((*s1)[i].group)==((*s1)[j].group)) && (((*s1)[i].name[0])<((*s1)[j].name[0] )) ){
    swp=(*s1)[i].group;
    (*s1)[i].group=(*s1)[j].group;
    (*s1)[j].group=swp;

    sswp=(*s1)[i].rating;
    (*s1)[i].rating=(*s1)[j].rating;
    (*s1)[j].rating=sswp; 

    strcpy( nname,(*s1)[i].name );
    strcpy( ((*s1)[i].name),(*s1)[j].name );
    strcpy( ((*s1)[j].name),nname );

   } 
   else if(((*s1)[i].group)>((*s1)[j].group) ){
    swp=(*s1)[i].group;
    (*s1)[i].group=(*s1)[j].group;
    (*s1)[j].group=swp;

    sswp=(*s1)[i].rating;
    (*s1)[i].rating=(*s1)[j].rating;
    (*s1)[j].rating=sswp; 

    strcpy( nname,(*s1)[i].name );
    strcpy( ((*s1)[i].name),(*s1)[j].name );
    strcpy( ((*s1)[j].name),nname );

   }}} 
return 0; 
}
