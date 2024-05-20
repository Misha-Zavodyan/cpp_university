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

double r(double *a,double *x,int n)
{ //max(for col)||A*B-E|| (B=A^(-1))
  int i,j,k;
  double tmp,max_col,sum_col;
  double *q,*b,*x1,*a1;

  max_col=-1;
  sum_col=0;
  // for(i=0;i<n;i++)
  //   d[i]=0;
  if(n<=4000)
  {
    for(i=0;i<n;i++)
    {
      q=a+i*n+i;
      b=x+i*n+i;

      sum_col=0;
      for(j=0;j<n;j++)
      {
        tmp=0;
        x1=x+j*n+j;
        a1=a+j*n+j;
        if(j<i)
        {
          for(k=0;k<j;k++)
          {
            tmp+=x1[-n*(k+1)]*a1[-n*(k+1)+i-j];
          }
          for(k=j;k<i;k++)
          {
            tmp+=x1[k-j]*a1[n*(k-j)+i-j];
          }
          
          for(k=i;k<n;k++)
          { 
            tmp+=x1[k-j]*q[k-i];
          }

        }
        else
        {
          for(k=0;k<i;k++)
          {
            tmp+=b[-n*(k+1)+j-i]*q[-n*(k+1)];
          }
          for(k=i;k<j;k++)
          {
            tmp+=q[k-i]*b[n*(k-i)+j-i];
          }
          
          for(k=j;k<n;k++)
          { 
            tmp+=x1[k-j]*q[k-i];
          }
        } 
        if(j==i)
          tmp-=1;
        // printf("%d %d %.16f \n",i,j,tmp);
        sum_col+=fabs(tmp);
      }
      if(sum_col>max_col)
        max_col=sum_col;
      // printf("\n");
    }

    return max_col;
  }
  else
    return 0;
}

double matrix_norm(double *a,int n)
{ //max sum for row
  int i,j;
  double summ,max_summ;
  double *q;
  max_summ=-1;
  for(i=0;i<n;i++)
  {
    q=a+i*n;
    summ=0;

    for(j=0;j<i;j++)
    {
      summ+=fabs(a[i+n*j]);
    }
    for(j=i;j<n;j++)
      summ+=fabs(q[j]);

    if(summ>max_summ)
      max_summ=summ;
  }
  return max_summ;
}

// int choleski_location (double *a, double *d, int n,double epsilon)
// {
//   int i,j,k;
//   double r_ii,r_ij,d_ii;
//   double *q = a;
//   double *b;
//   (void)d;
//   (void)d_ii;
//   for (i = 0; i < n; i++)
//     {
//       r_ii = q[i];
//       for (k = 0, b =  a; k < i; k++, b +=  n)
//         r_ii -= b[i] * b[i] ;
//       // if (r_ii < 0)
//       //   d_ii = d[i] = -1;
//       // else
//       //   d_ii = d[i] = 1;
//       if (fabs (r_ii) < epsilon)
//         return -1;
//       q[i] = r_ii = sqrt (fabs (r_ii));
//       for (j = i + 1; j < n; j++)
//         {
//           r_ij = q[j];
//           for (k = 0, b =  a; k < i; k++, b +=  n)
//             {
//               r_ij -= b[i] * b[j];
//             }
//           q[j] = r_ij / (r_ii );
//         }
//       q +=  n;
//     }
//   return 0;
// }


int choleski_location (double *a,double *x, double *d, int n,double epsilon)
{
  int i,j,k;
  double d_ii,r_ii,s;
  double *q=a,*b,*y=x;
  
  for (i = 0; i < n; i++) {
    s = q[i];
    for (k = 0; k < i ; k++) 
      s -= pow(q[k], 2)*d[k];
    if (s < 0)
      d_ii = d[i] = -1;
    else
      d_ii = d[i] = 1;
    if (fabs (s) < epsilon)
      return -1;
    r_ii=y[i]=q[i] = sqrt(fabs(s));

    for (j = i + 1,b=a+j*n; j < n; j++) {
      s = b[i];
      for (k = 0; k < i ; k++) 
        s -= q[k] * b[k]*d[k];
      y[j]=b[i] = s / r_ii*d_ii;
      b+=n;
    }
    q+=n;
    y+=n;
  }
  return 0;
}


void gaussian_method(double *a,double *x,int n)
{
  int i,j,k; 
  double r_ii,s;
  double *q,*y;

  for(i=n-1,q=a+i*n;i>=0;i--)
  {
    r_ii=q[i];//q добавить
    q[i]=x[i+i*n]=r_ii=1./r_ii;
    for(j=n-1,y=x+j*n;j>=i+1;j--)
    {
      s=0;
      for(k=i+1;k<=j;k++)
      {
        s+=q[k]*y[k]; 
      }
      q[j]=y[i]=-s*r_ii;
      y-=n;
    }
    q-=n;
  }
}

void matrix_mult(double *a,double *d,int n)
{
  int i,j,k;
  double tmp;
  double *q,*b;

  for(i=0;i<n;i++)
  {
    q=a+i*n;
    for(j=i;j<n;j++)
    {
      b=a+j*n;
      tmp=0;
      for(k=j;k<n;k++)
      {
        tmp+=q[k]*b[k]*d[k];
      }
      q[j]=tmp; 
    }
  }
}

// int solution_1(double *a,double *x,int n,double *d)
// {
//   int res;
//   double norm,epsilon,t;
//   t=clock();
//   norm=matrix_norm(a,n);
//   t=(clock()-t)/CLOCKS_PER_SEC;
//   printf("matrix_norm Elapsed = %.2f \n", t);
  
//   epsilon=eps*norm;
//   // (void)epsilon;
//   t=clock();
//   res= choleski_location(a,x,d,n,epsilon);
//   t=(clock()-t)/CLOCKS_PER_SEC;
//   printf("choleski_location Elapsed = %.2f \n", t);
//   // print_matrix(x,n,n,5);

//   if(res==-1)
//     return -1;

//   t=clock();
//   gaussian_method(x,a,n);
//   t=(clock()-t)/CLOCKS_PER_SEC;
//   printf("gaussian_method Elapsed = %.2f \n", t);
//   // print_matrix(x,n,n,5);
  
//   t=clock();
//   matrix_mult(x,d,n);
//   t=(clock()-t)/CLOCKS_PER_SEC;
//   printf("matrix_mult Elapsed = %.2f\n", t);
  

//   return 1;
// }

int solution_1(double *a,double *x,int n,double *d)
{
  int res;
  double norm,epsilon;

  norm=matrix_norm(a,n);
  epsilon=eps*norm;

  res= choleski_location(a,x,d,n,epsilon);
  if(res==-1)
    return -1;

  gaussian_method(x,a,n);

  matrix_mult(x,d,n);

  return 1;
}

/*

1,2,3 - приближение к производной
1) заданна х0 нужно высислить проиводную в ней
строица интерпаляционный многочлен 1ой степени в форме ньютона
ситаем произвоную
2) будем улучшать построим многочен второй степени х0 напишем инторпаляционный многочен в форме ньютона от точек (х0,х0+н,х0-н)
будем дифиренцировать О(н^2)
3) постороить вторую производную.
4)Интегралы f(x)dx (от а до b)
задаеться n b-a/n
Интегралы f(x)dx (от а до b) = сумме инегралов приблеженных
инегрируем линейную функцию
длинна отрезка одинакова н^2 /2 
см доску + сумма =сумма + функция в концах
количество вызово должнобыьб n+1 
квадратурные формулы как выислить инеграл зная значение в точчке.

5) считаем интеграл многочленом второй степени.
+f(x)x^3

8)авто выбор n 
формула трапеции S(n)=1/2h... 
S(2n) = 1/2*1/2 ... = 1/2S(n) + сумма
делаем пока |S(2n)-S(n)|<eps

	DO  I = 1, N
		A(I,I) = SQRT (A(I, I))
		DO  J = I+1, N
			A(J,I) = A(J,I)/A(I,I)
		END DO
		DO  K=I+1,N
			DO J = K, N
				A(J,K) = A(J,K) - A(J,I)*A(K,I)
			END DO	
		END DO
	END DO


  	DO  I = 1, N
		S = A(I,I)
		DO  IP=1, I-1
			S = S - DPROD(A(I,IP), A(I,IP))
		END DO
		A(I,I) = SQRT (S)
		DO  J = I+1, N
			S = A(J,I)
			DO  IP=1, I-1
				S = S - DPROD(A(I,IP), A(J,IP))
			END DO
			A(J,I) = S/A(I,I)
		END DO
	END DO

*/