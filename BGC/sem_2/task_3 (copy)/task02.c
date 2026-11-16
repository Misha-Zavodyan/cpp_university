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
    int na, pa, nb, pb;
    int res;
    int diff = 0;
    double t = 0;
    char* name1;
    char* name2;
    char** array1;
    char** array2;
    char** array3;
    int (*cmp)(char*, char*);
    int c;
    cmp = cmp_1;


    if (argc != 8 || argc < 8 || sscanf(argv[1], "%d", &c) != 1 || sscanf(argv[2], "%d", &na) != 1 || sscanf(argv[3], "%d", &pa) != 1
        || sscanf(argv[5], "%d", &nb) != 1 || sscanf(argv[6], "%d", &pb) != 1)
    {
        printf("Usage: %s c n_a p_a [filename_1] n_b p_b  [filename_2]\n", argv[0]);
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
    name1 = argv[4];
    name2 = argv[7];
    array1 = (char **)malloc(na * sizeof(char *));
    if (array1 == NULL)
    {
        printf("Error allocating memory\n");
        return 2;
    }
        res = read_array(array1, na, name1);
        if (res != SUCCESS)
        {
            switch (res)
            {
            case ERROR_OPEN: printf("Cannot open %s\n", name1);
                break;
            case ERROR_READ: printf("Cannot read %s\n", name1);
                break;
            default: printf("Unknown error %d in %s", res,
                name1); break;
            }
            free(array1);
            //fclose(file1);
            return 3;
        }

        //fclose(file1);

    array2 = (char **)malloc(nb * sizeof(char *));
    if (array2 == NULL)
    {
        printf("Error allocating memory \n");
        free_array(array1, na);
        free(array1);
        return 1;
    }
        res = read_array(array2, nb, name2);
        if (res != SUCCESS)
        {
            switch (res)
            {
            case ERROR_OPEN: printf("Cannot open %s\n", name2);
                break;
            case ERROR_READ: printf("Cannot read %s\n", name2);
                break;
            default: printf("Unknown error %d in %s", res,
                name2); break;
            }
            free_array(array1, na);
            free(array1);
            free(array2);
           // fclose(file2);
            return 3;
        }
        //fclose(file2);
    array3 = (char **)malloc((nb + na) * sizeof(char *));
    if (array3 == NULL)
    {
        printf("Error allocating memory \n");
        free_array(array1, na);
        free_array(array2, nb);
        free(array1);
        free(array2);
        return 1;
    }

    t = clock();
    f2(array1, na, array2, nb, array3, cmp);
    t = (clock() - t) / CLOCKS_PER_SEC;
    diff = count_elements(array3, nb + na, cmp);
    printf("New array: \n");
    print_array(array3, nb + na, pb + pa);
    printf("%s : Task = 2 Diff = %d Elapsed = %.2f\n",argv[0], diff, t);
    free_array(array1, na);
    free_array(array2, nb);
    free(array1);
    free(array2);
    free(array3);

    return 0;
}

