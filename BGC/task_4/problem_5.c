#include "array_io.h"

int main(int argc,char *argv[])
{
  int n,p,k,ret,task;
  double t;
  char *name;
  double *a;

  task=1;
  if(!((argc==5 || argc==4) && sscanf(argv[1],"%d",&n)==1 && n>0 &&  
  sscanf(argv[2],"%d",&p)==1 && p>=0 && 
  sscanf(argv[3],"%d",&k)==1 && k>=0))
  {
    printf("Usege: %s n p k name \n",argv[0]);
    return ERROR_ARGUMENT;
  }
  if(k==0)
    name = argv[4];

  a =(double*)malloc(n*n*sizeof(double));
  if (!a)
  {
    printf("not enough memory!\n");
    return ERROR_MEMORY;
  }

  if(k==0){
    ret=read_matrix(a,n,n,name);
  } else {
    ret=init_matrix(a,n,n,k);
  }

  if (ret!=SUCCESS)
    {
      switch(ret)
      {
        case ERROR_READ:
          printf("Can't reade %s! \n",name);
          break;
        case ERROR_OPEN:
          printf("Can't open %s! \n",name);
          break;
        default:
          printf("Unknown error %d in file %s %s",ret, k ? "file":"init" ,k ? name : " ");
      }
      free(a);
      return ret;
    }

  printf("Inition matrix:\n");
  print_matrix(a,n,n,p);
  t=clock();
  solution_5(a,n);
  t=(clock()-t)/CLOCKS_PER_SEC;
  printf("Result matrix:\n");
  print_matrix(a,n,n,p);
  printf ("%s : Task = %d Elapsed = %.2f\n",argv[0], task, t);
  free(a);
  return SUCCESS;
}