#include "find_root_io.h"

int main(int argc,char *argv[])
{
  double (*func[])( double)={f_1,f_2,f_3,f_4,f_5,f_6,f_7};
  const int len=sizeof(func)/sizeof(func[0]);
  double (*f)( double);
  int it,task,M,k,count;
  double t,x,fx,a,b,epsilon;

  
  task=1;
  if(!(argc==6 && sscanf(argv[1],"%lf",&a)==1 && sscanf(argv[2],"%lf",&b)==1 
  && sscanf(argv[3],"%lf",&epsilon)==1 && epsilon>0
  && sscanf(argv[4],"%d",&M)==1 && sscanf(argv[5],"%d",&k)==1 && k>=0 && k<=len))
  {
    printf("Usege: %s a b eps M k \n",argv[0]);
    return ERROR_ARGUMENT;
  }
  f = func[k];

  t=clock();
  it=solution_1(f,a,b,epsilon,M,&x);
  t=(clock()-t)/CLOCKS_PER_SEC;
  if(it<0)
    printf ("%s : Task = %d NOT FOUND Count = %d T = %.2f\n",argv[0], task, count, t);
  fx=f(x);

  printf ("%s : Task = %d X = %e Res = %e Its = %d Count = %d T = %.2f\n", argv[0], task, x, fx, it, count, t);
  return SUCCESS;
}