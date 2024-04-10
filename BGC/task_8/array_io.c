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
        // if(j==i)
        //   tmp-=1;
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
    return maxi-1;//так нельзя делать может
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
  double tmp,r_ii,d_i,tmp_1,ttt;
  double *q,*p,*b;
  shift=0;
  (void)shift;//tets speed vith shift
  q=a;
  for(i=0;i<n;i++)
  {
    //q=a+i*(n-1)-shift;
    
    //search for diagonal elements
    r_ii=q[i];
    p=a+i; 
    shift2=0;
    for(k=0;k<(i);k++) //tak lushe rabotaet hz poch
    {
      step=k*(n-1)-shift2;
      r_ii-=d[k]*p[step]*p[step];//mb убрать r_ii
      shift2+=k;
    }     
    (r_ii<epsilon) ? (d[i]=-1) : (d[i]=1);
    r_ii=fabs(r_ii);
    // r_ii=sqrt(r_ii);
    // q[i]=r_ii;
    if(r_ii<epsilon)//убрвть fabs 
      return -1;

    //search for elements of the upper triangle
    d_i=d[i];
    for(j=i+1;j<n;j++)
    {
      tmp=0;//mb убрать tmp
      b=a+j;
      for(k=0,step=0;k<i;k++,step+=(n-1))
      {
        tmp_1=p[step]*b[step]*d[k];
        tmp+=tmp_1;
        step-=k;
      }
      ttt=q[j]/(d_i*sqrt(r_ii));
      // q[j]/=(d_i*sqrt(r_ii));
       q[j]=ttt-tmp/(d_i*sqrt(r_ii));
      //tmp/=(d_i*sqrt(r_ii));//mb a=1./d[i]*r_ii?
      //q[j]=tmp;
      
    }
    q[i]=sqrt(r_ii);
    //shift+=i;
    q+=n-1-i;
  }
  return SUCCESS;
}

// int gaussian_method(double *a,double *x,int n,double epsilon)
// {// в начале приведем к 1 на диоганали а потом будем манипулировать.
//   int i,j,k,shift,shift2,additive; 
//   double *q;
//   double *y;
//   shift=0;
//   for(i=0;i<n;i++)
//   {
//     q=a+i*(n-1)-shift; // можно тут без shift mb меньше опреаций
//     y=x+i*(n-1)-shift;
//     if(q[i]<epsilon)
//       return -1;
//     y[i]=1./q[i];
//     shift2=i;
//     for(k=i;k>0;k--)
//     {
//       shift2-=(n-k);
//       q[shift2]/=q[i];
//     }

//     shift+=i;
//   }
//   shift=0;
//   for(i=0;i<n;i++)
//   {
//     q=a+i*(n-1)-shift; // можно тут без shift mb меньше опреаций
//     y=x+i*(n-1)-shift;
//     // if(q[i]<epsilon)
//     //   return -1;
//     // y[i]=1./q[i];

//     // shift2=i;
//     // for(k=i;k>0;k--)
//     // {
//     //   shift2-=(n-k);
//     //   y[shift2]/=q[i];
//     // }
//     for(j=i+1;j<n;j++)
//     {
//       y[j]=-q[j]/q[i];//mb tmp
//       shift2=j;
//       additive=-j+i;
//       for(k=i;k>0;k--)
//       {
//         shift2-=(n-k);
//         y[shift2]-=y[additive+shift2]*q[j];//mb tmp
//       }
//     }
//     shift+=i;
//   }

//   return SUCCESS;
// }

// int gaussian_method(double *a,double *x,int n,double epsilon)
// {// в начале приведем к 1 на диоганали а потом будем манипулировать.
//   int i,j,k,shift,shift2,additive,shift_j,shift_k; 
//   double *q;
//   double *y;
//   double r_jj,tmp,s;
//   shift=0;
//   for(i=0;i<n;i++)
//   {
//     q=a+i*(n-1)-shift; // можно тут без shift mb меньше опреаций
//     y=x+i*(n-1)-shift;
//     if(q[i]<epsilon)
//       return -1;
//     y[i]=1./q[i];
//     shift_j=n-i-1;
//     for(j=i+1;j<n;j++)
//     {
//       // printf("i:%d j:%d s_j:%d q_jj: %d\n",i,j,shift_j,(i*(n-1)-shift+j+shift_j));
//       r_jj=q[j+shift_j];
//       s=0;
//       shift_k=0;
//       for(k=i;k<j;k++)
//       {
//         // printf(" i:%d j:%d k:%d y_ik: %d q_kj: %d\n",i,j,k,i*(n-1)-shift+k,i*(n-1)-shift+shift_k+j);
//         tmp=-y[k]*q[shift_k+j];
//         s+=tmp/r_jj;
//         shift_k+=n-k-1;
//       }
//       // printf("  i:%d j:%d y_ij: %d\n",i,j,i*(n-1)-shift+j);
//       y[j]=s;
//       shift_j+=n-j-1;
//     }
//     shift+=i;
//   }
//   return SUCCESS;
// }



int gaussian_method(double *a,double *x,int n,double epsilon)
{// в начале приведем к 1 на диоганали а потом будем манипулировать.
  int i,j,k,shift,shift2,additive; 
  double *q;
  double *y;
  shift=0;
  for(i=0;i<n;i++)
  {
    q=a+i*(n-1)-shift; // можно тут без shift mb меньше опреаций
    y=x+i*(n-1)-shift;
    if(q[i]<epsilon)
      return -1;
    y[i]=1./q[i];
    for(j=i+1;j<n;j++)
    {
      y[j]=-q[j]/q[i]; // записывем вместо 0 -q[j]/q[i] это столбец под диаганальным элемнтом
      shift2=j;
      additive=-j+i;
      for(k=i;k>0;k--)
      {
        shift2-=(n-k);
        printf(" 2 y+s2:%d y+s2+a:%d\n",i*(n-1)-shift+shift2,i*(n-1)-shift+shift2+additive);
        y[shift2]-=y[additive+shift2]/q[i]*q[j]; // вычетаем из остальных столбцое строчку
      }
    }
    shift2=i; //деление всей строчки на q[i]
    for(k=i;k>0;k--)
    {
      shift2-=(n-k);
      printf("1 %d \n",i*(n-1)-shift+shift2);
      y[shift2]/=q[i];
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
    q=a+i*(n-1)-shift;// можно тут тожк шифт убрать
    shift2=n-i;
    b=q;
    for(j=i;j<n;j++)
    {
      tmp=0;
      for(k=j;k<n;k++)
      {
        tmp+=q[k]*b[k]*d[k];
      }
      q[j]=tmp;
      // printf(" %17f",tmp);
      shift2-=1;
      b+=shift2;  
    }
    // printf("\n-------------------------------------------\n");
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
  // //(void)x;
  // // printf("Chol mat \n");
  // // print_matrix(a,n,n,5);
  if(res==-1)
    return -1;
  res= gaussian_method(a,x,n,epsilon);
  if(res==-1)
    return -1;
  res=matrix_mult(x,d,n);

  return 1;
}
