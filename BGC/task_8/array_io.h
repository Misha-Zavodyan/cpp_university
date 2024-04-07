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

double f(int k,int n,int m,int i,int j);
int init_matrix(double *a,int n,int m,int k);
void print_matrix(double *a,int n,int m, int p);
int read_matrix(double *a,int n,int m, char * name);
double r(double *a,double *x,int n);
double matrix_norm(double *a,int n);
int choleski_location(double *a,double *d,int n,double epsilon);
int gaussian_method(double *a,double *x,int n,double epsilon);
int matrix_mult(double *a,double *d,int n);

int solution_1(double *a,double *x,int n,double *d);

#endif  