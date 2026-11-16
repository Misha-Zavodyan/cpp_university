#include <stdio.h>
#include <math.h>

#include "funcs.h"


double f2(double x, double t)
{
	return (t*t/sqrt(1 + x*x + t*t));
}

double f1(double x, double eps)
{
	double res;
	task9(f2, x, 0, x*x, eps*0.01, &res);
	return res;	
}

double f0(double x, double eps)
{
	return f1(x, eps) - exp(-x);
}

int task8(double (*op)(double, double), double xx, double a, double b, double ep, double *r)
{
	int i = 1, j = 0, k = 1;
	double h = (b - a) * 0.5;
	double x = 0.0, c = (a + b) * 0.5;
	double res = 0.0, tek = 0.0;
	double f1 = (*op)(xx, a), f3 = (*op)(xx, b), f2 = (*op)(xx, c);

	if(fabs(h) < ep)
		return 0.0;

	tek = ((f1 + f3) * 0.5 + f2) * h;

	for(i = 2; i < MAXIT; i++)
	{
		res = tek;
		h /= 2.0;
		x = a + h;
		k *= 2;
		tek *= 0.5;
		for(j = 0; j < k; j++)
		{
			f1 = (*op)(xx, x);
			tek += f1 * h;
			x += 2*h;
		}
		if(fabs(res - tek) < ep)
		{
			*r = tek;
			return i;
		}
	}
	return -1;
}



int task9(double (*op)(double, double), double xx,  double a, double b, double ep, double *r)
{
	int i = 1, j = 0, k = 1;
	double h = (b - a) * 0.5;
	double x = 0.0, c = (a + b) * 0.5;
	double s1 = 0.0, s2 = 0.0, s_21 = 0.0, s_22 = 0.0;
	if(fabs(h) < ep)
		return 0.0;

	//tek = h / 3.0 * (f1 + f3 + 4 * f2);
	s1 = h / 3.0 * ((*op)(xx, a) + (*op)(xx, b)) ;
	s2 = h / 3.0 * 2 * (*op)(xx, c);
	for(i = 2; i < MAXIT; i++)
	{
		s_21 = (s1 + s2) * 0.5;
		s_22 = 0.0;
		h /= 2.0;
		x = a + h;
		k *= 2;

		for(j = 0; j < k; j++)
		{
			s_22 += 2.0 / 3.0 * (*op)(xx, x) * h;
			x += 2.0 * h;
		}


		if(fabs(s1 + 2*s2 - s_21 - 2*s_22) < ep)
		{
			*r = s_21 + 2*s_22;
			return i;
		}
		s2 = s_22;
		s1 = s_21;
	}
	return -1;
}



int task1(double (*op)(double, double), double a, double b, double ep, double *x)
{

	double c = 0.0, f_a = (*op)(a, ep), f_b = (*op)(b, ep), f_c = 0.0;
	int i = 0;

	
	if(fabs(f_a) < ep)
	{
		*x = a;
		return 0;
	}

	if(fabs(f_b) < ep)
	{
		*x = b;
		return 0;
	}

	if(SIGN(f_a) == SIGN(f_b))
	{
		return -1;
	}

	for(i = 0; i < MAXIT1; i++)
	{
		c = (a + b) * 0.5;

		if((b - a < ep) || ((c <= a) && (c >= a)) || ((c >= b) && (c <= b)))
		{
			*x = c;
			return i;
		}

		f_c = (*op)(c, ep);
		if(fabs(f_c) < ep)
		{
			*x = c;
			return i; 
		}

		if(SIGN(f_a) != SIGN(f_c))
		{
			b = c;
			f_b = f_c;
		}else
		{
			a = c;
			f_a = f_c;
		}
	}
	return -1;
}


