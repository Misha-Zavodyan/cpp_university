#include "array_io.h"

int up_strcmp(const char *a ,const char *b)
{
  return strcmp(a,b) <= 0 ? 1 : 0;
}

int down_strcmp(const char *a, const char *b)
{
  return strcmp(a,b) > 0 ? 1 : 0;
}

int up_len(const char *a,const char *b)
{
  return strlen(a)<=strlen(b) ? 1 : 0; //xz zachem tyt ? 1 : 0
}

int down_len(const char *a, const char *b)
{
  return strlen(a) > strlen(b) ? 1 : 0;  
}

void delete_array(char *a[],int n)
{
  int i;
  for (i=0;i<n;i++)
    free(a[i]);
}

void print_array(char *a[],int n, int p)
{
  int m = (n < p ? n : p),i;
  for (i=0;i<m;i++)
    printf("%s\n",a[i]);
}

int read_array(char *a[],int n, char * name)
{
  char buf[LEN];
  FILE * fp;
  int i,j,k;
  fp=fopen(name,"r");
  if(!fp) return ERROR_OPEN;
  for (i=0;i<n;i++)
  {
    if(!fgets(buf,LEN,fp))
    {
      fclose(fp);
      //prochitano i shtyk
      delete_array(a,i);
      return ERROR_READ;
    }

    for(j=0;buf[j];j++)
    if(buf[j]=='\n') //&& ==0 ?
    {
      buf[j]=0;
      break;
    }

    a[i]=(char*)malloc(j+1);
    if(!a[i])
    {
      delete_array(a,i);
      fclose(fp);
      return ERROR_MEMORY;
    }

    for (k=0;k<=j;k++)
      a[i][k]=buf[k];
  }
  fclose(fp);
  return SUCCESS;
}

int check (char**a,int n, int (*cmp)(const char *, const char *))
{
  int i,count=0;
  for(i=1;i<n;i++)
    if(cmp(a[i-1],a[i])==0) count++;
  return count;
}

int sort1 (char**a,char * x,int n, int (*cmp)(const char *, const char *))
{
  int s,lbord=0,rbord=n;
  while (lbord < rbord) 
  {
    s = (lbord + rbord) / 2; 
    if (cmp(x,a[s])) rbord = s; 
    else lbord = s + 1;
  }
  return rbord;
}

void sort2 (char**a,char**b,char**c,int n,int m, int (*cmp)(const char *, const char *))
{
  int i,j,k;
  for( i = 0, j = 0, k = 0; k < n+m;)
    {
        if (i == n) c[k++] = b[j++];
        else if (j == m) c[k++] = a[i++];
        else if (cmp(a[i],b[j])) c[k++] = a[i++];
        else c[k++] = b[j++];
    }
}

int sort3 (char**a,char * x,int n, int (*cmp)(const char *, const char *))
{
  int i = 0, j = n-1;
  char* tmp;
  while (i < j)
  {
    if (cmp(a[i],x)) i++;
    else if (cmp(a[j],x))
    {
        tmp = a[i];
        a[i++] = a[j];
        a[j] = tmp;
    }
    else j--;
  }
  return j;
}

void sort4 (char**a,int n, int (*cmp)(const char *, const char *))
{
  int i,j,flag;
  char* tmp;
  for(i=0;i<n;i++)
  {
    flag=1;
    for(j=0;j<n-(i+1);j++)
    {
      if(cmp(a[j+1],a[j]))
      {
        flag=0;
        tmp=a[j];
        a[j]=a[j+1];
        a[j+1]=tmp;
      }
    }
    if (flag) break;
  }
}

void sort5 (char**a,int n, int (*cmp)(const char *, const char *))
{
  int i,j,min_index;
  char* tmp;
  for(i=0;i<n-1;i++)
  {
    min_index=i;
    for(j=i+1;j<n;j++)
    {
      if(cmp(a[j],a[min_index]))
      {
        min_index=j;
      }
    }
    if (min_index!=i)
    {
      tmp=a[i];
      a[i]=a[min_index];
      a[min_index]=tmp;
    }
  }
}

void sort6 (char**a,int n, int (*cmp)(const char *, const char *))
{
  int i,j;
  char * tmp;
  for(i=1;i<n;i++)
  {
    for(j=i;j>0 && cmp(a[j],a[j-1]);j--)
    {
      tmp=a[j-1];
      a[j-1]=a[j];
      a[j]=tmp;
    }
  }
}

void sort8 (char**a,char**b,int n, int (*cmp)(const char *, const char *))
{
  int i,j,endd;
  char **tmp;
  for (i=1;i<n;i*=2)
  {
    for(j=0;j<n-i;j+=2*i)
    {
      endd=((j + 2 * i) < n ? (j + 2 * i) : n);
      sort2(&(a[j]),&(a[j + i]),&(b[j]),  i, (endd-(j + i)), cmp);  
    }
    tmp=b;
    b=a;
    a=tmp;
  }
}