#include "str_io.h"

int main(int argc,char *argv[])
{
  FILE *fin,*fout;
  int i,len,task,res,backsl,flag;
  double t;
  char* s,* bufs,*name1,*name2,*s,procs[LEN];

  task=1;
  i=0;    
  len=0;
  name1=argv[1];
  name2=argv[2];
  s=argv[3];

  if (argc!=4)
  {
    printf("Usege: %s c n p name \n",argv[0]);
    return ERROR_ARGUMENT;
  }
  
  // if (!(fin=fopen(name1,"r")))
  // {
  //   printf("Can't open %s! \n",name1);
  //   return ERROR_OPEN;
  // }

  // if (!(fout=fopen(name2,"w")))
  // {
  //   printf("Can't open %s! \n",name2);
  //   return ERROR_OPEN;
  // }
  
  
  // while(s[i]!='\0')
  // {
  //   if(s[i]!='\\')
  //   {
  //     len++;
  //   }
  //   i++;
  // }
  
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
  bufs[len]=0;
  s[len]=0; 
  while(fgets(procs,LEN,fin)!=NULL)
  {
    i=0;
    flag=1;
    
    while(procs[i]!=0 && procs[i]!='\n')
    { 
      if (procs[i]!=s[i])
        if (bufs[i]=='0')
        {
          flag=0;
          break;
        }
      i++;
    }
    if(len!=i) flag=0;
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
