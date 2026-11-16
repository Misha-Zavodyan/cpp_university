#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "io_status.h"
#include "io_array.h"
#include "sol.h"

int main(int argc, char* argv[])
{
    int n, p;
    int res = 0;
    double t = 0;
    char** a;
    char* x;
    char* name;
    int (*cmp)(char*, char*);
    int c;
    cmp = cmp_1;

   if (!((argc == 6) && (sscanf(argv[2], "%d", &c) == 1) && (sscanf(argv[3], "%d", &n) == 1) && (sscanf(argv[4], "%d", &p) == 1)))
    {
        printf("Usage: %s x c n p [filename]\n", argv[0]);
        return 1;
    }

switch (c)
    {
      case 1: cmp = cmp_1;
          break;
      case 2: cmp = cmp_2;
          break;
      case 3: cmp = cmp_3;
          break;
      case 4: cmp = cmp_4;
          break;
      default: printf("Usage: c = {1, 2, 3, 4} \n"); 
      return 0;
    }

    a = (char **) malloc(n * sizeof(char *));
    
    if (a == NULL)
    {
        printf("Error allocating memory\n");
        return 1;
    }
        x = argv[1];
        name = argv[5];
        res = read_array(a, n, name);
        if (res != SUCCESS)
        {
            switch (res)
            {
            case ERROR_OPEN: printf("Cannot open %s\n", name);
                break;
            case ERROR_READ: printf("Cannot read %s\n", name);
                break;
            default: printf("Unknown error %d in %s", res, name);
            break;
            }
            free(a);
            return 3;
        }

    t = clock();
    res = f3(a, n, x, cmp);
    t = (clock() - t) / CLOCKS_PER_SEC;
    printf("New array: \n");
    print_array(a, n, p);
    printf("%s : Task = 3 Res = %d Elapsed = %.2f\n", argv[0], res, t);
    free_array(a, n);
    free(a);

    return 0;
}

