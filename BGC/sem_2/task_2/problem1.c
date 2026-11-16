#include "str_io.h"

int main(int argc,char *argv[])
{
  FILE *fin,*fout;
  int i,len,task,res,backsl,flag;
  double t;
  char* s, *bufs,*name1,*name2,*s,procs[LEN];

  task=1;
  i=0;    
  len=0;

  if (argc!=4)
  {
    printf("Usege: %s c n p name \n",argv[0]);
    return ERROR_ARGUMENT;
  }
  name1=argv[1];
  name2=argv[2];
  s=argv[3];
  
  s = (char*)malloc((len + 1)* sizeof(char));
  if (!s)
  {
    printf("not enough memory!\n");
    return ERROR_MEMORY;
  }

  

  // if(backsl)
  // {
  //   free(s);
  //   free(bufs);
  //   fclose(fin); 
  //   fclose(fout);  
  //   t=(clock()-t)/CLOCKS_PER_SEC;
  //   printf ("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], task, res, t); 
  //   return -4;
  // }
  // bufs[len]=0;
  // s[len]=0; 
  // while(fgets(procs,LEN,fin)!=NULL)
  // {
  //   i=0;
  //   flag=1;
  //   =0;
  // s[len]=0;
  //   while(procs[i]!=0 && procs[i]!='\n')
  //   { 
  //     if (procs[i]!=s[i])
  //       if (bufs[i]=='0')
  //       {
  //         flag=0;
  //         break;
  //       }
  //     i++;
  //   }
  //   if(len!=i) flag=0;
  //   if (flag)
  //   {
  //     res++;
  //     fputs(procs,fout);
  //   }
  // }

  // if(!feof(fin))
  // {
  //   free(s);
  //   free(bufs);
  //   fclose(fin);
  //   fclose(fout);
  //   t=(clock()-t)/CLOCKS_PER_SEC;
  //   printf ("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], task, res, t);
  //   return -5;
  // }

t=clock();
solution_1(fin,fout,s,&res);
t=(clock()-t)/CLOCKS_PER_SEC;
printf ("%s : Task = %d Result = %d Elapsed = %.2f\n", argv[0], task, res, t);
free(s);
return 0;
}
