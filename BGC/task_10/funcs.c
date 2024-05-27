#include <stdio.h>
#include <math.h>

#include "funcs.h"

static int count = 0;

double fu0(double x)
{
	(void)x;
	count++;
	return 1;
}

double fu1(double x)
{
	double vi = 1e+100;
	count++;

	return (x - vi);
}

double fu2(double x)
{
	count++;
	return (4 - x*x);
}

double fu3(double x)
{
	count++;
	return (x*x*x + 3*x*x+16);
}

double fu4(double x)
{
	count++;
	return (3 - 2.0 *x*x - x*x*x*x);
}

double fu5(double x)
{
	count++;
	return (sqrt(fabs(x) + 1) - 2);
}

double fu6(double x)
{
	count++;
	return (sqrt(sqrt(fabs(x) + 1) + 1) - 2);
}

double fu0_(double x)
{
	(void) x;
	return 0;
}

double fu1_(double x)
{
	(void) x;
	return 1;
}

double fu2_(double x)
{
	return (-2 * x);
}

double fu3_(double x)
{
	return (3*x*x + 6*x);
}

double fu4_(double x)
{
	return (-4*x -4*x*x*x);
}

double fu5_(double x)
{
	if(x >= 0)
	{
		if(x <= 0)
			return 0;
		return (0.5 / sqrt(x + 1));
	}
	return (-0.5/ sqrt(1 - x));
}

double fu6_(double x)
{
	if(x >= 0)
	{
		if(x <= 0)
			return 0;
		return (0.25/(sqrt(x + 1) * sqrt(sqrt(x + 1) + 1)));
	}
	return (-0.25/(sqrt(1 - x) * sqrt(sqrt(1 - x) + 1)));
}

int getcount(void)
{
	return count;
}
