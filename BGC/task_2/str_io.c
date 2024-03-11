#include "str_io.h"

void solution_1(const char *fn1;const char *fn2;const char *s)
{
  FILE * fin;
  FILE * fout;
  int len,i,backsl;


  len=0;
  i=0;
  if (!(fin=fopen(fn1,"r")))
  {
    printf("Can't open %s! \n",name1);
    return ERROR_OPEN;
  }

  if (!(fout=fopen(fn2,"w")))
  {
    printf("Can't open %s! \n",name2);
    fclose(fin);
    return ERROR_OPEN;
  }

  while(s[i]!='\0')
  {
    if(s[i]!='\\')
    {
      len++;
    }
    i++;
  }

  bufs = (char*)malloc((len + 1)* sizeof(char));
  if (!bufs)
  {
    printf("not enough memory! \n");
    return ERROR_MEMORY;
  }

  s = (char*)malloc((len + 1)* sizeof(char));




}