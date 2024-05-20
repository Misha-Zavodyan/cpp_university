#include "find_root_io.h"

int main(int argc,char *argv[])
{
  int task,p,ret,len;
  double t;
  char *name;
  node *my_list;

  task=9;
  if(!(argc==3 && sscanf(argv[1],"%d",&p)==1 && p>=0))
  {
    printf("Usege: %s p name \n",argv[0]);
    return ERROR_ARGUMENT;
  }
  name = argv[2];

  ret=read_list(name, &my_list);
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
    return ret;
  }

  print_list(my_list, p);

  t=clock();
  my_list=function_9(my_list);
  t=(clock()-t)/CLOCKS_PER_SEC;
  print_list(my_list, p);
  len=get_length(my_list);
  
  printf ("%s : Task = %d Length = %d Elapsed = %.2f\n",argv[0], task, len, t);
  delet_list(my_list);
  return SUCCESS;
}