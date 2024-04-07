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



double r(double *a,double *x,int n)
{ //max(for col)||A*B-E|| (B=A^(-1))
  int i,j,k,shift,shift2,shift3;
  double tmp;
  double *q,*b,*p;
  if(n<=4000)
  {
    shift=0;
    for(i=0;i<n;i++)
    {
      q=a+i*(n-1)-shift;
      shift2=n-i;
      //b=q;
      b=x+i*(n-1)-shift;
      for(j=0;j<n;j++)
      {
        tmp=0;
        //p=q+j;
        if(j<i)
        {
          p=x+i*(n-1)-shift+j;
          q+=i;
          //b+=j;
          
          shift3=0;
          for(k=0;k<i;k++)
          {
            shift3+=n-i+k;
            tmp+=q[-shift3]*p[-shift3];
            // printf("1 i:%d j:%d k:%d q:%d p:%d -s3:%d q[k]:%lf p[k]:%lf\n",i,j,k,i*(n-1)-shift+i,i*(n-1)-shift+j,-shift3,q[-shift3],p[-shift3]);
          }
          shift3=0;
          q-=i;
          for(k=i;k<j;k++)
          {
            
            tmp+=q[k]*p[shift3];
            // printf("2 i:%d j:%d k:%d q:%d p:%d s3:%d q[k]:%lf p[k]:%lf\n",i,j,k,i*(n-1)-shift,i*(n-1)-shift+j,shift3,q[k],p[shift3]);
            shift3+=n-k-1;
          }
          for(k=j;k<n;k++)
          { 
            tmp+=q[k]*b[k];
            //printf("3  i:%d j:%d k:%d q:%lf b:%lf q[k]:%lf b[k]:%lf\n",i,j,k,q[0],b[0],q[k],b[k]);
          }
          shift2-=1;
          b+=shift2;
          // //p=x+i*(n-1)-shift+j;
          // //y=a+j*(n-1)-shift+i;
          // //q+=i;
          // q+=j;
          // b+=i;
          
          // shift3=0;
          // for(k=0;k<j;k++)
          // {
          //   shift3+=n-i+k;
          //   tmp+=b[-shift3]*q[-shift3];
          //   printf("1 i:%d j:%d k:%d b:%d q:%d -s3:%d b[k]:%lf q[k]:%lf\n",i,j,k,
          //   i*(n-1)-shift+i,i*(n-1)-shift+i,-shift3,b[-shift3],y[-shift3]);
          // }
          // shift3=0;
          // // q-=i;
          // b-=i;
          // for(k=j;k<i;k++)
          // {
            
          //   tmp+=b[k]*y[shift3];
          //   printf("2 i:%d j:%d k:%d b:%d y:%d s3:%d b[k]:%lf y[k]:%lf\n",i,j,k,
          //   i*(n-1)-shift,j*(n-1)-shift+i,shift3,b[k],y[shift3]);
          //   shift3+=n-k-1;
          // }
          
          // for(k=i;k<n;k++)
          // { 
          //   tmp+=b[k]*q[k];
          //   printf("3  i:%d j:%d k:%d b:%lf q:%lf b[k]:%lf q[k]:%lf\n",i,j,k,
          //   q[0],b[0],b[k],q[k]);
          // }
          // shift2-=1;
          // b+=shift2;
        }
        else
        {
          // p=x+i*(n-1)-shift+j;
          // q+=i;
          // //b+=j;
          
          // shift3=0;
          // for(k=0;k<i;k++)
          // {
          //   shift3+=n-i+k;
          //   tmp+=q[-shift3]*p[-shift3];
          //   // printf("1 i:%d j:%d k:%d q:%d p:%d -s3:%d q[k]:%lf p[k]:%lf\n",i,j,k,i*(n-1)-shift+i,i*(n-1)-shift+j,-shift3,q[-shift3],p[-shift3]);
          // }
          // shift3=0;
          // q-=i;
          // for(k=i;k<j;k++)
          // {
            
          //   tmp+=q[k]*p[shift3];
          //   // printf("2 i:%d j:%d k:%d q:%d p:%d s3:%d q[k]:%lf p[k]:%lf\n",i,j,k,i*(n-1)-shift,i*(n-1)-shift+j,shift3,q[k],p[shift3]);
          //   shift3+=n-k-1;
          // }
          // for(k=j;k<n;k++)
          // { 
          //   tmp+=q[k]*b[k];
          //   //printf("3  i:%d j:%d k:%d q:%lf b:%lf q[k]:%lf b[k]:%lf\n",i,j,k,q[0],b[0],q[k],b[k]);
          // }
          // shift2-=1;
          // b+=shift2;
        }
        

          
        printf(" %f",tmp);
      }
      printf("\n");
      shift+=i;
    }
    return SUCCESS;
  }
  else
    return 0;
  // int i,j,l;
  // double *q,*p,summ,summ_col,max_summ_col;
  // if(n<=4000)
  // {
  //   max_summ_col=-1;
  //   for(i=0;i<n;i++)
  //   {
  //     p=b+i;
  //     summ_col=0;
  //     for(j=0;j<n;j++)
  //     {
  //       summ=0;
        
  //       q=a+j*n;
  //       for(l=0;l<n;l++)
  //       {
  //         summ+=q[l]*(p[l*n]);
  //       }
  //       summ_col+=fabs(summ);
  //     }
  //     summ_col=fabs(summ_col-1);
  //     if (summ_col>max_summ_col)
  //       max_summ_col=summ_col;
  //   }  
  //   return max_summ_col;
  // }
  // else
  //   return 0;
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
    r_ii=fabs(r_ii);
    r_ii=sqrt(r_ii);
    q[i]=r_ii;
    if(r_ii<epsilon)
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
      tmp/=(d_i*r_ii);//mb a=1./d[i]*r_ii?
      q[j]=tmp;
      
    }
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

// int matrix_mult(double *a,double *d,int n)
// {
//   int i,j,k,shift,step;
//   double tmp;
//   double *q,*p,*b;
//   shift=0;
//   for(i=0;i<n;i++)
//     shift+=i;
//   for(i=n;i>0;i--)
//   {
//     q=a+i*n-shift-1;
//     p=a+i-1; 
//     for(j=0;j<n-i+1;j++)
//     {
//       tmp=0;
//       b=a+(n-j-1);
//       printf("i:%d j:%d b:%d a:%d\n",i,j,(n-j-1),i*n-shift-1);
//       for(k=0,step=0;k<i;k++,step+=(n-1))
//       {
//         tmp+=d[k]*p[step]*b[step];
//         step-=k;
//       }
//       q[-j]=tmp;  
//     }
//     shift-=(i-1);
//   }
//   return SUCCESS;
// }

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
  //(void)x;
  res= gaussian_method(a,x,n,epsilon);
  if(res==-1)
    return -1;
  res=matrix_mult(x,d,n);

  return 1;
}