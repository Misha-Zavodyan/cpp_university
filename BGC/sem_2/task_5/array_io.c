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

double solution_1(double *a,int n, int m)
{
  int i,j;
  double summ,max_summ;
  double *q;
  max_summ=-999;
  for(i=0;i<n;i++)
  {
  q=a+i*m;
  summ=0;
    for(j=0;j<m;j++)
      summ+=fabs(q[j]);
  if(summ>max_summ)
    max_summ=summ;
  }
  return max_summ;
}

double solution_2(double *a,int n, int m)
{
  int i,j;
  double summ,max_summ;
  double *q;
  max_summ=-999;
  for(j=0;j<m;j++)
  {
  q=a+j;
  summ=0;
    for(i=0;i<n;i++)
      summ+=fabs(q[i*m]);
  if(summ>max_summ)
    max_summ=summ;
  }
  return max_summ;
}

double solution_3(double *a,double *x,double *b,int n, int m)
{
  int i,j;
  double *q,summ,res;
  res=0;
  for(i=0;i<n;i++)
  {
    summ=0;
    q=a+i*m;
    for(j=0;j<m;j++)
    {
      summ+=q[j]*x[j];
    }
    res+=fabs(summ-b[i]);
  }
  return res;
}

double solution_4(double *a,double *x,double *b,int n, int m)
{
  int i,j;
  double *q,summ,res,r;
  res=0;
  r=0;
  for(i=0;i<n;i++)
  {
    summ=0;
    q=a+i*m;
    for(j=0;j<m;j++)
    {
      summ+=q[j]*x[j];
    }
    res=fabs(summ-b[i]);
    if(res>r)
      r=res;
  }
  return r;
}

double solution_5(double *a,double *b,int n,int m)
{ 
  int i,j,l;
  double *q,*p,summ,summ_row,max_summ_row;
  max_summ_row=-1;
  for(i=0;i<n;i++)
  {
    q=a+i*m;
    summ_row=0;
    for(j=0;j<n;j++)
    {
      summ=0;
      p=b+j;
      for(l=0;l<m;l++)
      {
        summ+=q[l]*(p[l*n]);
      }
      if(j==i)
        summ-=1;
      summ_row+=fabs(summ);
    }
    if (summ_row>max_summ_row)
      max_summ_row=summ_row;
  }  
  return max_summ_row;
}

double solution_6(double *a,double *b,int n,int m)
{ 
  int i,j,l;
  double *q,*p,summ,summ_col,max_summ_col;
  max_summ_col=-1;
  for(i=0;i<n;i++)
  {
    p=b+i;
    summ_col=0;
    for(j=0;j<n;j++)
    {
      summ=0;
      
      q=a+j*m;
      for(l=0;l<m;l++)
      {
        summ+=q[l]*(p[l*n]);
      }
      if(j==i)
        summ-=1;
      summ_col+=fabs(summ);
    }
    //summ_col=fabs(summ_col-1);
    if (summ_col>max_summ_col)
      max_summ_col=summ_col;
  }  
  return max_summ_col;
}


double solution_7(double *a,int n,int m)
{ 
  int i,j;
  double maxi,tmp;
  double *q;
  maxi=-1;
  for(j=0;j<m;j++)
  {
    tmp=fabs(a[j]);
    if(tmp>maxi)
    {
      maxi=tmp;
    }    
  }

  for(i=1;i<(n-1);i++)
  {
    q=a+m*i;
    tmp=q[0];
    if(fabs(tmp)>maxi)
    {
      maxi=fabs(tmp);
    }

    for(j=1;j<(m-1);j++)
    {
      tmp=q[j]=0.2*(tmp+q[j+1]+q[j+m]+q[j-m]);
      //tmp=fabs(q[j]);
      if(fabs(tmp)>maxi)
      {
        maxi=fabs(tmp);
      }   
    }
    tmp=fabs(q[m-1]);
    if(tmp>maxi)
    {
      maxi=tmp;
    }
  }

  q=a+m*(n-1);
  for(j=0;j<m;j++)
  {
    tmp=fabs(q[j]);
    if(tmp>maxi)
    {
      maxi=tmp;
    }   
  }

  return maxi;
}


double solution_8(double *a,int n,int m)
{ 
  int i,j;
  double maxi,tmp;
  double *q;
  maxi=-1;
  q=a+m*(n-1);
  for(j=(m-1);j>=0;j--)
  {
    tmp=fabs(q[j]);
    if(tmp>maxi)
    {
      maxi=tmp;
    }    
  }

  for(i=(n-2);i>=1;i--)
  {
    q=a+m*i;
    tmp=q[m-1];
    if(fabs(tmp)>maxi)
    {
      maxi=fabs(tmp);
    }

    for(j=(m-2);j>=1;j--)
    {
      tmp=q[j]=0.2*(tmp+q[j-1]+q[j+m]+q[j-m]);
      if(fabs(tmp)>maxi)
      {
        maxi=fabs(tmp);
      }   
    }
    tmp=fabs(q[0]);
    if(tmp>maxi)
    {
      maxi=tmp;
    }
  }

  for(j=(m-1);j>=0;j--)//mb tut norm cicl
  {
    tmp=fabs(a[j]);
    if(tmp>maxi)
    {
      maxi=tmp;
    }   
  }

  return maxi;
}

double solution_9(double *a,int n,int m)
{ 
  int i,j;
  double maxi,tmp;
  double *q;
  maxi=-1;
  q=a+m*(n-1);
  for(j=0;j<m;j++)
  {
    tmp=fabs(q[j]);
    if(tmp>maxi)
    {
      maxi=tmp;
    }    
  }

  for(i=(n-2);i>=1;i--)
  {
    q=a+m*i;
    tmp=q[0];
    if(fabs(tmp)>maxi)
    {
      maxi=fabs(tmp);
    }

    for(j=1;j<(m-1);j++)
    {
      tmp=q[j]=0.2*(tmp+q[j+1]+q[j+m]+q[j-m]);
      if(fabs(tmp)>maxi)
      {
        maxi=fabs(tmp);
      }   
    }
    tmp=fabs(q[m-1]);
    if(tmp>maxi)
    {
      maxi=tmp;
    }
  }

  for(j=0;j<m;j++)
  {
    tmp=fabs(a[j]);
    if(tmp>maxi)
    {
      maxi=tmp;
    }   
  }

  return maxi;
}


//rabotaet medlenie

/*
double solution_9(double *a,int n,int m)
{ 
  int i,j;
  double maxi,tmp;
  double *q,*p;
  maxi=-1;


  for(i=0;i<(n/2);i++)
  {
    q=a+m*i;
    p=a+m*(n-i-1);
    for(j=0;j<m;j++)
    {
      tmp=q[j]; 
      q[j]= p[j];
      p[j]=tmp;
    }
  }

  maxi=solution_7(a, n, m);


  return maxi;
}
*/

double solution_10(double *a,int n,int m)
{ 
  int i,j;
  double maxi,tmp;
  double *q;
  maxi=-1;
  
  for(j=(m-1);j>=0;j--)
  {
    tmp=fabs(a[j]);
    if(tmp>maxi)
    {
      maxi=tmp;
    }    
  }

  for(i=1;i<(n-1);i++)
  {
    q=a+m*i;
    tmp=q[m-1];
    if(fabs(tmp)>maxi)
    {
      maxi=fabs(tmp);
    }

    for(j=(m-2);j>=1;j--)
    {
      tmp=q[j]=0.2*(tmp+q[j-1]+q[j+m]+q[j-m]);
      // tmp=fabs(q[j]);
      if(fabs(tmp)>maxi)
      {
        maxi=fabs(tmp);
      }   
    }
    tmp=fabs(q[0]);
    if(tmp>maxi)
    {
      maxi=tmp;
    }
  }

  q=a+m*(n-1);
  for(j=(m-1);j>=0;j--)
  {
    tmp=fabs(q[j]);
    if(tmp>maxi)
    {
      maxi=tmp;
    }   
  }

  return maxi;
}

double solution_11(double *a,int n,int m)
{ 
  int i,j,max_i,max_j;
  double maxi,tmp;
  double *q;
  maxi=-1;
  max_i=max_j=0;
  for(i=0;i<n;i++)
  {
    q=a+i*m;
    for(j=0;j<m;j++)
    {
      tmp=fabs(q[j]);
      if(tmp>maxi)
      {
        maxi=tmp;
        max_i=i;
        max_j=j;
      }  
    }
  }

  if(max_i)
  {
    q=a+max_i*m;
    for(j=0;j<m;j++)
    {
      tmp=q[j];
      q[j]=a[j];
      a[j]=tmp;
    }
  }

  if(max_j)
  {
    q=a+max_j;
    for(i=0;i<n;i++)
    {
      tmp=q[i*m];
      q[i*m]=a[i*m];
      a[i*m]=tmp;
    }
  }


  return maxi;
}