 #include "array_io.h"

int read_array(double *x,double *y,int n, char * name)
{
  FILE * fp;
  int i;
  if (!(fp=fopen(name,"r"))) 
    return ERROR_OPEN;
  for(i=0;i<n;i++)
    if((fscanf(fp,"%lf",x+i)!=1) || (fscanf(fp,"%lf",y+i)!=1))
    {
      fclose(fp);
      return ERROR_READ;
    }
  fclose(fp);
  return SUCCESS;
}

int read_array4(double *x,double *y,double *d,int n, char * name)
{
  FILE * fp;
  int i;
  if (!(fp=fopen(name,"r"))) 
    return ERROR_OPEN;
  for(i=0;i<n;i++)
    if((fscanf(fp,"%lf",x+i)!=1) || (fscanf(fp,"%lf",y+i)!=1)|| (fscanf(fp,"%lf",d+i)!=1))
    {
      fclose(fp);
      return ERROR_READ;
    }
  fclose(fp);
  return SUCCESS;
}

double solution_1(double x0,int n,double *x,double *y)
{
  int i,j;
  double s,prod,x_i,x_j;

  s=0;
  for(i=0;i<n;i++)
  {
    prod=y[i];
    x_i=x[i];
    for(j=0;j<i;j++)
    {
      x_j=x[j];
      prod*=(x0-x_j)/(x_i-x_j);
    }
    for(j=i+1;j<n;j++)
    {
      x_j=x[j];
      prod*=(x0-x_j)/(x_i-x_j);
    }
    s+=prod;
  }
  return s;
}

double solution_2(double x0,int n,double *x,double *y)
{
  int i,j;
  double s;

  for(i=n;i>0;i--)
  {
    for(j=n-1;j>n-i;j--)
    {
      y[j]=(y[j]-y[j-1])/(x[j]-x[j-n+i-1]);
    }
  }
  s=0;
  for(i=n-1;i>0;i--)
  {
    s=(s+y[i])*(x0-x[i-1]);
  }
  s+=y[0];
  return s;
}

double solution_3(double x0,int n,double *x,double *y)
{
  int i,j;

  for(i=n;i>0;i--)  
  {
    for(j=n-1;j>n-i;j--)
    {
      //printf("i:%d j:%d k:%d k-1:%d k-step-1:%d \n",i,j,k,k-1,k-step-1);
      y[j]=(y[j]*(x0-x[j-n+i-1])-y[j-1]*(x0-x[j]))/(x[j]-x[j-n+i-1]);
    }
  }
  return y[n-1];
}

double solution_4(double x0,int n,double *x,double *y, double *d)
{
  int i,j,k,m,i_1,i_2;
  double s;
  m=2*n;
  for(i=0;i<m;i++)
  {
    i_2=0;
    for(j=0;j<m-i;j++)
    {
      i_1=j*0.5;
      //printf("i:%d j:%d k:%d k-1:%d i/2-1-j/2:%d i/2-1-k:%d \n",i,j,k,k-1,i/2-1-j/2,i/2-1-k);
      
      if(!(j&1))
      {
        d[k]=(d[i_1]-y[i_2])/(x[k]-x[i/2-1-k]);
      }
      else
      {
        i_2++;
        y[k]=(y[i_1]-d[i_2])/(x[k]-x[i/2-1-j/2]);
      }
    }
  }
  s=0;
  for(i=n-1;i>0;i--)
  {
    k=i/2;
      if(i&1)
        s=(s+d[k])*(x0-x[k-1]);
      else
        s=(s+y[k])*(x0-x[k-1]);
  }
  s+=y[0];
  return s;
}

double sin_tylor(double x0,double epsilon)
{
  double res,nomial; 
  int n;
  res=nomial=x0; 
  n=1;

  while(fabs(nomial)>epsilon)  
    { 
      nomial*=-x0*x0/((n+1)*(n+2)); 
      res += nomial; 
      n+=2; 
    } 
  return res;
}

double cos_tylor(double x0,double epsilon)
{
  double res,nomial; 
  int n;
  res=nomial=1; 
  n=0;

  while(fabs(nomial)>epsilon)  
    { 
      nomial*=-x0*x0/((n+1)*(n+2)); 
      res += nomial; 
      n+=2; 
    } 
  return res;

}

double solution_5(double x0,double epsilon)
{
  double res,x,sgn;
  x=x0;
  res=0;
  if(x<0)
    sgn=-1;
  else
    sgn=1;
  
  x=fmod(x0,2*M_PI);
  x=fabs(x);
  if (fabs(x)<1)
    res=sin_tylor(x,epsilon);
  else
  {
    x=x-M_PI;
    sgn*=-1;
    if (fabs(x)<1)
      res=sin_tylor(x,epsilon);
    else
    {
      x=x-M_PI*0.5;
      if (fabs(x)<1)
        res=cos_tylor(x,epsilon);
      else
      {
        x*=0.5;
        res=1-2*sin_tylor(x,epsilon)*sin_tylor(x,epsilon);
      } 
    } 
  } 
  return sgn*res;
}

double solution_6(double x0,double epsilon)
{
  double res,x,sgn;
  x=x0;
  res=0;
  sgn=1;
  
  x=fmod(x0,2*M_PI);
  x=fabs(x);
  if (fabs(x)<1)
    res=cos_tylor(x,epsilon);
  else
  {
    x=x-M_PI;
    sgn*=-1;
    if (fabs(x)<1)
      res=cos_tylor(x,epsilon);
    else
    {
      x=x-M_PI*0.5;
      sgn*=-1;
      if (fabs(x)<1)
        res=sin_tylor(x,epsilon);
      else
      {
        x*=0.5;
        res=2*cos_tylor(x,epsilon)*sin_tylor(x,epsilon);
      } 
    } 
  } 
  return sgn*res;
}

double solution_7(double x0,double epsilon) 
{ 
  double res,nomial; 
  int n;
  res=nomial=1; 
  n=1;
  if(fabs(x0)>1000)
  {
    if (x0>0) 
      res=INFINITY;
    else
      res=0;
    return res;
  }
  if (x0>0) 
  { 
    while(fabs(nomial)>epsilon)  
    { 
      nomial*=x0/n; 
      res += nomial; 
      n++; 
    } 
    return res; 
  } 
  else  
  { 
    while(fabs(nomial)>epsilon) 
    { 
      nomial*=(-x0)/n; 
      res+=nomial; 
      n++; 
    }     
    if(res>0)  
      return 1/res; 
  } 
  return 0; 
}

double solution_8(double x0,double epsilon)
{
  double res,x,nomial;
  int p,n;
  x=x0;
  n=2;
  p=0;
  if(x0<0)
    return -NAN;
  if(x0<eps)
    return -INFINITY;
  
  while(x>1)
  {
    x=x*0.5;
    p++;
  }
  x=x-1;
  res=nomial=x;

  while(fabs(nomial/n)>epsilon)  
  { 
    nomial*=-x; 
    res += nomial/n; 
    n++; 
  } 
  
  return p*M_LN2+res;
}

/*

строица последывательность кторая должна сойтись
заводим констанут макс итераций 10000
for(it=0;iy<MAX_it)
if (условия выхода)
 breack


if it>=maxit
 print неудача

криткрий остановки 
1) НЕВЯЗКА
|f(x)|<eps
если f(x)=x, то |f(x)-x|<eps

2) кр коши
|f(xk+1)-f(xk)|<eps|f(xk)|

|xk+1 - xk|<eps

Сложность алгоритма
число вызово f(x)
K+O(1)










*/