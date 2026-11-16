#include "array_io.h"

int main(int argc,char *argv[])
{
  int (*f[])(const char *, const char *)={up_strcmp,down_strcmp,up_len,down_len};
  const int len=sizeof(f)/sizeof(f[0]);
  int (*cmp)(const char *,const char *);
  int c,n,m,p_a,p_b,ret,task,diff;
  double t;
  char *name_a,*name_b;
  char **a,**b,**c_arr;

  task=2;
  if(!(argc==8 && sscanf(argv[1],"%d",&c)==1 && sscanf(argv[2],"%d",&n)==1 && 
  sscanf(argv[3],"%d",&p_a)==1 && sscanf(argv[5],"%d",&m)==1 && 
  sscanf(argv[6],"%d",&p_b)==1 && c > 0 && c <= len ))
  {
    printf("Usege: %s c n p name \n",argv[0]);
    return ERROR_ARGUMENT;
  }
  name_a = argv[4];
  name_b = argv[7];
  cmp = f[c-1];
  a =(char**)malloc(n*sizeof(char*));
  if (!a)
  {
    printf("not enough memory! \n");
    return ERROR_MEMORY;
  }
  b =(char**)malloc(m*sizeof(char*));
  if (!b)
  {
    printf("not enough memory! \n");
    return ERROR_MEMORY;
  }
  c_arr =(char**)malloc((n+m)*sizeof(char*));
  if (!c_arr)
  {
    printf("not enough memory! \n");
    return ERROR_MEMORY;
  }

  ret=read_array(a,n,name_a);
  if (ret!=SUCCESS)
  {
    switch(ret)
    {
      case ERROR_READ:
        printf("Can't reade %s! \n",name_a);
        break;
      case ERROR_OPEN:
        printf("Can't open %s! \n",name_a);
        break;
      case ERROR_MEMORY:
        printf("not enough memory! \n");
        break;
      default:
        printf("Unknown error %d in file %s",ret,argv[0]);
    }
    free(a);
    free(b);
    free(c_arr);
    return ret;
  }

  ret=read_array(b,m,name_b);
  if (ret!=SUCCESS)
  {
    switch(ret)
    {
      case ERROR_READ:
        printf("Can't reade %s! \n",name_b);
        break;
      case ERROR_OPEN:
        printf("Can't open %s! \n",name_b);
        break;
      case ERROR_MEMORY:
        printf("not enough memory! \n");
        break;
      default:
        printf("Unknown error %d in file %s",ret,argv[0]);
    }
    free(a);
    free(b);
    free(c_arr);
    return ret;
  }


  print_array(a,n,p_a);
  printf("\n");
  print_array(b,m,p_b);
  printf("\n");
  t=clock();
  sort2(a,b,c_arr,n,m,cmp);
  t=(clock()-t);
  diff = check(c_arr,n+m,cmp);
  printf ("New array:\n");
  print_array (c_arr, n + m, p_a+p_b); /* вывод нового состояния массива c */
  printf ("%s : Task = %d Diff = %d Elapsed = %.2f\n",argv[0], task, diff, t);
  delete_array(c_arr,(n+m));
  free(a);
  free(b);
  free(c_arr);
  return SUCCESS;
}