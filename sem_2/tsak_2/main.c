#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>
#include <ctype.h>                                        
#include "fun.h"

int main(void)
{int err; 
 char smin[512];
 err=search("t.txt",smin);
 if(err==0) 
  printf("%s",smin);
 else if(err==-2) 
  printf("net slowa"); 
 else 
  printf("error");
 return err;
}