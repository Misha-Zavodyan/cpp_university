#include "find_root_io.h"
#include "funk_io.h"

static int count=0;

double f_1(double x)
{
  (void)x;
  count++;
  return 1;
}
double f_2(double x)
{
  count++;
  return 1+x;
}
double f_3(double x)
{
  count++;
  double x_2;
  x_2=x*x;
  return 1+x+x_2;
}
double f_4(double x)
{
  count++;
  double x_2;
  x_2=x*x;
  return 1+x+x_2+x*x_2;
}
double f_5(double x)
{
  count++;
  double x_2;
  x_2=x*x;
  return 1+x+x_2+x_2*x+x_2*x_2;
}
double f_6(double x)
{
  count++;
  return exp(-x);
}
double f_7(double x)
{
  count++;
  double x_2;
  x_2=x*x;
  return 1./(25*x_2+1);    
}

int return_count(void)
{
  return count;
}