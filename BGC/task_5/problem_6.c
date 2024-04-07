#include "array_io.h"

int main(int argc,char *argv[])
{
  int n,m,p,k_a,k_b,ret,task;
  double t,res;
  char *name_a,*name_b;
  double *a,*b;

  task=6;
  if(!((argc==6 || argc==8 || argc==7) && sscanf(argv[1],"%d",&n)==1 && n>0 && 
  sscanf(argv[2],"%d",&m)==1 && m>0 &&  
  sscanf(argv[3],"%d",&p)==1 && p>=0 && 
  sscanf(argv[4],"%d",&k_a)==1 && k_a>=0))
  {
    printf("Usege: %s n m p k name \n",argv[0]);
    return ERROR_ARGUMENT;
  }

  if(k_a==0)
  {
    name_a = argv[5];
    if(!(sscanf(argv[6],"%d",&k_b)==1 && k_b>=0))
    {
      printf("Usege: %s n m p name \n",argv[0]);
      return ERROR_ARGUMENT;
    }
    if(k_b==0)
    {
      name_b = argv[7];
    }
  }
  else
  {
    if(!(sscanf(argv[5],"%d",&k_b)==1 && k_b>=0))
    {
      printf("Usege: %s n m p name \n",argv[0]);
      return ERROR_ARGUMENT;
    }
     if(k_b==0)
    {
      name_b = argv[6];
    }
  }

  a =(double*)malloc(n*m*sizeof(double));
  if (!a)
  {
    printf("not enough memory!\n");
    return ERROR_MEMORY;
  }
  b =(double*)malloc(m*n*sizeof(double));
  if (!b)
  {
    printf("not enough memory!\n");
    free(a);
    return ERROR_MEMORY;
  }

  if(k_a==0){
    ret=read_matrix(a,n,m,name_a);
  } else {
    ret=init_matrix(a,n,m,k_a);
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
      return ret;
    }

  if(k_b==0){
    ret=read_matrix(b,m,n,name_b);
  } else {
    ret=init_matrix(b,m,n,k_b);
  }

  if (ret!=SUCCESS)
    {
      switch(ret)
      {
        case ERROR_READ:
          printf("Can't reade %s! \n",name_b);
          break;
        case ERROR_OPEN:
          printf("Can't open %s! \n",name_b);
          break;
        default:
          printf("Unknown error %d in file %s %s",ret, k_b ? "file":"init" ,k_b ? name_b : " ");
      }
      free(a);
      free(b);
      return ret;
    }

  printf("Initial matrix:\n");
  print_matrix(a,n,m,p);
  printf("Initial matrix:\n");
  print_matrix(b,m,n,p);
  t=clock();
  res=solution_6(a,b,n,m);
  t=(clock()-t)/CLOCKS_PER_SEC;
  printf ("%s : Task = %d Result = %e Elapsed = %.2f\n",argv[0], task, res, t);
  free(a);
  free(b);
  return SUCCESS;
}