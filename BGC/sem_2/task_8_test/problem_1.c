#include "array_io.h"

int main(int argc,char *argv[])
{
  int n,p,k_a,ret,task;
  double t,r1,r2;
  char *name_a;
  double *a,*x,*d;
  task=6;
  if(!((argc==5 || argc==4) && 
  sscanf(argv[1],"%d",&n)==1 && n>0 && 
  sscanf(argv[2],"%d",&p)==1 && p>=0 && 
  sscanf(argv[3],"%d",&k_a)==1 && k_a>=0))
  {
    printf("Usege: %s n p k (name) \n",argv[0]);
    return ERROR_ARGUMENT;
  }
  name_a=0;
  if(k_a==0)
  {
    name_a = argv[4];
  }

  a =(double*)malloc(n*n*sizeof(double));
  if (!a)
  {
    printf("not enough memory!\n");
    return ERROR_MEMORY;
  }
  x =(double*)malloc(n*n*sizeof(double));
  if (!x)
  {
    printf("not enough memory!\n");
    free(a);
    return ERROR_MEMORY;
  }
  d =(double*)malloc(n*sizeof(double));
  if (!d)
  {
    printf("not enough memory!\n");
    free(a);
    free(x);
    return ERROR_MEMORY;
  }

  if(k_a==0){
    ret=read_matrix(a,n,n,name_a);
  } else {
    ret=init_matrix(a,n,n,k_a);
  }

  if (ret!=SUCCESS)
  {
    switch(ret)
    {
      case ERROR_READ:
        printf("Can't reade %s! \n",name_a);
        break;
      case ERROR_OPEN:
        printf("Can't open %s! \n",name_a);
        break;
      default:
        printf("Unknown error %d in file %s %s",ret, k_a ? "file":"init" ,k_a ? name_a : " ");
    }
    free(a);
    free(x);
    free(d);
    return ret;
  }


  printf("Initial matrix A:\n");
  print_matrix(a,n,n,p);
  r1=matrix_norm(a,n);
  t=clock();
  ret=solution_1(a,x,n,d);
  t=(clock()-t)/CLOCKS_PER_SEC;
  if(ret==-1)
  {
    printf("Division by zero!\nCannot use Cholesky method.\n");
    free(a);
    free(x);
    free(d);
    return -1;
  }
  printf("Result matrix A^(-1):\n");
  print_matrix(x,n,n,p);
  if(k_a==0){
    ret=read_matrix(a,n,n,name_a);
  } else {
    ret=init_matrix(a,n,n,k_a);
  }

  if (ret!=SUCCESS)
  {
    switch(ret)
    {
      case ERROR_READ:
        printf("Can't reade %s! \n",name_a);
        break;
      case ERROR_OPEN:
        printf("Can't open %s! \n",name_a);
        break;
      default:
        printf("Unknown error %d in file %s %s",ret, k_a ? "file":"init" ,k_a ? name_a : " ");
    }
    free(a);
    free(x);
    free(d);
    return ret;
  }

  r1=r(x,a,n);
  r2=r(a,x,n);
  printf (
  "%s : Task = %d Res1 = %e Res2 = %e Elapsed = %.2f K = %d N = %d\n",
  argv[0], task, r1, r2, t, k_a, n);
  free(a);
  free(x);
  free(d);
  return SUCCESS;
}
