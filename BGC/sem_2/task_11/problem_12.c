#include "find_root_io.h"

int main(int argc,char *argv[])
{
  double (*func[])( double)={f_1,f_2,f_3,f_4,f_5,f_6,f_7};
  const int len=sizeof(func)/sizeof(func[0]);
  double (*f)( double),(*g)( double);
  int task,k_f,k_g,count,n;
  double t,a,b,res,epsilon;

  
  task=12;
  b=0;
  if(!(argc==6 && sscanf(argv[1],"%lf",&a)==1 && sscanf(argv[2],"%lf",&b)==1
  && (b>a) && sscanf(argv[3],"%lf",&epsilon)==1 && epsilon>0  
  && sscanf(argv[4],"%d",&k_f)==1 && k_f>=0 && k_f<len 
  && sscanf(argv[5],"%d",&k_g)==1 && k_g>=0 && k_g<len))
  {
    printf("Usege: %s a b eps k \n",argv[0]);
    return ERROR_ARGUMENT;
  }
  f = func[k_f];
  g = func[k_g];

  t=clock();
  n=solution_12(f,g,a,b,epsilon,&res);
  t=(clock()-t)/CLOCKS_PER_SEC;
  count=return_count();
  printf ("%s : Task = %d Res = %e N = %d Count = %d T = %.2f\n",
  argv[0], task, res, n, count, t);
  return SUCCESS;
}