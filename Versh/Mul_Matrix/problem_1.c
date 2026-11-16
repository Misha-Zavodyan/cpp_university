#include "array_io.h"

int main(int argc,char *argv[])
{
  int n,p,k_a,ret;
  double t;
  char *name_a;
  double *a,*b,*c;

  if(!((argc==6 || argc==4) && 
  sscanf(argv[1],"%d",&n)==1 && n>0 && 
  sscanf(argv[2],"%d",&p)==1 && p>=0 && 
  sscanf(argv[3],"%d",&k_a)==1 && k_a>=0 && 
  sscanf(argv[4],"%d",&k_ab)==1 && k_b>=0)))
  {
    printf("Usege: %s n p k (name) \n",argv[0]);
    return ERROR_ARGUMENT;
  }
  name_a=0;
  if(k_a==0)
  {
    name_a = argv[5];
  }

  a =(double*)malloc(n*n*sizeof(double));
  if (!a)
  {
    printf("not enough memory!\n");
    return ERROR_MEMORY;
  }
  b =(double*)malloc(n*n*sizeof(double));
  if (!b)
  {
    printf("not enough memory!\n");
    free(a);
    return ERROR_MEMORY;
  }
  c =(double*)malloc(n*n*sizeof(double));
  if (!c)
  {
    printf("not enough memory!\n");
    free(a);
    free(b);
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
    free(b);
    free(c);
    return ret;
  }

  if(k_b==0){
    ret=read_matrix(b,n,n,name_a);
  } else {
    ret=init_matrix(b,n,n,k_a);
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

  printf("Initial matrix B:\n");
  print_matrix(b,n,n,p);

  t=clock();
  matrix_mult(a,b,n);
  t=(clock()-t)/CLOCKS_PER_SEC;
 
  printf("Result matrix C:\n");
  print_matrix(c,n,n,p);



  printf (
  "%s : Elapsed = %.2f K = %d N = %d\n",
  argv[0], t, k_a, n);
  free(a);
  free(b);
  return SUCCESS;
}
