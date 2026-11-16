#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include "io_status.h"
#include "sol.h"
#define LEN 1234

int main(int argc, char* argv[])
{
    char* f_a;
    char* f_b;
    char* s = 0;
    double t;
    int res;

    if (argc != 4)
    {
        printf("Usage: %s file1 file2 s\n", argv[0]);
        return 1;
    }

    f_a = argv[1];
    f_b = argv[2];
    s = argv[3];
    t = clock();
    res = f1(f_a, f_b, s);
    t = (clock() - t) / CLOCKS_PER_SEC;

    if (res < SUCCESS) 
    {
        switch (res)
        {
        case ERROR_OPEN:
            printf("Cannot open %s\n", f_a);
            break;
        case ERROR_READ:
            printf("Cannot read %s\n", f_a);
            break;
        case ERROR_WRITE:
            printf("Cannot write to file %s\n", f_b);
            break;
        default:
            printf("Unknown error %d\n", res);
        }
        return 2;
    }

    printf("%s : Task = 1 Result = %d Elapsed = %.2f\n", argv[0], res, t);
  
    return 0;
}


