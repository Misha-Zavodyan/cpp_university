#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ann.h"
int InputArray1(const char *sf,struct otr **m, int *n)
{
 int i=0,x=0,y=0; FILE *f;
 f=fopen(sf,"r");
printf("+\n");
 if(f!=NULL)
 {printf("-\n");
  if(fscanf(f,"%d",n)!=1){fclose(f);return -2;}
  
  printf("%d\n",*n);

  *m=(struct otr *)malloc( (*n)*sizeof*(m[0]) +1);
  
  //**(m)->a=(int**)malloc( (*n)*sizeof(int));
  //m[i]->b=(int*)malloc( (*n)*sizeof(int));
  
   
  printf("- -\n");
  if(*m==NULL){fclose(f); return -3;}
  printf("!\n");
  for(i=0;i<*n;i++){ 
   if(fscanf(f,"%d %d",&x,&y)!=2){
     printf("?\n");free(*m);*m=NULL;fclose(f);return -4;}
   else{
   //m[i]={x,y};
   //printf("++++\n");
   (*(m)[i]).a=x;
   (*(m)[i]).b=y;
  // m[i]->b=y;
   printf("%d %d %d\n",i,(*(m)[i]).a,(*(m)[i]).b);
   }
  }
printf("&\n");
  fclose(f);
 }
 else return -1;
 return 0;
}