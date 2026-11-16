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

void matrix_mult_naiv(double *a,double *b,double *c,int n,int m,int k)
{ 
  int i,j,l;
  double summ;
  double *q,*p,*d;

  for(i=0;i<n;i++)
  {
    q=a+i*m;
    d=c+i*k;
    for(j=0;j<k;j++)
    {
      summ=0;
      p=b+j;
      for(l=0;l<m;l++)
      {
        summ+=q[l]*(p[l*k]);
      }
      d[j]=summ;
    }
  }  
}

void matrix_mult_block(double * a, double * b, double * c, int n, int m) {
	int i,j,l,k,bl,v,h,r,t,ah,s,q;
  double sum, s00, s01, s02, s10, s11, s12, s20, s21, s22;

	k = n / m; l = n - k * m; // n = k * m + l
	// Если поделилось нацело, то блоков k, иначе k + 1
	bl = (l != 0 ? k + 1 : k); // Самый вероятный случай рассматриваем
	for (i = 0; i < bl; i++) {
		for (j = 0; j < bl; j++) {
			// размер блока С -- v x h
			v = (i < k ? m : l); // vertical
			h = (j < k ? m : l); // horizontal
			// начало блока С
			double * pc = c + i * n * m + j * m;

			for (r = 0; r < v; r++){ // обнулять блок r x h Зачем?
				for (t = 0; t < h; t++) {
					pc[r * m + t] = 0;
				}
			}

			for (s = 0; s < bl; s++) {
				// C(v x h) += A(v x _) * B(_ x h), нужно найти _
				ah = (s < k ? m : l);
				double * pa = a + i * n * m + s * m; // Ais
				double * pb = b + s * n * m + j * m; // Bsj
				int v3 = v % 3;
				int h3 = h % 3;

				// напишем ту часть, что касается остатка
				for (r = 0; r < v3; r++){
					for (t = 0; t < h3; t++){
						sum = 0;
						for (q = 0; q < ah; q++){
							sum += pa[r * n + q] * pb[q * n + t];
						}
						pc[r * n + t] += sum;
					}
					for ( ; t < h; t += 3) {
						s00 = 0;
						s01 = 0;
						s02 = 0;
						for (q = 0; q < ah; q++) {
							s00 += pa[r * n + q] * pb[q * n + t];
							s01 += pa[r * n + q] * pb[q * n + t + 1];
							s02 += pa[r * n + q] * pb[q * n + t + 2];
						}
						pc[r * n + t] += s00;//+=?
						pc[r * n + t + 1] += s01;
						pc[r * n + t + 2] += s02;
					}
				}

				for (; r < v; r += 3) {
					for (t = 0; t < h3; t++){
						s00 = 0;
						s10 = 0;
						s20 = 0;
						for (q = 0; q < ah; q++) {
							s00 += pa[r * n + q] * pb[q * n + t];
							s10 += pa[(r + 1) * n + q] * pb[q * n + t];
							s00 += pa[(r + 2) * n + q] * pb[q * n + t];
						}
						pc[r * n + t] += s00;
						pc[(r + 1) * n + t] += s10;
						pc[(r + 2) * n + t] += s20;
					}
				
				// переходим к основному циклу
          for (; t < h; t += 3) {
            s00 = 0;
            s01 = 0;
            s02 = 0;
            s10 = 0;
            s11 = 0;
            s12 = 0;
            s20 = 0;
            s21 = 0;
            s22 = 0;
            for (q = 0; q < ah; q++) {
              s00 += pa[r * n + q] * pb[q * n + t];
              s01 += pa[r * n + q] * pb[q * n + t + 1];
              s02 += pa[r * n + q] * pb[q * n + t + 2];
              s10 += pa[(r + 1) * n + q] * pb[q * n + t];
              s11 += pa[(r + 1) * n + q] * pb[q * n + t + 1];
              s12 += pa[(r + 1) * n + q] * pb[q * n + t + 2];
              s20 += pa[(r + 2) * n + q] * pb[q * n + t];
              s21 += pa[(r + 2) * n + q] * pb[q * n + t + 1];
              s22 += pa[(r + 2) * n + q] * pb[q * n + t + 2];
            }
            pc[r * n + t] += s00;
            pc[r * n + t + 1] += s01;
            pc[r * n + t + 2] += s02;
            pc[(r + 1) * n + t] += s10;
            pc[(r + 1) * n + t + 1] += s11;
            pc[(r + 1) * n + t + 2] += s12;
            pc[(r + 2) * n + t] += s20;
            pc[(r + 2) * n + t + 1] += s21;
            pc[(r + 2) * n + t + 2] += s22;
          }
        }  
			} // s
		} // j
	} // i
} // func