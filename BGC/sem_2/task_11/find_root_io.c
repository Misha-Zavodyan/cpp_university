#include "find_root_io.h"

int my_sgn(double x)
{
  if (x<0)
    return -1;
  else if (x>0)
    return 1;
  return 0;
}

double solution_1(double (*f)( double),double x,double h)
{
  double res;
  res= f(x+h)-f(x);
  res /=h;
  return res;
}

double solution_2(double (*f)( double),double x,double h)
{
  double res;

  res= f(x+h)-f(x-h);
  res /= 2*h;

  return res;
}

double solution_3(double (*f)( double),double x,double h)
{
  double res;

  res= f(x+h)-2*f(x) +f(x-h);
  res /= h*h;

  return res;
}

double solution_4(double (*f)( double),double a,double b,int n)
{//n+1 вызовов функции
  double res,h,x;
  int i;

  h = (b-a)/n;  //n>=1

  res=f(a)*0.5;
  for(i=1;i<n;i++)
  {
    x=a+i*h;
    res+= f(x);
  }
  res+=f(b)*0.5;
  res*=h;
  
  return res;
}

double solution_5(double (*f)( double),double a,double b,int n)
{//n+1 вызовов функции
  double res,h,x;
  int i;

  h = (b-a)/(2*n);  //n>=1

  res=f(a)*0.5;
  for(i=1;i<2*n;i++)
  {
    x=a+i*h;
    if(i&1)
      res+= 2*f(x);
    else
      res+= f(x);
  }
  res+=f(b)*0.5;
  res*=h*(2/3.);
  
  return res;
}

double solution_6(double (*f)( double),double a,double b,int n)
{//n+1 вызовов функции
  double res,h,x_1,x_2,y_1,y_2,fi,ai,bi,sgnx1,sgnx2,z_1,z_2;
  int i;

  h = (b-a)/n;  //n>=1
  res=0;
  y_2=f(a);
  for(i=0;i<n;i++)
  {
    x_1=a+i*h;
    x_2=a+(i+1)*h;
    y_1=y_2;
    y_2=f(x_2);
    fi=(y_2-y_1)/(x_2-x_1);
    ai=y_1-x_1*fi;
    bi=fi;

    sgnx1=my_sgn(x_1);
    sgnx2=my_sgn(x_2);
    z_1=sqrt(fabs(x_1));
    z_2=sqrt(fabs(x_2));

    res+= ai*2*(z_2*sgnx2-z_1*sgnx1);
    res+= bi*(2./3)*(z_2*z_2*z_2-z_1*z_1*z_1);
  }
  
  return res;
}

double solution_7(double (*f)( double),double a,double b,int n)
{//n+1 вызовов функции
  double res,h,x_1,x_2,x_3,y_1,y_2,y_3,f12,f23,f123,ai,bi,ci,sgnx1,sgnx2,z_1,z_2;
  int i;

  h = (b-a)/(2*n);  //n>=1
  res=0;
  y_2=f(a);
  y_3=f(a+h);
  for(i=0;i<n;i++)
  {
    x_1=a+i*2*h;
    x_2=a+(2*i+1)*h;
    x_3=a+(2*i+2)*h;
    y_1=y_2;
    y_2=y_3;
    y_3=f(x_3);
    f12=(y_2-y_1)/(x_2-x_1);
    f23=(y_3-y_2)/(x_3-x_2);
    f123=(f23-f12)/(x_3-x_1);

    ai=y_1-x_1*f12+x_1*x_2*f123;
    bi=f12-f123*x_1-f123*x_2;
    ci=f123;

    sgnx1=my_sgn(x_1);
    sgnx2=my_sgn(x_3);
    z_1=sqrt(fabs(x_1));
    z_2=sqrt(fabs(x_3));

    res+= ai*2*(z_2*sgnx2 - z_1*sgnx1);
    res+= bi*(2./3)*(z_2*z_2*z_2 - z_1*z_1*z_1);
    res+= ci*(2./5)*(z_2*z_2*z_2*z_2*z_2*sgnx2 - z_1*z_1*z_1*z_1*z_1*sgnx1);
  }
  
  return res;
}

double solution_8(double (*f)( double),double a,double b,double epsilon,int *nn)
{//n+1 вызовов функции
  double res,res2,h,x;
  int i,n;

  *nn=n=1;
  h = (b-a)/n;  //n>=1

  res=f(a)*0.5*h;
  for(i=1;i<n;i++)
  {
    x=a+i*h;
    res+= f(x)*h;
  }
  res+=f(b)*0.5*h;
  //res*=h;
  res2=0;
  while(fabs(res2-res)>=epsilon)
  {
    if (n>1)
      res=res2;
    
    res2=res*0.5;
    h *=0.5;
    for(i=0;i<n;i++)
    {
      x=a+(2*i+1)*h;
      res2+= f(x)*h;
    }
    if(n>=pow(2,30))
      break;
    n*=2;
    //res=res2;
  }

  
  *nn=n;
  return res2;
}

double solution_9(double (*f)( double),double a,double b,double epsilon,int *nn)
{//n+1 вызовов функции
  double res,res2,h,x,s2n,s22n,tmp;
  int i,n;

  *nn=n=1;
  h = (b-a)/(2*n);  //n>=1
  s2n=0;
  
  res=f(a)*0.5;
  for(i=1;i<2*n;i++)
  {
    x=a+i*h;
    tmp=f(x);
    if(i&1)
    {
      s2n+=tmp;
      res+= tmp;
    }
    else
      res+= tmp;
  }
  res+=f(b)*0.5;
  res*=h*(2/3.);

  res2=0;
  s22n=0;
  while(fabs((res2+s22n)-(res+s2n))>=epsilon)
  {
    if (n>1)
    {
      res=res2;
      s2n=s22n;
    }
    res2=res*0.5;
    h *=0.5;
    s22n=0;
    for(i=0;i<2*n;i++)
    {
      x=a+(2*i+1)*h;
      tmp=f(x)*2./3.*h;
      s22n+= tmp;
      res2+= tmp;
    }
    
    if(n>=pow(2,29))
      break;
    n*=2;
  }

  
  *nn=n;
  return (res2+s22n);
}

double solution_10(double (*f)( double),double a,double *bb ,double epsilon)
{
  double H,b,I,Is;
  int n;

  H=1;
  *bb=b=a+H;
 
  Is=I=solution_8(f,a,b,epsilon,&n);
  while(fabs(I)>=epsilon)
  {
    I=solution_8(f,b,b+H,epsilon,&n);
    Is+=I;
    H*=2;
    b=a+H;
    if(fabs(H)>=pow(2,33))
      break;
  }

  *bb=b;
  return Is;
}

double solution_11(double (*f)( double),double a,double *bb ,double epsilon)
{
  double H,b,I,Is;
  int n;

  H=1;
  *bb=b=a+H;
 
  Is=I=solution_9(f,a,b,epsilon,&n);
  while(fabs(I)>=epsilon)
  {
    I=solution_9(f,b,b+H,epsilon,&n);
    Is+=I;
    H*=2;
    b=a+H;
    if(fabs(H)>=pow(2,33))
      break;
  }

  *bb=b;
  return Is;
}

int solution_12(double (*f)( double),double (*g)( double),double a,double b,double epsilon,double *r)
{
  double res,res2,h,x_2,x_1,y_2,y_1,t,y_a,x_a;
  int i,n;

  n=1;
  h = (b-a)/n;  
  x_a=x_1=f(a);
  x_2=f(b);
  y_a=y_1=g(a);
  y_2=g(b);
  res=sqrt((x_2-x_1)*(x_2-x_1)+(y_2-y_1)*(y_2-y_1));

  res2=res+2*epsilon;
  while(fabs(res2-res)>=epsilon)
  {
    if (n>1)
      res=res2;
    
    res2=0;
    if(n>=pow(2,29))
    {
      *r=-1;
      return n;
    }
    n*=2;
    h*=0.5;
    x_2=x_a;
    y_2=y_a;
    for(i=0;i<n;i++)
    {
      t=a+(i+1)*h;
      x_1=x_2;
      x_2=f(t);
      y_1=y_2;
      y_2=g(t);
      
      res2+=sqrt((x_2-x_1)*(x_2-x_1)+(y_2-y_1)*(y_2-y_1));
    }
  }

  
  *r=res2;
  return n;
}