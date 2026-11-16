#include "str_io.h"

int solution_1(const char *fn1;const char *fn2;const char *s,int*r)
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
    fclose(fout);
    fclose(fin);
    return ERROR_MEMORY;
  }
  backsl=0;
  i=0;
  len=0;
  while(s[i]!='\0')
  {
    if (!backsl)
    {
      if(argv[3][i]=='\\')
      {
        backsl=1;
        len--;
      } 
      else if(argv[3][i]=='.')
      {
        s[len]=argv[3][i];
        bufs[len]='1';

      }
      else
      {
        bufs[len]='0';
        s[len]=argv[3][i]; 
      }
    } 
    else 
    {
      s[len]=argv[3][i];
      bufs[len]='0';
      backsl=0;
    }
    i++;
    len++;
    
  }

  fclose(fin);
  fclose(fout);
  free(bufs);
  return SUCCESS;
}