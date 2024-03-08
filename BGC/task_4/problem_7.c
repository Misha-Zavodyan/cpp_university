#include "array_io.h"

int main(int argc,char *argv[])
{
  int i,j,n,m,p,k,ret,task;
  double t;
  char *name;
  double *a;

  task=1;
  if(!((argc==8 || argc==7) && sscanf(argv[1],"%d",&i)==1 && i>0 &&sscanf(argv[2],"%d",&j)==1 
  && j>0 &&sscanf(argv[3],"%d",&n)==1 && n>0 && 
  sscanf(argv[4],"%d",&m)==1 && m>0 && 
  sscanf(argv[5],"%d",&p)==1 && p>=0 && 
  sscanf(argv[6],"%d",&k)==1 && k>=0 && i<=m && j <= m))
  {
    printf("Usege: %s n m p k name \n",argv[0]);
    return ERROR_ARGUMENT;
  }
  if(k==0)
    name = argv[7];

  a =(double*)malloc(n*m*sizeof(double));
  if (!a)
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
  t=clock();
  solution_7(a,n,m,i-1,j-1);
  t=(clock()-t)/CLOCKS_PER_SEC;
  printf("Result matrix:\n");
  print_matrix(a,n,m,p);
  printf ("%s : Task = %d Elapsed = %.2f\n",argv[0], task, t);
  free(a);
  return SUCCESS;
}