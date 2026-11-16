#ifndef LEN
#define LEN 1234
#define eps 2.20e-16
#include "funk_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include <math.h>

enum io_status
{

ERROR_ARGUMENT = -3,
ERROR_UNKNOWN,
ERROR_METHOD,
SUCCESS
};

int my_sgn(double x);


double solution_1(double (*f)( double),double x,double h);
double solution_2(double (*f)( double),double x,double h);
double solution_3(double (*f)( double),double x,double h);
double solution_4(double (*f)( double),double a,double b,int n);
double solution_5(double (*f)( double),double a,double b,int n);
double solution_6(double (*f)( double),double a,double b,int n);
double solution_7(double (*f)( double),double a,double b,int n);
double solution_8(double (*f)( double),double a,double b,double epsilon,int *nn);
double solution_9(double (*f)( double),double a,double b,double epsilon,int *nn);
double solution_10(double (*f)( double),double a,double *bb ,double epsilon);
double solution_11(double (*f)( double),double a,double *bb ,double epsilon);
int solution_12(double (*f)( double),double (*g)( double),double a,double b,double epsilon,double *r);



#endif  