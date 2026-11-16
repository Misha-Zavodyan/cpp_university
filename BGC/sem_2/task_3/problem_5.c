#include "array_io.h"

int main(int argc,char *argv[])
{
  int (*f[])(const char *, const char *)={up_strcmp,down_strcmp,up_len,down_len};
  const int len=sizeof(f)/sizeof(f[0]);
  int (*cmp)(const char *,const char *);
  int c,n,p,ret,task,diff;
  double t;
  char *name;
  char **a;

  task=5;
  if(!(argc==5 && sscanf(argv[1],"%d",&c)==1 && sscanf(argv[2],"%d",&n)==1 && 
  sscanf(argv[3],"%d",&p)==1 && c > 0 && c <= len ))
  {
    printf("Usege: %s c n p name \n",argv[0]);
    return ERROR_ARGUMENT;
  }
  name = argv[4];
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
  sort5(a,n,cmp);
  t=(clock()-t);
  diff = check(a,n,cmp);
  printf ("New array:\n");
  print_array (a, n, p); /* вывод нового состояния массива a */
  printf ("%s : Task = %d Diff = %d Elapsed = %.2f\n",argv[0], task, diff, t);
  delete_array(a,n);
  free(a);
  return SUCCESS;
}