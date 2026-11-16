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

	while (a < -MINX)
	{
		a += STEP;


		it = task1(f0, a, a + STEP, ep, &x);
		if(it < 0)
		{
//		printf("%s : Cannot find root\n", argv[0]);
//		return -1;
			continue;
		}

	//count = getcount();
	
		fx = f0(x, ep);

		printf ("%s : Task = %d X = %e Res = %e Its = %d\n", argv[0], task, x, fx, it);
		k++;
	}
	printf("Root Count %d", k);

	return 0;
}

