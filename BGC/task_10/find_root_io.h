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

int solution_1(double (*f)( double),double a,double b,double epsilon,int M,double* p_x);



#endif  