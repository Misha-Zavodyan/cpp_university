#include <time.h>
#include <stdio.h>
#include <stdlib.h>


void solve(double *ma, int len);

//read from file
//k - length (items count)
int read_array(double *b, int k, const char *filename);

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


void solve(double *ma, int len)
{
	int dl = len;
	int i = 0;
	int chek = 0;
	double tmp = 0.0;
	for(dl = len; dl > 1; dl--)
	{
		//if((len - dl) %10000 == 0)
			//printf("dl = %d\n", dl);
		chek = 0;
		for(i = 0; i < dl - 1; i++)
		{
			if(ma[i] > ma[i+1])
			{
				tmp = ma[i];
				ma[i] = ma[i+1];
				ma[i+1] = tmp;
				chek = 1;
			}
		}
		if(chek == 0)
			break;
	}
}

int main(int argc, char* argv[])
{
	double *a;
	double t;
	int n, p, f;// result;
	char *name = 0;
	a = 0;
	t = 0;
	
	n = 0;
	p = 0;
	f = 0;

	if (!(((argc == 5)||(argc == 4)) &&
		(sscanf(argv[1], "%d", &n) == 1) && (n > 0) &&
		(sscanf(argv[2], "%d", &p) == 1) && (p >= 0) &&
		(sscanf(argv[3], "%d", &f) == 1) && (f >= 0) && (f <= 6)))
	{
		printf("Usage: %s n p f [file]\n", argv[0]);
		return 1;
	}

	if(argc == 5)
	{
		if(f == 0)
		{
			name = argv[4];
		}	
		else
		{
			printf("Usage: %s n p f [file]\n", argv[0]);
			return 1;
		}
	}

	a = (double*) (malloc(n * sizeof(double)));
	if(!a)
	{
		printf("ERROR: Cannot allocate %d elements\n", n);
		return 2;
	}
	//printf("name = %s\n", name);
	if(name)
	{
		int res;
		res = read_array(a, n, name);
		if(res < 0)
		{
			switch (res)
			{
				case -1: printf("ERROR: Cannot open file\n");
						 break;
				case -2: printf("ERROR: Cannot read file\n");
						 break;
				default: printf("Unknown error %d in %s\n", res, name);	   	 
			}	
			free(a);
			return 3;
		}

	}else
	{
		init_array(a, n, f);	
	}
	printf("Init array:\n");
	pri_array(a, n, p);
	t = clock();
	solve(a, n);
	t = (clock() - t)/CLOCKS_PER_SEC;
	printf("\nResult array:\n");
	pri_array(a, n, p);
	//printf("\nresult is %d\n", result);
	free(a);
	printf("\nf_lapsed = %.2f\n", t);
		
	return 0;
}
