 #include "array_io.h"

int init_matrix(double *a,int n,int m,int k)
{
  int i,j,shift;
  shift=0;
  double *q;
  for(i=0;i<n;i++)
  {
    q=a+i*m-i-shift;
    for(j=i;j<m;j++)
      q[j]=f(k,n,m,i+1,j+1);//+1 to trasfer from inf to math
    shift+=i;
  }
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
  int i,j,shift,tmp;
  double *q;
  shift=0;
  for(i=0;i<np;i++)
  {
    tmp=i;
    q=a+i*m-i-shift;
    for(j=0;j<i;j++)
    {
      printf(" %10.3e",a[tmp]);
      tmp+=(m-j-1);
    }
    for(j=i;j<mp;j++)
      printf(" %10.3e",q[j]);
    printf("\n");
    shift+=i;
  }
}

int read_matrix(double *a,int n,int m, char * name)
{
  FILE * fp;
  int i,j,shift;
  double tmp;
  shift=0;
  if (!(fp=fopen(name,"r"))) 
    return ERROR_OPEN;
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      if(fscanf(fp,"%lf",&tmp)!=1)
      {
        fclose(fp);
        return ERROR_READ;
      }
      if(j>=i)
      {
        a[i*m+j-i-shift]=tmp;
      }
    }
    shift+=i;
  }
  fclose(fp);
  return SUCCESS;
}



double r(double *a,double *x,int n,double *d)
{ //max(for col)||A*B-E|| (B=A^(-1))
  int i,j,k,shift,shift2,shift3,shiftx;
  double tmp,maxi;
  double *q,*b,*p,*x1,*a1;
  maxi=-1;
  for(i=0;i<n;i++)d[i]=0;
  if(n<=4000)
  {
    shift=0;
    for(i=0;i<n;i++)
    {
      q=a+i*(n-1)-shift;
      shift2=n-i;
      b=x+i*(n-1)-shift;
      shiftx=0;

      for(j=0;j<n;j++)
      {
        tmp=0;
        x1=x+j*(n-1)-shiftx+j;
        a1=a+j*(n-1)-shiftx+j+i-j;
        if(j<i)
        {
          shift3=0;
          for(k=0;k<j;k++)
          {
            shift3+=n-j+k;
            tmp+=x1[-shift3]*a1[-shift3];
          }
          shift3=0;
          x1-=j;
          for(k=j;k<i;k++)
          {
            tmp+=x1[k]*a1[shift3];
            shift3+=n-k-1;
          }
          
          for(k=i;k<n;k++)
          { 
            tmp+=x1[k]*q[k];
          }
          x1+=j;
        }
        else
        {
          p=x+i*(n-1)-shift+j;
          q+=i;
          
          shift3=0;
          for(k=0;k<i;k++)
          {
            shift3+=n-i+k;
            tmp+=q[-shift3]*p[-shift3];
          }
          shift3=0;
          q-=i;
          for(k=i;k<j;k++)
          {
            tmp+=q[k]*p[shift3];
            shift3+=n-k-1;
          }
          for(k=j;k<n;k++)
          { 
            tmp+=q[k]*b[k];
          }
          shift2-=1;
          b+=shift2;
        } 
        // printf(" %f",tmp);
        if(j==i)
          tmp-=1;
        d[j]+=fabs(tmp);
        shiftx+=j;
      }
      // printf("\n");
      shift+=i;
    }
    for(i=0;i<n;i++)
    {
      if(d[i]>maxi)
      maxi=d[i];
    }
    return maxi;
  }
  else
    return 0;
}

double matrix_norm(double *a,int n)
{ //max sum for row
  int i,j,tmp,shift;
  double summ,max_summ;
  double *q;
  max_summ=-1;
  shift=tmp=0;
  for(i=0;i<n;i++)
  {
    tmp=i;
    q=a+i*n-i-shift;
    summ=0;

    for(j=0;j<i;j++)
    {
      summ+=fabs(a[tmp]);
      tmp+=(n-j-1);
    }
    for(j=i;j<n;j++)
      summ+=fabs(q[j]);

    if(summ>max_summ)
      max_summ=summ;
    shift+=i;
  }
  return max_summ;
}

int choleski_location(double *a,double *d,int n,double epsilon)
{
  int i,j,k,shift,shift2,step;
  double tmp,r_ii,d_i;
  double *q,*p,*b;
  shift=0;
  for(i=0;i<n;i++)
  {
    q=a+i*(n-1)-shift;
    //search for diagonal elements
    r_ii=q[i];
    p=a+i; 
    shift2=0;
    for(k=0;k<(i);k++) //tak lushe rabotaet hz poch
    {
      step=k*(n-1)-shift2;
      r_ii-=d[k]*p[step]*p[step];
      shift2+=k;
    }     
    (r_ii<epsilon) ? (d[i]=-1) : (d[i]=1);
    //r_ii=fabs(r_ii);
    // r_ii=sqrt(r_ii);
    // q[i]=r_ii;
    if(fabs(r_ii)<epsilon)//убрвть fabs 
      return -1;

    //search for elements of the upper triangle
    d_i=d[i];
    for(j=i+1;j<n;j++)
    {
      tmp=q[j];
      b=a+j;
      for(k=0,step=0;k<i;k++,step+=(n-1))
      {
        tmp-=d[k]*p[step]*b[step];
        step-=k;
      }
      tmp/=(d_i*sqrt(r_ii));//mb a=1./d[i]*r_ii?
      q[j]=tmp;
      
    }
    r_ii=fabs(r_ii);
    r_ii=sqrt(r_ii);
    q[i]=r_ii;
    shift+=i;
  }
  return SUCCESS;
}

int gaussian_method(double *a,double *x,int n,double epsilon)
{
  int i,j,k,shift,shift2;
  double *q;
  double *y;
  shift=0;
  for(i=0;i<n;i++)
  {
    q=a+i*(n-1)-shift;
    y=x+i*(n-1)-shift;
    if(q[i]<epsilon)
      return -1;
    y[i]=1./q[i];

    shift2=i;
    for(k=i;k>0;k--)
    {
      shift2-=(n-k);
      y[shift2]/=q[i];
    }

    for(j=i+1;j<n;j++)
    {
      y[j]=-q[j]/q[i];
      shift2=j;
      for(k=i;k>0;k--)
      {
        shift2-=(n-k);
        y[shift2]-=y[-j+i+shift2]*q[j];
      }
    }
    shift+=i;
  }

  return SUCCESS;
}

int matrix_mult(double *a,double *d,int n)
{
  int i,j,k,shift,shift2;
  double tmp;
  double *q,*b;
  shift=0;
  for(i=0;i<n;i++)
  {
    q=a+i*(n-1)-shift;
    shift2=n-i;
    b=q;
    for(j=i;j<n;j++)
    {
      tmp=0;
      for(k=j;k<n;k++)
      {
        tmp+=d[k]*q[k]*b[k];
      }
      shift2-=1;
      b+=shift2;
      
      q[j]=tmp;  
    }
    shift+=i;
  }
  return SUCCESS;
}

int solution_1(double *a,double *x,int n,double *d)
{
  int res;
  double norm,epsilon;
  norm=matrix_norm(a,n);
  epsilon=eps*norm;
  res= choleski_location(a,d,n,epsilon);
  if(res==-1)
    return -1;
  res= gaussian_method(a,x,n,epsilon);
  if(res==-1)
    return -1;
  res=matrix_mult(x,d,n);

  return 1;
}
