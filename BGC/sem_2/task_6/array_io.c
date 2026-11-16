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

int solution_1(double *a,int m, int n)
{
  int i,j,step,j_min;
  double minn,tmp;
  double *q;
  j_min=0;
  minn=99999999999;
  for(i=0;i<m;i++)
  {
  q=a+i*n;
    for(j=0;j<n;j++)
    {
      tmp=fabs(q[j]);
      if(tmp<minn)
      {
        minn=tmp;
        j_min=j;
      }
    }
  }

  step=0;
  for(i=0;i<m;i++)
  {
  q=a+i*n;
    for(j=0;j<n;j++)
    {
      if(j==j_min)
        step+=1;
      else
        q[j-step]=q[j];
    }
  }


  return (j_min+1);
}

int solution_2(double *a,int m, int n)
{
  int i,j,step,j_min,i_min;
  double minn,tmp;
  double *q;
  j_min=0;
  i_min=0;
  minn=99999999999;
  for(i=0;i<m;i++)
  {
  q=a+i*n;
    for(j=0;j<n;j++)
    {
      tmp=fabs(q[j]);
      if(tmp<minn)
      {
        minn=tmp;
        j_min=j;
        i_min=i;
      }
    }
  }

  step=0;
  q=a;
  for(i=0;i<m;i++)
  {
  
    for(j=0;j<n;j++)
    {
      if(i==i_min)
      {
        step+=n;
        j+=n;
      }
      if(j==j_min)
        step+=1;
      else
        q[j-step]=q[j];
    }
  q+=n;
  }


  return ( n*(i_min) + j_min );
}


int solution_3(double *a,int m, int n)
{
  int i,j,step,j_min;
  double minn,summ;
  double *q;
  j_min=0;
  minn=99999999999;
  for(i=0;i<n;i++)
  {
  q=a+i;
  summ=0;
    for(j=0;j<m;j++)
    {
      summ+=fabs(q[j*n]);  
    }
  if(summ<minn)
  {
    minn=summ;
    j_min=i;
  }
  }

  step=0;
  for(i=0;i<m;i++)
  {
  q=a+i*n;
    for(j=0;j<n;j++)
    {
      if(j==j_min)
        step+=1;
      else
        q[j-step]=q[j];
    }
  }

  return (j_min+1);
}

int solution_4(double *a,int m, int n)
{
  int i,j,step,j_min,i_min;
  double minn,summ;
  double *q;
  j_min=0;
  i_min=0;
  summ=0;
  minn=99999999999;
  for(i=0;i<m;i++)
  {
    q=a+i*n;
    for(j=0;j<n;j++)
    {
      summ+=fabs(q[j]);
    }
    if(summ<minn)
    {
      minn=summ;
      i_min=i;
    }
  }

  minn=99999999999;
  for(i=0;i<n;i++)
  {
    q=a+i;
    summ=0;
    for(j=0;j<m;j++)
    {
      summ+=fabs(q[j*n]);  
    }
    if(summ<minn)
    {
      minn=summ;
      j_min=i;
    }
  }

  step=0;
  q=a;
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      if(i==i_min)
      {
        step+=n;
        j+=n;
      }
      if(j==j_min)
        step+=1;
      else
        q[j-step]=q[j];
    }
    q+=n;
  }

  return ( n*(i_min) + j_min );
}

int solution_5(double *a,int m, int n)
{
  int i,j,step,j_max;
  double maxx,summ;
  double *q;
  j_max=0;
  maxx=-1;
  for(i=0;i<n;i++)
  {
    q=a+i;
    summ=0;
    for(j=0;j<m;j++)
    {
      if(i!=j)
        summ+=fabs(q[j*n]);  
    }
    if(summ>maxx)
    {
      maxx=summ;
      j_max=i;
    }
  }

  step=0;
  for(i=0;i<m;i++)
  {
    q=a+i*n;
    for(j=0;j<n;j++)
    {
      if(j==j_max)
        step+=1;
      else
        q[j-step]=q[j];
    }
  }
  
  return (j_max+1);
}

int solution_6(double *a,int m, int n)
{
  int i,j,step,j_max,k;
  double maxx,summ;
  double *q,p;
  j_max=0;
  maxx=-1;
  k=(n<m?n:m);
  for(i=0;i<k;i++)
  {
    q=a+i;
    p=a[i*k+i];
    summ=0;
    for(j=0;j<k;j++)
    {
      if(i!=j)
        summ+=fabs(q[j*k]-p);  
    }
    if(summ>maxx)
    {
      maxx=summ;
      j_max=i;
    }
  }

  step=0;
  for(i=0;i<m;i++)
  {
    q=a+i*n;
    for(j=0;j<n;j++)
    {
      if(j==j_max)
        step+=1;
      else
        q[j-step]=q[j];
    }
  }
  
  return (j_max+1);
}

int solution_7(double *a,int m, int n)
{
  int i,j,step,j_max;
  double maxx,summ,sub_sum,factor,p;
  double *q;
  j_max=0;
  maxx=99999999999;
  
  factor=1./m;

  for(i=0;i<n;i++)
  {
    q=a+i;
    summ=0;
    sub_sum=0;
    for(j=0;j<m;j++)
    {
      sub_sum+=(q[j*n]);  
    }
    sub_sum*=factor;
    for(j=0;j<m;j++)
    {
      p=q[j*n];
      summ+=((p-sub_sum)*(p-sub_sum));  
    }
    if(summ<maxx)
    {
      maxx=summ;
      j_max=i;
    }
  }

  step=0;
  for(i=0;i<m;i++)
  {
    q=a+i*n;
    for(j=0;j<n;j++)
    {
      if(j==j_max)
        step+=1;
      else
        q[j-step]=q[j];
    }
  }
  
  return (j_max+1);
}

int solution_8(double *a,int m, int n)
{
  int i,j,step,j_min,i_min;
  double minn,summ;
  double *q;
  j_min=0;
  i_min=0;
  summ=0;
  minn=-1;
  for(i=0;i<m;i++)
  {
    q=a+i*n;
    for(j=0;j<n;j++)
    {
      if(i!=j)
        summ+=fabs(q[j]);
    }
    if(summ>minn)
    {
      minn=summ;
      i_min=i;
    }
  }

  minn=-1;
  for(i=0;i<n;i++)
  {
    q=a+i;
    summ=0;
    for(j=0;j<m;j++)
    {
      if(i!=j)
        summ+=fabs(q[j*n]);  
    }
    if(summ>minn)
    {
      minn=summ;
      j_min=i;
    }
  }

  step=0;
  q=a;
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      if(i==i_min)
      {
        step+=n;
        j+=n;
      }
      if(j==j_min)
        step+=1;
      else
        q[j-step]=q[j];
    }
    q+=n;
  }

  return ( n*(i_min) + j_min );
}

int solution_9(double *a,int m, int n)
{
  int i,j,k,step,j_min,i_min;
  double minn,summ,sub_sum;
  double *q,c;
  j_min=0;
  i_min=0;
  summ=0;
  minn=-1;
  for(i=0;i<m;i++)
  {
    
    q=a+i*n;
    for(j=0;j<n;j++)
    {
      sub_sum=0;
      summ=0;
      c=q[j];
      for(k=0;k<j;k++)
        sub_sum+=fabs(q[k]-c);
      for(k=j+1;k<n;k++)
        sub_sum+=fabs(q[k]-c);
      for(k=j;k<(j+i*n);k+=n)
        summ+=fabs(a[k]-c);
      for(k=(j+i*n+n);k<n*m;k+=n)
        summ+=fabs(a[k]-c);
      //printf("i: %d j: %d sub: %f sum: %f\n",i,j,sub_sum,summ);

      if((summ+sub_sum)>minn)
      {
        minn=(summ+sub_sum);
        i_min=i;
        j_min=j;
      }
    }
  }

  step=0;
  q=a;
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      if(i==i_min)
      {
        step+=n;
        j+=n;
      }
      if(j==j_min)
        step+=1;
      else
        q[j-step]=q[j];
    }
    q+=n;
  }

  return ( n*(i_min) + j_min );
}

int solution_10(double *a,int m, int n)
{
  int i,j,step,j_max,i_max;
  double maxx,summ,sub_sum,factor1,factor2;
  double *q,p;
  j_max=0;
  i_max=0;
  factor1=1./n;
  factor2=1./m;


  maxx=99999999999;
  for(i=0;i<n;i++)
  {
    q=a+i;
    summ=0;
    sub_sum=0;
    for(j=0;j<m;j++)
    {
      sub_sum+=(q[j*n]);  
    }
    sub_sum*=factor2;
    for(j=0;j<m;j++)
    {
      p=q[j*n];
      summ+=((p-sub_sum)*(p-sub_sum));  
    }
    printf("j: %d sum: %f\n",i,summ);
    if(summ<maxx)
    {
      maxx=summ;
      j_max=i;
    }
  }
  

  maxx=99999999999;
  for(i=0;i<m;i++)
  {
    q=a+i*n;
    summ=0;
    sub_sum=0;
    for(j=0;j<n;j++)
    {
      sub_sum+=(q[j]);  
    }
    sub_sum*=factor1;
    for(j=0;j<n;j++)
    {
      p=q[j];
      summ+=((p-sub_sum)*(p-sub_sum));  
    }
    printf("i: %d sum: %f\n",i,summ);
    if(summ<maxx)
    {
      maxx=summ;
      i_max=i;
    }
  }
  

  step=0;
  q=a;
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      if(i==i_max)
      {
        step+=n;
        j+=n;
      }
      if(j==j_max)
        step+=1;
      else
        q[j-step]=q[j];
    }
    q+=n;
  }

  return ( n*(i_max) + j_max );
}