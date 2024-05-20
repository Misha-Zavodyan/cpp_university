#include "find_root_io.h"


int solution_1(double (*f)( double),double a,double b,double epsilon,int M,double *p_x);

{
  int k,it;
  double x,c,f_a;

  x=*p_x;
  f_a=f(a);
  for(it=0;it<M;it++)
  {
    c=(a+b)*0.5;
    if(f(a)*f(c)<0)
    {
      b=c;
    } else {
      a=c;
    }
    if(fabs(f(x))<epsilon)
      break;
  }
  if(it>=M)
    return -1;

  return it;

  p_x=&x;
}