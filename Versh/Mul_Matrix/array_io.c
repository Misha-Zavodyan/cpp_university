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
  int i,j,tmp;
  double *q;
  (void)tmp;
  for(i=0;i<np;i++)
  {
    tmp=i;
    q=a+i*m;
    for(j=0;j<i;j++)
    {
      
      printf(" %10.3e",a[tmp]);
      tmp+=m;
    }
    for(j=i;j<mp;j++)
    {
      printf(" %10.3e",q[j]);
    }
      
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


// double matrix_norm(double *a,int n)
// { //max sum for row
//   int i,j;
//   double summ,max_summ;
//   double *q;
//   max_summ=-1;
//   for(i=0;i<n;i++)
//   {
//     q=a+i*n;
//     summ=0;

//     for(j=0;j<i;j++)
//     {
//       summ+=fabs(a[i+n*j]);
//     }
//     for(j=i;j<n;j++)
//       summ+=fabs(q[j]);

//     if(summ>max_summ)
//       max_summ=summ;
//   }
//   return max_summ;
// }


void matrix_mult(double *a,double *b ,double *c,int n, int m)
{
  int i,j,k;
  double tmp;
  double *q,*d;

  double t;
  t=clock();

  for(i=0;i<n;i++)
  {
    q=a+i*n;
    for(j=i;j<n;j++)
    {
      d=b+j*n;
      tmp=0;
      for(k=j;k<n;k++)
      {
        tmp+=q[k]*d[k]*d[k];
      }
      q[j]=tmp; 
    }
  }

  t=(clock()-t)/CLOCKS_PER_SEC;
  printf("matrix_mult_naiv Elapsed = %.2f\n", t);
}