#include "find_root_io.h"
#include "funk_io.h"

static int count=0;

double f_1(double x)
{
  count++;
  return 1;
}
double f_2(double x)
{
  count++;
  return x-10e+100;
}
double f_3(double x)
{
  count++;
  double x_2;
  x_2=x*x;
  return 4-x_2;
}
double f_4(double x)
{
  count++;
  double x_2;
  x_2=x*x;
  return x*x_2+3*x_2+16;
}
double f_5(double x)
{
  count++;
  double x_2;
  x_2=x*x;
  return 3-2*x_2-x_2*x_2;
}
double f_6(double x)
{
  count++;
  return sqrt(fabs(x)+1)-2;
}
double f_7(double x)
{
  count++;
  return sqrt(sqrt(fabs(x)+1)+1)-2;    
}

int return_count(void)
{
  return count;
}