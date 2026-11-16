#include "array_io.h"

int main(int argc,char *argv[])
{
  int n,m,p,k_a,k_x,ret,task;
  double t,r1,r2;
  char *name_a,*name_x;
  double *a,*x,*x_0,*b,*r;
  name_x=0;
  task=3;
  if(!((argc==6 || argc==8 || argc==7) && sscanf(argv[1],"%d",&m)==1 && m>0 && 
  sscanf(argv[2],"%d",&n)==1 && n>0 && 
  sscanf(argv[3],"%d",&p)==1 && p>=0 && 
  sscanf(argv[4],"%d",&k_a)==1 && k_a>=0))
  {
    printf("Usege: %s m n p k_a (f_a) k_x (f_x) name \n",argv[0]);
    return ERROR_ARGUMENT;
  }

  if(k_a==0)
  {
    name_a = argv[5];
    if(!(sscanf(argv[6],"%d",&k_x)==1 && k_x>=0))
    {
      printf("Usege: %s n m p k name \n",argv[0]);
      return ERROR_ARGUMENT;
    }
    if(k_x==0)
    {
      name_x = argv[7];
    }
  }
  else
  {
    if(!(sscanf(argv[5],"%d",&k_x)==1 && k_x>=0))
    {
      printf("Usege: %s m n p k name \n",argv[0]);
      return ERROR_ARGUMENT;
    }
     if(k_x==0)
    {
      name_x = argv[6];
    }
  }

  a =(double*)malloc(n*n*sizeof(double));
  if (!a)
  {
    printf("not enough memory!\n");
    return ERROR_MEMORY;
  }
  x_0 =(double*)malloc(n*sizeof(double));
  if (!x_0)
  {
    printf("not enough memory!\n");
    free(a);
    return ERROR_MEMORY;
  }
  x =(double*)malloc(n*sizeof(double));
  if (!x)
  {
    printf("not enough memory!\n");
    free(a);
    free(x_0);
    return ERROR_MEMORY;
  }
  b =(double*)malloc(n*sizeof(double));
  if (!b)
  {
    printf("not enough memory!\n");
    free(a);
    free(x_0);
    free(x);
    return ERROR_MEMORY;
  }
  r =(double*)malloc(n*sizeof(double));
  if (!r)
  {
    printf("not enough memory!\n");
    free(a);
    free(x_0);
    free(x);
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
      free(x);
      free(x_0);
      free(b);
      free(r);
      return ret;
    }
  b_init(a,b,n);
  if(k_x==0){
    ret=read_matrix(x_0,n,1,name_x);
  } else {
    ret=init_matrix(x_0,n,1,k_x);
  }

  if (ret!=SUCCESS)
    {
      switch(ret)
      {
        case ERROR_READ:
          printf("Can't reade %s! \n",name_x);
          break;
        case ERROR_OPEN:
          printf("Can't open %s! \n",name_x);
          break;
        default:
          printf("Unknown error %d in file %s %s",ret, k_x ? "file":"init" ,k_x ? name_x : " ");
      }
      free(a);
      free(x);
      free(x_0);
      free(b);
      free(r);
      return ret;
    }

  printf("Initial matrix:\n");
  print_matrix(a,n,n,p);
  printf("Initial vector x_0:\n");
  print_matrix(x_0,1,n,p);
  printf("Initial vector b:\n");
  print_matrix(b, 1, n, p);
  t=clock();
  solution_3(a,x_0,b,x,r,n,m);
  t=(clock()-t)/CLOCKS_PER_SEC;
  printf("Result vector x_%d:\n",m);
  print_matrix(x,1,n,p);
  r1=r_1(a,x,b,n);
  r2=r_2(x,n);
  printf ("%s : Task = %d Res1 = %e Res2 = %e Elapsed = %.2f\n",argv[0], task, r1, r2, t);
  free(a);
  free(x);
  free(x_0);
  free(b);
  free(r);
  return SUCCESS;
}