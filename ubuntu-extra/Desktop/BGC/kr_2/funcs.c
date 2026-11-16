#include <stdio.h>
#include <math.h>

#include "funcs.h"


double f3(double x, double u, double t)
{
	return ((t - x)/sqrt(1+ x*x*u*u*t*t*t*t));
}

double f2(double x, double u, double eps)
{
	double res = 0.;
	task8(f3, x, u, 0, 1, eps, &res);
	return res;
}

double f1(double x, double eps)
{
	double res = 0.;
	task8_1(f2, x, 0, x, eps, &res);
	return res;	
}

double f0(double x, double eps)
{
	return f1(x, eps) + 1.0;
}

int task8(double (*op)(double, double, double), double xx, double uu, double a, double b, double ep, double *r)
{
	int i = 1, j = 0, k = 1;
	double h = (b - a) * 0.5;
	double x = 0.0, c = (a + b) * 0.5;
	double res = 0.0, tek = 0.0;
	double f1 = (*op)(xx, uu, a), f3 = (*op)(xx, uu, b), f2 = (*op)(xx, uu, c);

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
			f1 = (*op)(xx, uu, x);
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

int task8_1(double (*op)(double, double, double), double xx, double a, double b, double ep, double *r)
{
	int i = 1, j = 0, k = 1;
	double h = (b - a) * 0.5;
	double x = 0.0, c = (a + b) * 0.5;
	double res = 0.0, tek = 0.0;
	double f1 = (*op)(xx, a, ep), f3 = (*op)(xx, b, ep), f2 = (*op)(xx, c, ep);

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
			f1 = (*op)(xx, x, ep);
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

