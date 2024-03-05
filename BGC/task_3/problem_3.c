#include "array_io.h"

int main(int argc,char *argv[])
{
  int (*f[])(const char *, const char *)={up_strcmp,down_strcmp,up_len,down_len};
  const int len=sizeof(f)/sizeof(f[0]);
  int (*cmp)(const char *,const char *);
  int c,n,p,ret,res,task;
  double t;
  char *name,*x;
  char **a;

  task=3;
  if(!(argc==6 && sscanf(argv[2],"%d",&c)==1 && sscanf(argv[3],"%d",&n)==1 && 
  sscanf(argv[4],"%d",&p)==1 && c > 0 && c <= len ))
  {
    printf("Usege: %s c n p name \n",argv[0]);
    return ERROR_ARGUMENT;
  }
  name = argv[5];
  x = argv[1];
  cmp = f[c-1];
  a =(char**)malloc(n*sizeof(char*));
  if (!a)
  {
    printf("not enough memory! \n");
    return ERROR_MEMORY;
  }
  ret=read_array(a,n,name);
  if (ret!=SUCCESS)
  {
    switch(ret)
    {
      case ERROR_READ:
        printf("Can't reade %s! \n",name);
        break;
      case ERROR_OPEN:
        printf("Can't open %s! \n",name);
        break;
      case ERROR_MEMORY:
        printf("not enough memory! \n");
        break;
      default:
        printf("Unknown error %d in file %s",ret,argv[0]);
    }
    free(a);
    return ret;
  }
  print_array(a,n,p);
  t=clock();
  res=sort3(a,x,n,cmp);
  t=(clock()-t);
  printf ("New array:\n");
  print_array (a, n, p); /* вывод нового состояния массива a */
  printf ("%s : Task = %d Res = %d Elapsed = %.2f\n",argv[0], task, res, t);
  delete_array(a,n);
  free(a);
  return SUCCESS;
}