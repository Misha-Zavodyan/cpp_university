#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc,char *argv[])
{
  enum io_status
  {
    SUCCESS,
    ERROR_OPEN,
    ERROR_ARGUMENT,
    ERROR_FIRST_SIMBOL,
    ERROR_FIRST_BACKSLASH,
    ERROR_READ
  } io_stat;

  FILE* fin,*fout;
  int i,len,task,res;
  int backsl,flag;
  double t;
  char* s;
  char procs[100000];
  char* bufs;

  task=1;
  i=0;    
  len=0;
  t=clock();
  if (argc!=4)
  {
    t=(clock()-t)/CLOCKS_PER_SEC;
    printf ("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], task, res, t);
    return -1;
  }
  
  if (!(fin=fopen(argv[1],"r")))
  {
    t=(clock()-t)/CLOCKS_PER_SEC;
    printf ("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], task, res, t);
    return -2;
  }

  if (!(fout=fopen(argv[2],"w")))
  {
    t=(clock()-t)/CLOCKS_PER_SEC;
    printf ("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], task, res, t);
    return -2;
  }
  
  
  while(argv[3][i]!='\0')
  {
    if(argv[3][i]!='\\' || argv[3][i]!='?')
    {
      len++;
    }
    i++;
  }
  
  bufs = (char*)malloc((len + 1)* sizeof(char));
  s = (char*)malloc((len + 1)* sizeof(char));
  
  backsl=0;
  i=0;
  len=0;
  while(argv[3][i]!='\0')
  {
    if (!backsl)
    {
      if(argv[3][i]=='\\')
      {
        backsl=1;
        len--;
      } 
      else if(argv[3][i]=='?')
      {
        if (i==0)
        {
          free(s);
          free(bufs);
          fclose(fin);
          fclose(fout);
          t=(clock()-t)/CLOCKS_PER_SEC;
          printf ("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], task, res, t);
          return -3;
        }
          len--;
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
  if(backsl)
  {
    free(s);
    free(bufs);
    fclose(fin); 
    fclose(fout);  
    t=(clock()-t)/CLOCKS_PER_SEC;
    printf ("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], task, res, t); 
    return -4;
  }
  bufs[len+1]=0;
  s[len+1]=0; 
  
  while(fgets(procs,100000,fin)!=NULL)
  {
    i=0;
    flag=1;
    while(procs[i]!=0 && procs[i]!='\n')
    { 
      if(procs[i]!=s[i])
        if(bufs[i]=='0')
        {
          flag=0;
          break;
        }
      i++;
    }
    if (flag)
    {
      res++;
      fputs(procs,fout);
    }
  }
  if(!feof(fin))
  {
    free(s);
    free(bufs);
    fclose(fin);
    fclose(fout);
    t=(clock()-t)/CLOCKS_PER_SEC;
    printf ("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], task, res, t);
    return -5;
  }


free(s);
free(bufs);
fclose(fin);
fclose(fout);

t=(clock()-t)/CLOCKS_PER_SEC;
printf ("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], task, res, t);
return 0;
}
