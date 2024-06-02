#include <stdio.h>
#include <stdlib.h>

#include "funcs.h"

int main(int argc, char *argv[])
{
	int k = 0;
	double a = MINX, fx = 0.0, ep = 0.0;
	int task = 1, it = 0;
	double x = 0.0;


	if(!((argc == 2) && (sscanf(argv[1], "%lf", &ep) == 1)))
	{
		printf("Usage: %s ep\n", argv[0]);
		return -1;
	}

	if(ep < 2e-9)
		ep = 2e-9;
	a = -8;

	while (a < -5)
	{
		a += STEP;
		it = task1(f0, a, a + STEP, ep, &x);
		if(it < 0)
		{
			continue;
		}

	//count = getcount();
	
		fx = f0(x, ep);

		printf ("%s : Task = %d X = %.10e Res = %e Its = %d\n", argv[0], task, x, fx, it);
		k++;
	}
	

	a = -3;

	while (a < 0)
	{
		a += STEP;
		it = task1(f0, a, a + STEP, ep, &x);
		if(it < 0)
		{
			continue;
		}

	//count = getcount();
	
		fx = f0(x, ep);

		printf ("%s : Task = %d X = %.10e Res = %e Its = %d\n", argv[0], task, x, fx, it);
		k++;
	}

	a = 0;

	while (a < 3)
	{
		a += STEP;
		it = task1(f0, a, a + STEP, ep, &x);
		if(it < 0)
		{
			continue;
		}

	//count = getcount();
	
		fx = f0(x, ep);

		printf ("%s : Task = %d X = %.10e Res = %e Its = %d\n", argv[0], task, x, fx, it);
		k++;
	}

	printf("root count = %d\n", k);

	return 0;
}

double int_sol(double x,double epsilon)
{
        double r;
        double r2;
        double h;
        double x1;
        int i;
        int n=1;

        h = (x*x)/n;  
        r=f(x,0)*0.5*h;
        
        for(i=1;i<n;i++)
        {
                x1=i*h;
                r+= f(x,x1)*h;
        }
        
        r+=f(x,x*x)*0.5*h;
        r2=0;
        
        while(fabs(r2-r)>=epsilon)
        {
                if (n>1)
                        r=r2;
            
                r2=r*0.5;
                h *=0.5;
                for(i=0;i<n;i++)
                {
                        x1=(2*i+1)*h;
                        r2+= f(x,x1)*h;
                }
                n*=2;
                r=r2;
        }

        return r2 - exp(-x);
}

