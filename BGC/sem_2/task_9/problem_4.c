#include "array_io.h"

int main(int argc,char *argv[])
{
  int n,ret,task;
  double t,r,x0;
  char *f;
  double *x,*y,*d;

  task=4;
  if(!(argc==4 && sscanf(argv[1],"%lf",&x0)==1 && sscanf(argv[2],"%d",&n)==1 && n>0))
  {
    printf("Usege: %s x0 n f \n",argv[0]);
    return ERROR_ARGUMENT;
  }
  f = argv[3];
    

  x =(double*)malloc(n*sizeof(double));
  if (!x)
  {
    printf("not enough memory!\n");
    return ERROR_MEMORY;
  }

  y =(double*)malloc(n*sizeof(double));
  if (!y)
  {
    printf("not enough memory!\n");
    free(x);
    return ERROR_MEMORY;
  }

  d =(double*)malloc(n*sizeof(double));
  if (!d)
  {
    printf("not enough memory!\n");
    free(x);
    free(y);
    return ERROR_MEMORY;
  }
  
 
  ret=read_array4(x,y,d,n,f);

  if (ret!=SUCCESS)
  {
    switch(ret)
    {
      case ERROR_READ:
        printf("Can't reade %s! \n",f);
        break;
      case ERROR_OPEN:
        printf("Can't open %s! \n",f);
        break;
      default:
        printf("Unknown error %d in file %s",ret, f);
    }
      free(x);
      free(y);
      free(d);
    return ret;
  }

  t=clock();
  r=solution_4(x0,n,x,y,d);
  t=(clock()-t)/CLOCKS_PER_SEC;
  printf ("%s : Task = %d Result = %e Elapsed = %.2f\n",argv[0], task, r, t);
  free(x);
  free(y);
  free(d);
  return SUCCESS;
}