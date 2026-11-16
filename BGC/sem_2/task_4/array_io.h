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
double solution_1(double *a,int n);
double solution_2(double *a,int n);
void solution_3(double *a,int n);
void solution_4(double *a,int n);
void solution_5(double *a,int n);
void solution_6(double *a,int n,int m,int i,int j);
void solution_7(double *a,int n,int m,int i,int j);
void solution_8(double *a,int n,int m,int i,int j,double c);
void solution_9(double *a,double *b,double *c,int n,int m);
void solution_10(double *a,double *b,double *c,int n,int m,int k);

#endif  