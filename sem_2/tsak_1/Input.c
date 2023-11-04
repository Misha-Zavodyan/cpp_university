#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"fun.h"
int Input_array(const char *fn,int ***a,int *m, int *n)
{ int j,err=0,i,r;
  FILE*f;
  f=fopen(fn,"r");             

  if(f!=NULL)
   {   
    if(fscanf(f,"%d %d ",m,n)!=2){fclose(f);err=-2;}
    else
    {
    *a=(int**)malloc((*m+1)*sizeof(int*)+(*n*sizeof(int*)*(*m+1)));
    (*a)[0]=(int*)(*a+*m+1);
    for(r=1;r<*m;r++){(*a)[r]=(*a)[r-1]+*n;}
     
    if((*a)==NULL) {err=-3;fclose(f);}
    else
     {

      for(i=0;i<*m;i++)
      {                    
       { 
        for(j=0;j<*n;j++)               
        if(fscanf(f,"%d",((*a)[i])+j)!=1)
        {err=-4;goto lc;}
       }
      }
     }
    }                  
   }
  else{err=-1;}
 
 lc:; 
 if(f!=NULL)
  fclose(f);        
 return err;
}