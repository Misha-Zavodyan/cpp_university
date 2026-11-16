#include "find_root_io.h"

int main(int argc,char *argv[])
{
  double (*func[])( double)={f_1,f_2,f_3,f_4,f_5,f_6,f_7};
  const int len=sizeof(func)/sizeof(func[0]);
  double (*f)( double);
  int task,k,count,n;
  double t,a,b,res,epsilon;

  n=0;
  task=9;
  if(!(argc==5 && sscanf(argv[1],"%lf",&a)==1 && sscanf(argv[2],"%lf",&b)==1
  && (b>a) && sscanf(argv[3],"%lf",&epsilon)==1 && epsilon>0  
  && sscanf(argv[4],"%d",&k)==1 && k>=0 && k<=len))
  {
    printf("Usege: %s a b eps k \n",argv[0]);
    return ERROR_ARGUMENT;
  }
  f = func[k];

  t=clock();
  res=solution_9(f,a,b,epsilon,&n);
  t=(clock()-t)/CLOCKS_PER_SEC;
  count=return_count();
  printf ("%s : Task = %d Res = %e N = %d Count = %d T = %.2f\n",
  argv[0], task, res, n, count, t);
  return SUCCESS;
}