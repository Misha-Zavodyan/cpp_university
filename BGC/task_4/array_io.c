 #include "array_io.h"

int init_matrix(double *a,int n,int m,int k)
{
  int i,j;
  for (i=0;i<n;i++)
    for(j=0;j<m;j++)
      a[i*m+j]=f(k,n,m,i+1,j+1);//+1 to trasfer from inf to math
  return SUCCESS;
}

double f(int k,int n,int m,int i,int j)
{
  switch(k)
  {
    case 1:
      return ((n>m?n:m)-(i>j?i:j)+1);
    case 2:
      return (i>j?i:j);
    case 3:
      return ((i>j?i:j)-(i<j?i:j));
    case 4:
      return 1./(i+j-1);
  }
  return -1e300;
}

void print_matrix(double *a,int n,int m, int p)
{
  int np=(n>p?p:n);
  int mp=(m>p?p:m);
  int i,j;
  for(i=0;i<np;i++)
  {
    for(j=0;j<mp;j++)
      printf(" %10.3e",a[i*m+j]);
    printf("\n");
  }
}

int read_matrix(double *a,int n,int m, char * name)
{
  FILE * fp;
  int i,j;
  if (!(fp=fopen(name,"r"))) 
    return ERROR_OPEN;
  for(i=0;i<n;i++)
    for(j=0;j<m;j++)
      if(fscanf(fp,"%lf",a+i*m+j)!=1)
      {
        fclose(fp);
        return ERROR_READ;
      }
  fclose(fp);
  return SUCCESS;
}

double solution_1(double *a,int n,int m)
{
  int i,j;
  for(i=0;i<n;i++)
    for(j=0;j<i;j++)
      if(fabs(a[i*n+j]-a[j*m+i])>eps)
        return 0;
  return 1;
}

double solution_2(double *a,int n,int m)
{
  int i;
  double res;
  (void)m;
  res=0;
  for(i=0;i<n;i++)
    res+=a[i*n+i];
  return res;
}

void solution_3(double *a,int n,int m)
{
  int i,j;
  double tmp;
  for(i=0;i<n;i++)
    for(j=0;j<i;j++)
    {                 //mb tut if sdelat
      tmp=a[i*n+j];
      a[i*n+j]=a[j*m+i];
      a[j*m+i]=tmp;
    }
}

void solution_4(double *a,int n,int m)
{
  int i,j;
  for(i=0;i<n;i++)
    for(j=0;j<i;j++)
    {                 //mb tut if sdelat
      a[i*n+j]=(a[i*n+j]+a[j*m+i])/2.;
      a[j*m+i]=a[i*n+j];
    }
}

void solution_5(double *a,int n,int m)
{
  int i,j;
  for(i=0;i<n;i++)
    for(j=0;j<i;j++)
    {                 //mb tut if sdelat
      a[i*n+j]=(a[i*n+j]-a[j*m+i])/2.;
      a[j*m+i]=-1*a[i*n+j];
    }
  for(i=0;i<n;i++)
    a[i*n+i]=0;
}

void solution_6(double *a,int n,int m,int i,int j)
{
  int k;
  double tmp;
  double *q,*p;
  (void)n;
  q=a+i*m;
  p=a+j*m;
  for(k=0;k<m;k++)
  {
    tmp=q[k];
    q[k]=p[k];
    p[k]=tmp;
  }  
}

void solution_7(double *a,int n,int m,int i,int j)
{
  int k;
  double tmp;
  double *q,*p;
  //(void)m;
  q=a+i;
  p=a+j;
  for(k=0;k<n;k++)
  {
    tmp=q[k*m];
    q[k*m]=p[k*m];
    p[k*m]=tmp;
  }  
}

void solution_8(double *a,int n,int m,int i,int j,int c)
{
  int k;
  double *q,*p;
  (void)n;
  q=a+i*m;
  p=a+j*m;
  for(k=0;k<m;k++)
  {
    p[k]+=c*q[k];
  }  
}