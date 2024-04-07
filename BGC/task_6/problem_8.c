#include "array_io.h"

int main(int argc,char *argv[])
{
  int n,m,p,k,ret,task;
  int res;
  double t;
  char *name;
  double *a;

  task=8;
  if(!((argc==5 || argc==6) && sscanf(argv[1],"%d",&m)==1 && m>0 &&
  sscanf(argv[2],"%d",&n)==1 && n>0 &&  
  sscanf(argv[3],"%d",&p)==1 && p>=0 && 
  sscanf(argv[4],"%d",&k)==1 && k>=0))
  {
    printf("Usege: %s m n p k name \n",argv[0]);
    return ERROR_ARGUMENT;
  }
  if(k==0)
    name = argv[5];

  a =(double*)malloc(n*m*sizeof(double));
  if (!a)
  {
    printf("not enough memory!\n");
    return ERROR_MEMORY;
  }

  if(k==0){
    ret=read_matrix(a,m,n,name);
  } else {
    ret=init_matrix(a,m,n,k);
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
  print_matrix(a,m,n,p);
  t=clock();
  res=solution_8(a,m,n);
  t=(clock()-t)/CLOCKS_PER_SEC;
  printf("Result matrix:\n");
  print_matrix(a,m-1,n-1,p);
  printf ("%s : Task = %d Result = %d Elapsed = %.2f\n",argv[0], task, res, t);
  free(a);
  return SUCCESS;
}
