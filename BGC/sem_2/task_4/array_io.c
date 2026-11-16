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

double solution_1(double *a,int n)
{
  int i,j;
  for(i=0;i<n;i++)
    for(j=0;j<i;j++)
      if(fabs(a[i*n+j]-a[j*n+i])>eps*(fabs(a[i*n+j])-fabs(a[j*n+i])))
        return 0;
  return 1;
}

double solution_2(double *a,int n)
{
  int i;
  double res;
  res=0;
  for(i=0;i<n;i++)
    res+=a[i*n+i];
  return res;
}

void solution_3(double *a,int n)
{
  int i,j;
  double tmp;
  for(i=0;i<n;i++)
    for(j=0;j<i;j++)
      //if(fabs(a[i*n+j]-a[j*n+i])>eps*(fabs(a[i*n+j])-fabs(a[j*n+i])))
      {              //mb tut if sdelat; ne on zamelyaet daze na simitrichnoi
        tmp=a[i*n+j];
        a[i*n+j]=a[j*n+i];
        a[j*n+i]=tmp;
      }
}

void solution_4(double *a,int n)
{
  int i,j;
  for(i=0;i<n;i++)
    for(j=0;j<i;j++)
    {                 
      a[i*n+j]=(a[i*n+j]+a[j*n+i])/2.;//тут нужно не делить на 2, а умножать на 0.5, так быстрее.
      a[j*n+i]=a[i*n+j];//тут 5 обращений к памяти, а можно 4(ну тип перменную ввести)
      // тут компилятор сам правит, если бы была прогу чуть лсожнее, то не смог бы
      // т.к. a[i*n+j] между первой и второй строчкой поменялся бы.
      // тут все в одну строчку решалось бы черз множкственное присваевание.
      // a[j*n+i]=a[i*n+j]=(a[i*n+j]+a[j*n+i])*0.5;
      // читать хуже, но чем сложнее формула, тем болше компилятор может нашаманить 
      //и тем в теории будет быстрее работать
    }
}

void solution_5(double *a,int n)
{
  int i,j;
  for(i=0;i<n;i++)
    for(j=0;j<i;j++)
    {                 
      a[i*n+j]=(a[i*n+j]-a[j*n+i])/2.;
      a[j*n+i]=-1*a[i*n+j];//можно было -(a[i*n+j]) унарная видимо быстрее
    }
  for(i=0;i<n;i++)//тут цикл не нужен, так было бы быстрее.
    a[i*n+i]=0;// т.к. процесор быстрее работае с продряд иддущими элементами
    //(т.к. обращаеться к памяти ну по эти словам там или как там они)
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
  q=a+i;
  p=a+j;
  for(k=0;k<n;k++)
  {
    tmp=q[k*m];
    q[k*m]=p[k*m];
    p[k*m]=tmp;
  }  
}

void solution_8(double *a,int n,int m,int i,int j,double c)
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

void solution_9(double *a,double *b,double *c,int n,int m)
{ //b=m*1
  int i,j;
  double *q,summ;

  for(i=0;i<n;i++)
  {
    summ=0;
    q=a+i*m;
    for(j=0;j<m;j++)
    {
      summ+=q[j]*b[j];// короче тут я все верно сделал, т.к. сумма в регистри и работает быстрее
    }
    c[i]=summ;
//мой алгоритм рабоает за 2nm+n обращений к памяти, а если без summ(как в 10), то за 4mm

/*
 +-* -2 такта
 / 30-100 такотов
  обращенрие к памяти 100-200

  компелятор видит что s локальная пременная и 
  что она живет только в этой функции
  Он не может заменить c[i] на s, т.к. он боитьсячто c иожет
  измениться(указывать на а или b)


*/
  }  
}

void solution_10(double *a,double *b,double *c,int n,int m,int k)
{ 
  int i,j,l;
  double *q,*p,*d;

  for(i=0;i<n;i++)
  {
    q=a+i*m;
    d=c+i*n;
    for(j=0;j<k;j++)
    {
      d[j]=0;// тут нужно было дкелать черз summ тогда вместо 4х обращений было бы 2
      p=b+j;
      for(l=0;l<m;l++)
      {
        d[j]+=q[l]*(p[l*k]);
      }
    }
  }  
}

/*
1) Эфективность
2) Память

норма ||.||: R^n->R
1)||x||=0 <=> x=0
2) ||a*x||=|a|*||x||
3) ||x+y||<=||x||+||y||

Для матриц
A э Mn(R)
1) ||A||=0 <=>  A=0
2) ||aA||=|a|*||A||
3) ||A+B|| <= ||A||+||B||
4) ||A*B|| <= ||A||*||B||

||A||=max(||Ax||/||x||)


Если Ax*=b - точное решение
то x будет приближоным решение если ||x-x*||
||Ax-b|| еорма невязки.



*/
