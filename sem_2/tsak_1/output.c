#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include"fun.h"
int Output_array(int **a, int m, int n)
{
 int i=0,j=0,err=0;
 int *lmax,l;
 char s[100];
 FILE*f;
 lmax=(int*)malloc(n*sizeof(int)); for(i=0;i<n;i++)lmax[i]=1;

 for(i=0;i<m;i++)
 for(j=0;j<n;j++)
 {
  sprintf(s, "%d",a[i][j]);
  l=strlen(s);
  if(lmax[j]<l)lmax[j]=l;
 }

 f=fopen("data.res","w");
 if(f!=NULL)
 {

  for(i=0;i<m;i++)
  {
   for(j=0;j<n;j++)
   {
    fprintf(f,"%*d ",lmax[j],a[i][j]); 
   }
   fprintf(f,"\n"); 
  }

  fclose(f);
 }
 else(err=-1);
 free(lmax);
 return err;
}