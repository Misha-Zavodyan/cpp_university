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
    int diff = 0;
    double t = 0;
    char** array;
    char** b;
    char* name;
    int (*cmp)(char*, char*);
    int c;
    cmp = cmp_1;
    
   if (argc != 5 || sscanf(argv[1], "%d", &c) != 1 || sscanf(argv[2], "%d", &n) != 1 
        || sscanf(argv[3], "%d", &p) != 1)
    {
        printf("Usage: %s c n p [filename]\n", argv[0]);
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
      default: printf("Usage: s = {1, 2, 3, 4} \n"); 
      return 0;
    }

    array = (char **) malloc(n * sizeof(char *));
    if (array == NULL)
    {
        printf("Error allocating memory\n");
        return 1;
    }
        name = argv[4];
        res = read_array(array, n, name);
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
            free(array);
            return 3;
        }

    b = (char **) malloc(n * sizeof(char *));
    if (b == NULL)
    {
        printf("Error allocating memory\n");
        free_array(array, n);
        free(array);
        return 1;
    }

    t = clock();
    f8(array, b, n, cmp);
    t = (clock() - t) / CLOCKS_PER_SEC;
    diff = count_elements(b, n, cmp);
    printf("New array: \n");
    print_array(b, n, p);
    printf("%s : Task = 8 Diff = %d Elapsed = %.2f\n", argv[0], diff, t);
    free_array(array, n);
    free(array);
    free(b);
    return 0;
}
