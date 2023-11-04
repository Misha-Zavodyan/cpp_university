#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>
#include <ctype.h> 
#include "fun.h"

void Print(const char *sf, int **a,size_t *n,size_t m)
{size_t i,j; FILE *f;
 f=fopen(sf,"w");
 for(i=0;i<m;i++,fprintf(f,"\n"))
 for(j=0;j<n[i];j++) fprintf(f,"%d ", a[i][j]);
 fclose(f);
}