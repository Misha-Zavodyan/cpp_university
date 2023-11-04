#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main (void)
{
 int minimum, x, kol; 
 FILE*f;
 f=fopen("proga.txt","r");
 kol=-1;
 minimum=0;
 if(f==NULL) 
  {
   return -1;
   fclose(f);
  }
   else
   if (fscanf(f, "%d", &x)!=1)
   {fclose(f); printf("Pusto(("); return -2; }
   fscanf(f, "%d", &minimum);
   while (fscanf(f, "%d", &x)==1)//мы берём файл f и считываем из него по одному элементу , которые присваиваем переменной x
   {
    if(x<minimum)
    {
     minimum=x;    
     kol=0;
    } 
    if(minimum==x)
    kol=kol+1;  
   }
  printf("kolichestvo minimalnih chisel ravno %d",kol);
  fclose(f);
  return 0;//как только return встречается, программа завершается.
}