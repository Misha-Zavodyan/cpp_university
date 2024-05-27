#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "tasks.h"
#include "funcs.h"

int main(int argc, char *argv[])
{
	double (*fu[7])(double) = {fu0, fu1, fu2, fu3, fu4, fu5, fu6};
	double (*dfu[7])(double)= {fu0_, fu1_, fu2_, fu3_, fu4_, fu5_, fu6_};
	int k = 0;
	double x0 = 0.0, fx = 0.0, ep = 0.0;
	int task = 2, it = 0, count = 0;
	double t = 0.0, x = 0.0;

	if(!((argc == 4) && (sscanf(argv[1], "%lf", &x0) == 1) && 
		(sscanf(argv[2], "%lf", &ep) == 1) && (ep > 0) && 
		(sscanf(argv[3], "%d", &k) == 1) && (k < 7) && (k >= 0)))
	{
		printf("Usage: %s x0 ep k\n", argv[0]);
		return -1;
	}

	t = clock();
	it = task2(fu[k], dfu[k], x0, ep, &x);
	t = (clock() - t) / CLOCKS_PER_SEC;
	if(it < 0)
	{
		printf("%s : Cannot find root\n", argv[0]);
		return -1;
	}

	count = getcount();
	
	fx = (*fu[k]) (x);

	printf ("%s : Task = %d X = %e Res = %e Its = %d Count = %d T = %.2f\n", argv[0], task, x, fx, it, count, t);
	return 0;
}

