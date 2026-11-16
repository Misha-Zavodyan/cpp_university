#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXIT 1000

#define SIGN(x) ((x) < (0) ? (1) : (0)) 

int solution( double a, double b, double eps, double M, double *x);
double f(double x,double t);
double int_sol( double xx,  double ep);



double f(double x,double t)
{
        double x_2=x*x;
        double t_2=t*t;
        return (t_2/(sqrt(1+x_2+t_2)));
}




double int_sol( double xx,  double ep)
{
	double b=xx*xx;
	double a=0;
	int i = 1, j = 0, k = 1;
	double h = (b - a) * 0.5;
	double x = 0.0, c = (a + b) * 0.5;
	double s1 = 0.0, s2 = 0.0, s_21 = 0.0, s_22 = 0.0;
	if(fabs(h) < ep)
		return 0.0;

	//tek = h / 3.0 * (f1 + f3 + 4 * f2);
	s1 = h / 3.0 * (f(xx, a) + f(xx, b)) ;
	s2 = h / 3.0 * 2 * f(xx, c);
	for(i = 2; i < MAXIT; i++)
	{
		s_21 = (s1 + s2) * 0.5;
		s_22 = 0.0;
		h /= 2.0;
		x = a + h;
		k *= 2;

		for(j = 0; j < k; j++)
		{
			s_22 += 2.0 / 3.0 * f(xx, x) * h;
			x += 2.0 * h;
		}


		if(fabs(s1 + 2*s2 - s_21 - 2*s_22) < ep)
		{
			return  (s_21 + 2*s_22) - exp(-xx);
			//return i;
		}
		s2 = s_22;
		s1 = s_21;
	}
	return -1;
}

int main(int argc, char* argv[])
{
        double a = -10;
        double b = 10;
        double eps = 0;
        double x;
        double point;
        double step;
        double secon;
        double first;
        int M = 1000;
        int it;
        int n = 200;
        if(!((argc == 2) && (sscanf(argv[1], "%lf", &eps) == 1)))
	{
		printf("Usage: %s ep\n", argv[0]);
		return -1;
	}

        first = int_sol(a,eps);
        step = (b - a) / n;
        point = a;
        while  (point < b)
        {
        
                point += step;
                secon = int_sol(point,eps);
                if (secon * first < 0)
                {
                        it = solution(a, point, eps, M, &x);
                        printf("point = %10.6e iteration = %d value = %10.6e \n", x,it,fabs(int_sol(x,eps)));
                        first = secon;
                        a = point;
                }
        }

        return 0;
}


int solution(double a, double b, double eps, double M, double *x)
{
        double c = 0.0;
        double f_a = int_sol(a,eps);
        double f_b = int_sol(b,eps);
        double f_c = 0.0;
        int i = 0;

        if(fabs(f_a) < eps)
        {
                *x = a;
                return 0;
        }

        if(fabs(f_b) < eps)
        {
                *x = b;
                return 0;
        }

        if(SIGN(f_a) == SIGN(f_b))
        {
                return -1;
        }

        for(i = 0; i < M; i++)
        {
                c = (a + b) * 0.5;

                if((b - a < eps) || ((c <= a) && (c >= a)) || ((c >= b) && (c <= b)))
                {
                        *x = c;
                        return i;
                }

                f_c = int_sol(c,eps);
                if(fabs(f_c) < eps)
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
