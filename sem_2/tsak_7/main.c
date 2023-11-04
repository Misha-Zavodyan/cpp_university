#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"
#include "fun.h"

int main(void)
{int err=0;
 size_t n1=6,i;
 struct Student *s1=NULL ;

 err=Input("t1.txt",&s1,&n1);
 if(err==0)
 {   
   fun(&n1,&s1);
   for(i=0;i<n1;i++) printf("%d n %lg n %s\n",s1[i].group,s1[i].rating,s1[i].name);
   printf("\n");
   free(s1);
  }
 else printf("error");

return err;
}