#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>
#include <ctype.h>                                        
#include "fun.h"


int search(const char *SInputFile, char *smin)
{
 size_t lmin=512;
 char str[512], word[512],*s,*sb,*se;
 int err=0;
 FILE *f;
 smin[0]='0';

 f=fopen(SInputFile,"r");
 if(f!=NULL)
 {
  while(fgets(str,sizeof(str),f)!=NULL)
  { 
   if((s=strchr(str,'\n'))!=NULL) *s='\0';
   for(sb=str;;sb=se)
   {
    while(*sb==' '||*sb=='.'||*sb==',') sb++;
    if(*sb=='\0') break;
    for(se=sb+1;*se!='\0' && *se!=' ' && *se!=',' && *se!='.';se++);
    strncpy(word,sb,se-sb); word[se-sb]='\0';
    if ((strlen(word)<lmin)&&(iscorrect(word)==0))                    
    {
     lmin = strlen(word);
     strcpy(smin,word);
    }    
   }
  }
  fclose(f);
 }
 else err=-1;
 if(smin[0]=='0')
  err=-2;
 return err;
}