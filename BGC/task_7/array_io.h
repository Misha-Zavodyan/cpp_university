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
void mult_by_vector(double *a,double *x,double *res,int n);
void D_by_vector(double *a,double *x,int n);
void D_1_by_vector(double *a,double *x,int n);
double scalar_product(double *a,double *b,int n);
double r(double *a,double *x,int n, double r1);
double r_1(double *a,double *x,double* b,int n);
double r_2(double *x,int n);
void b_init(double *a,double *b,int n);
double solution_1(double *a,double *x0,double *x,int n, int m);
void solution_2(double *a,double *x0,double *b,double *x,int n, int m,double tau);
void solution_3(double *a,double *x0,double *b,double *x,double *r,int n, int m);
void solution_4(double *a,double *x0,double *b,double *x,double *r,int n, int m);
void solution_5(double *a,double *x0,double *b,double *x,double *r,int n, int m);
void solution_6(double *a,double *x0,double *b,double *x,double *r,int n, int m);
void solution_7(double *a,double *x0,double *b,double *x,double *r,int n, int m,double tau);


#endif  