#ifndef LEN
#define LEN 1234
#define eps 2.20e-16
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include <math.h>

enum io_status
{
ERROR_OPEN = -5,
ERROR_ARGUMENT,
ERROR_MEMORY,
ERROR_READ,
ERROR_UNKNOWN,
SUCCESS
};

int read_array(double *x,double *y,int n, char * name);
int read_array4(double *x,double *y,double *d,int n, char * name);
double solution_1(double x0,int n,double *x,double *y);
double solution_2(double x0,int n,double *x,double *y);
double solution_3(double x0,int n,double *x,double *y);
double solution_4(double x0,int n,double *x,double *y,double *d);
double sin_tylor(double x0,double epsilon);
double cos_tylor(double x0,double epsilon);
double solution_5(double x0,double epsilon);
double solution_6(double x0,double epsilon);
double solution_7(double x0,double epsilon);
double solution_8(double x0,double epsilon);


#endif  