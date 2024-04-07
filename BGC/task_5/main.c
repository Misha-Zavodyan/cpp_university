#include "array_io.h"

int main(int argc,char *argv[])
{
  int n,m,p,k_a,k_b,ret,task;
  //double res;
  double t;
  char *name;
  double *a,*b,*c;

  task=1;
  if(!((argc==6 || argc==5) && sscanf(argv[1],"%d",&n)==1 && n>0 && 
  sscanf(argv[2],"%d",&m)==1 && m>0 && 
  sscanf(argv[3],"%d",&p)==1 && p>=0 && 
  sscanf(argv[4],"%d",&k_a)==1 && k_a>=0 &&
  sscanf(argv[4],"%d",&k_a)==1 && k_a>=0))
  {
    printf("Usege: %s n m p k name \n",argv[0]);
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
  b =(double*)malloc(m*sizeof(double));
  if (!b)
  {
    printf("not enough memory!\n");
    return ERROR_MEMORY;
  }
  c =(double*)malloc(n*sizeof(double));
  if (!c)
  {
    printf("not enough memory!\n");
    return ERROR_MEMORY;
  }

  if(k==0){
    ret=read_matrix(a,n,m,name);
  } else {
    ret=init_matrix(a,n,m,k);
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
  print_matrix(a,n,m,p);
  print_matrix(b,1,m,p);
  t=clock();
  solution_9(a,b,c,n,m);
  t=(clock()-t)/CLOCKS_PER_SEC;
  printf("Result matrix:\n");
  //print_matrix(&res,1,1,1);
  print_matrix(c,n,1,p);
  printf ("%s : Task = %d Elapsed = %.2f\n",argv[0], task, t);
  free(a);
  return SUCCESS;
}