#include "array_io.h"

int main(int argc,char *argv[])
{
  int task;
  double t,r1,r2,x0,epsilon;


  task=6;
  if(!(argc==3 && sscanf(argv[1],"%lf",&x0)==1 && sscanf(argv[2],"%lf",&epsilon)==1 && epsilon>0))
  {
    printf("Usege: %s x0 n f \n",argv[0]);
    return ERROR_ARGUMENT;
  }

  t=clock();
  r1=solution_6(x0,epsilon);
  r2=cos(x0);
  t=(clock()-t)/CLOCKS_PER_SEC;
  printf ("%s : Task = %d Result = %e Residual = %e Elapsed = %.2f\n",argv[0], task, r1, r2, t);
  return SUCCESS;
}