#include <time.h>
#include <stdio.h>
#include <stdlib.h>
//read from file
//k - length (items count)
int read_array(double *b, int k, const char *filename);

void solve(double *a, int lena, double *b, int lenb, double *c);
//init arr by formula
// fo - formula 0..6
void init_array(double *c, int ko, int fo);

//print first kol items from arr
void pri_array(double *d, int kol, int viv);

// fl - formula (0..6)
// le - length
// no - index (1..n)
double f(int fl, int le, int no);

int read_array(double *b, int k, const char *filename)
{
	FILE* in;
	int i;
	if(!(in = fopen(filename, "r")))
		return -1;
	for(i=0; i<k;i++)
	{
		if(fscanf(in, "%lf", b+i)!=1)
		{
			fclose(in);
			return -2;
		}
	}
	fclose(in);
	return 0;
}

void pri_array(double *d, int kol, int viv)
{
	int j;
	if(viv > kol)
		viv = kol;
	for(j = 0; j < viv; j++)
	{
		printf("a[%d] = %lf\n", j, *d);
		d++;
	}
}

void init_array(double *c, int ko, int fo)
{
	int e;
	for(e = 1; e <= ko; e++)
	{
		*c = f(fo, ko, e);
		c++;
	}				
}

double f(int fl, int le, int no)
{
	switch (fl)
	{
		case 1: return no;
		case 2: return le - no;
		case 3: return no / 2;
		case 4: return le - no / 2;
		case 5: return 2 * no;
		default: return le - 2 * no;
	}
	
}




void solve(double *a, int lena, double *b, int lenb, double *c)
{
	int i = 0, j = 0;
	while((i + j)<(lena+lenb))
	{
		if(i == lena)
		{
			c[i+j] = b[j];
			j++;
		}else
		{
			if(j < lenb)
			{
				if(a[i] <= b[j])
				{
					c[i + j] = a[i];
					i++;

				}else
				{
					c[i+j] = b[j];
					j++;
				}
			}else
			{
				c[i+j] = a[i];
				i++;
			}
			
		}
	}
}



int main(int argc, char* argv[])
{
	double *a, *b, *c;
	double t;
	int na, pa, fa;
	int nb, pb, fb;	
	
	char *namea = 0;
	char *nameb = 0;
	na = 0;
	nb = 0;
	fa = 0;
	pa = 0; 
	pb = 0;
	fb = 0;
	a = 0;
	b = 0;
	c = 0;
	switch(argc)
	{
		case  7: if (!((sscanf(argv[1], "%d", &na) == 1) && (na > 0) &&
					 (sscanf(argv[2], "%d", &pa) == 1) && (pa >= 0) &&
					 (sscanf(argv[3], "%d", &fa) == 1) && (fa >= 0) && (fa <= 6) &&
					 (sscanf(argv[4], "%d", &nb) == 1) && (nb > 0) &&
					 (sscanf(argv[5], "%d", &pb) == 1) && (pb >= 0) &&
					 (sscanf(argv[6], "%d", &fb) == 1) && (fb >= 0) && (fb <= 6)))
				{
					printf("Usage: %s na pa fa [filea] nb pb fb [fileb]\n", argv[0]);
					return 1;					
				}
				break;

		case  8: if (!(sscanf(argv[3], "%d", &fa) == 1) && (fa >= 0) && (fa <= 6))
				 {
					printf("Usage: %s na pa fa [filea] nb pb fb [fileb]\n", argv[0]);
					return 1;									 	
				 }
				 if (fa != 0)
				 {
				 	//file b
				 	if (!((sscanf(argv[1], "%d", &na) == 1) && (na > 0) &&
					 (sscanf(argv[2], "%d", &pa) == 1) && (pa >= 0) &&
					 (sscanf(argv[4], "%d", &nb) == 1) && (nb > 0) &&
					 (sscanf(argv[5], "%d", &pb) == 1) && (pb >= 0) &&
					 (sscanf(argv[6], "%d", &fb) == 1) && (fb >= 0) && (fb <= 6)))	
				 	{
				 		printf("Usage: %s na pa fa [filea] nb pb fb [fileb]\n", argv[0]);
				 		return 1;
				 	}
				 	nameb = argv[7];
				 }else
				 {
				 	//file a
				 	if (!((sscanf(argv[1], "%d", &na) == 1) && (na > 0) &&
					 (sscanf(argv[2], "%d", &pa) == 1) && (pa >= 0) &&
					 (sscanf(argv[5], "%d", &nb) == 1) && (nb > 0) &&
					 (sscanf(argv[6], "%d", &pb) == 1) && (pb >= 0) &&
					 (sscanf(argv[7], "%d", &fb) == 1) && (fb >= 0) && (fb <= 6)))	
				 	{
				 		printf("Usage: %s na pa fa [filea] nb pb fb [fileb]\n", argv[0]);
				 		return 1;
				 	}
				 	namea = argv[4];

				 }
				 break;

		case  9: if (!((sscanf(argv[1], "%d", &na) == 1) && (na > 0) &&
					 (sscanf(argv[2], "%d", &pa) == 1) && (pa >= 0) &&
					 (sscanf(argv[3], "%d", &fa) == 1) && (fa >= 0) && (fa <= 6) &&
					 (sscanf(argv[5], "%d", &nb) == 1) && (nb > 0) &&
					 (sscanf(argv[6], "%d", &pb) == 1) && (pb >= 0) &&
					 (sscanf(argv[7], "%d", &fb) == 1) && (fb >= 0) && (fb <= 6)))
				{
					printf("Usage: %s na pa fa [filea] nb pb fb [fileb]\n", argv[0]);
					return 1;					
				}
				namea = argv[4];
				nameb = argv[8];
				break;
		default:
				printf("Usage: %s na pa fa [filea] nb pb fb [fileb]\n", argv[0]);
				return 1;

	}



	a = (double*) (malloc(na * sizeof(double)));
	if(!a)
	{
		printf("ERROR: Cannot allocate %d elements\n", na);
		return 2;
	}

	b = (double*) (malloc(nb * sizeof(double)));
	if(!b)
	{
		free(a);
		printf("ERROR: Cannot allocate %d elements\n", nb);
		return 2;
	}

	c = (double*) (malloc((na + nb) * sizeof(double)));
	if(!c)
	{
		free(a);
		free(b);
		printf("ERROR: Cannot allocate %d elements\n", nb+na);
		return 2;
	}

	if(namea)
	{
		int res;
		res = read_array(a, na, namea);
		if(res < 0)
		{
			switch (res)
			{
				case -1: printf("ERROR: Cannot open file a\n");
						 break;
				case -2: printf("ERROR: Cannot read file a\n");
						 break;
				default: printf("Unknown error with array a %d in %s\n", res, namea);	   	 
			}	
			free(a);
			free(b);
			free(c);
			return 3;
		}

	}else
	{
		init_array(a, na, fa);	
	}

	if(nameb)
	{
		int res;
		res = read_array(b, nb, nameb);
		if(res < 0)
		{
			switch (res)
			{
				case -1: printf("ERROR: Cannot open file b\n");
						 break;
				case -2: printf("ERROR: Cannot read file b\n");
						 break;
				default: printf("Unknown error with array b %d in %s\n", res, nameb);	   	 
			}	
			free(a);
			free(b);
			free(c);
			return 3;
		}

	}else
	{
		init_array(b, nb, fb);	
	}



	printf("Init array a: \n");
	pri_array(a, na, pa);

	printf("\nInit array b: \n");
	pri_array(b, nb, pb);

	t = clock();
	solve(a, na, b, nb, c);
	t = (clock() - t)/ CLOCKS_PER_SEC;
	printf("\nResult array: \n");
	//if(pa>pb)
	//	pa = pb;
	pri_array(c, (na + nb),pa+pb);
	//printf("\nResult is: %d\n", result);
	
	free(a);
	free(b);
	free(c);
	t = (clock() - t)/ CLOCKS_PER_SEC;
	printf("\nf_lapsed = %.2f\n", t);
		
	return 0;
}
