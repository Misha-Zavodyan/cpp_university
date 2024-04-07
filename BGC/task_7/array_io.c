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

void mult_by_vector(double *a,double *x,double *res,int n)
{
  int i,j;
  double *q;
  double summ;

  for(i=0;i<n;i++)
  {
    summ=0;
    q=a+i*n;
    for(j=0;j<n;j++)
    {
      summ+=q[j]*x[j];
    }
    res[i]=summ;
  }
}

void D_1_by_vector(double *a,double *x,int n)
{
  int i;

  for(i=0;i<n;i++)
  {
    x[i]/=(a[i*n+i]);
  }
}
void D_by_vector(double *a,double *x,int n)
{
  int i;

  for(i=0;i<n;i++)
  {
    x[i]*=(a[i*n+i]);
  }
}

double scalar_product(double *a,double *b,int n)
{
  int j;
  double summ;
  summ=0;
  for(j=0;j<n;j++)
  {
    summ+=a[j]*b[j];
  }
  return summ;
}

double r(double *a,double *x,int n, double r1)
{
  int j,i;
  double summ,sub_summ,main_summ,tmp;
  double *q;

  sub_summ=0;
  main_summ=0;
  for(i=0;i<n;i++)
  {
    summ=0;
    q=a+i*n;
    for(j=0;j<n;j++)
    {
      summ+=q[j]*x[j];
    }
    tmp=x[i]*r1;
    sub_summ+=fabs(tmp);
    summ-=tmp;
    main_summ+=fabs(summ);
  }

  return(main_summ/sub_summ);
}

double r_1(double *a,double *x,double* b,int n)
{
  int j,i;
  double summ,sub_summ,main_summ,tmp;
  double *q;

  sub_summ=0;
  main_summ=0;
  for(i=0;i<n;i++)
  {
    summ=0;
    q=a+i*n;
    for(j=0;j<n;j++)
    {
      summ+=q[j]*x[j];
    }
    tmp=b[i];
    summ-=tmp;
    main_summ+=fabs(summ);
    sub_summ+=fabs(tmp);
  }
  return(main_summ/sub_summ);
}

double r_2(double *x,int n)
{
  int i;
  double summ;
  summ=0;

  for(i=0;i<n;i++)
  {
    summ+=fabs(x[i]-((i+1)&1));
  }
  return summ;
}

void b_init(double *a,double *b,int n)
{
  int i,k,m;
  double summ;
  double *q;

  m=(n-1)/2;//(n-1)/2;
  for(i=0;i<n;i++)
  {
    q=a+i*n;
    summ=0;
    for(k=0;k<=m;k++)
    {
      summ+=q[2*k];
    }
    b[i]=summ;
  }
}

double solution_1(double *a,double *x0,double *x,int n, int m)
{
  int k,i;
  double lam;


  for(i=0;i<n;i++)
  {
    x[i]=x0[i];
  }

  for(k=0;k<(m-1);k++)
  {
    if(k&1)
      mult_by_vector(a,x0,x,n);
    else
      mult_by_vector(a,x,x0,n);
  }
  if(!(k&1))
    for(i=0;i<n;i++)
        x0[i]=x[i];
  mult_by_vector(a,x0,x,n);

  lam= scalar_product(x,x0,n)/scalar_product(x0,x0,n);
  return lam;
}

void solution_2(double *a,double *x0,double *b,
double *x,int n, int m,double tau)
{
  int k,i,j;
  double summ;
  double *q;

  for(j=0;j<n;j++)
  {
    x[j]=x0[j];
  }

  for(k=0;k<m;k++)
  {   
    for(i=0;i<n;i++)
    {
      summ=0;
      q=a+i*n;
      for(j=0;j<n;j++)
      {
        summ+=q[j]*x[j];
      }
      x0[i]=(summ-b[i])*tau;
    }

    for(j=0;j<n;j++)
    {
      x[j]-=x0[j];
    }
  }
}

void solution_3(double *a,double *x0,double *b,
double *x,double *r,int n, int m)
{
  int k,j;
  double tau;

  //x=x_0 x0=r_0
  for(j=0;j<n;j++)
  {
    x[j]=x0[j];
  }
  mult_by_vector(a,x,r,n);
  for(j=0;j<n;j++)
  {
    r[j]-=b[j];
  }

  for(k=0;k<m;k++)
  {   
    mult_by_vector(a,r,x0,n);
    tau=scalar_product(r,r,n)/scalar_product(x0,r,n);

    for(j=0;j<n;j++)
    {
      x[j]-=r[j]*tau;
    }

    for(j=0;j<n;j++)
    {
      r[j]-=x0[j]*tau;
    }
  }
}

void solution_4(double *a,double *x0,double *b,
double *x,double *r,int n, int m)
{
  int k,j;
  double tau;

  //x=x_0 x0=r_0
  for(j=0;j<n;j++)
  {
    x[j]=x0[j];
  }
  mult_by_vector(a,x,r,n);
  for(j=0;j<n;j++)
  {
    r[j]-=b[j];
  }

  for(k=0;k<m;k++)
  {   
    mult_by_vector(a,r,x0,n);
    tau=scalar_product(x0,r,n)/scalar_product(x0,x0,n);

    for(j=0;j<n;j++)
    {
      x[j]-=r[j]*tau;
    }

    for(j=0;j<n;j++)
    {
      r[j]-=x0[j]*tau;
    }
  }
}

void solution_5(double *a,double *x0,double *b,
double *x,double *r,int n, int m)
{
  int k,j;
  double tau;

  //x=x_0 x0=r_0
  for(j=0;j<n;j++)
  {
    x[j]=x0[j];
  }

  mult_by_vector(a,x,r,n);
  for(j=0;j<n;j++)
  {
    r[j]-=b[j];
  }
  

  for(k=0;k<m;k++)
  { 
    for(j=0;j<n;j++)
    {
      b[j]=r[j];
    }
    D_1_by_vector(a,b,n);  
    mult_by_vector(a,b,x0,n);
    tau=scalar_product(b,r,n)/scalar_product(x0,b,n);

    for(j=0;j<n;j++)
    {
      x[j]-=b[j]*tau;
    }

    for(j=0;j<n;j++)
    {
      r[j]-=x0[j]*tau;
    }
  }
}

void solution_6(double *a,double *x0,double *b,
double *x,double *r,int n, int m)
{
  int k,j;
  double tau;

  //x=x_0 x0=r_0
  for(j=0;j<n;j++)
  {
    x[j]=x0[j];
  }

  mult_by_vector(a,x,r,n);
  for(j=0;j<n;j++)
  {
    r[j]-=b[j];
  }
  

  for(k=0;k<m;k++)
  { 
    for(j=0;j<n;j++)
    {
      b[j]=r[j];
    }
    D_1_by_vector(a,b,n);  
    mult_by_vector(a,b,x0,n);
    tau=scalar_product(x0,r,n)/scalar_product(x0,x0,n);

    for(j=0;j<n;j++)
    {
      x[j]-=b[j]*tau;
    }

    for(j=0;j<n;j++)
    {
      r[j]-=x0[j]*tau;
    }
  }
}

void solution_7(double *a,double *x0,double *b,
double *x,double *r,int n, int m,double tau)
{
  int k,j;

  //x=x_0 x0=r_0
  for(j=0;j<n;j++)
  {
    x[j]=x0[j];
  }

  mult_by_vector(a,x,r,n);
  for(j=0;j<n;j++)
  {
    r[j]-=b[j];
  }

  for(k=0;k<m;k++)
  { 
    D_1_by_vector(a,r,n);  
    mult_by_vector(a,r,x0,n);

    for(j=0;j<n;j++)
    {
      x[j]-=r[j]*tau;
    }
    D_by_vector(a,r,n);
    for(j=0;j<n;j++)
    {
      r[j]-=x0[j]*tau;
    }
  }
}

/*
сегодня мы сомтриели сойдеться ли Ax*=b x_k->x*
Сегодня итерационый метод
R1(x) R2(x)

1) НЕВЗЯКА 
||Ax-b||/||x||
2) погрешность
||x-x*||/||x*||
Точный метод

Ax*=b
можно посяитаь невязкуи ошибку

1) метод гауса:
a11 a12 ... a1n
a21 a22 ... a2n
.
.
an1     ... ann

Если а11=0, то Гаус не пременим
а11<eps||A|| //na eps ne rabotaet
Если пременим то :
a11/a11 a12/a11 ... a1n/a11 (a11/a11 можно просто как 1 срауз записать)
в гилберте в обращение матрици не работает в системе работает

потом обратный ход метода гауса


2) найти обратную матрицу
a11 a12 ... a1n 1 0 ... 0
a21 a22 ... a2n 0 1 ... 0
.
.
an1     ... ann 0 0 ... 1
матрици отдельные

3)
возмем 2 матрицы
и построить A=LV
aij=sum(lik*ukj)
a1j=sum(1:min(1;j))(lik*ukj)=l11*u1j
ai1sum(1:min(i;1))(lik*ukj)=l1i1*u11

4) Обратная разложением


5) симитричная матрица: A=R^tDR(D на диаганали +-1)


7) метод Гауса-Жордана
1)=1)Гуса

8) обратня Жорданом







для 12х12 невзяка <100%
*/
