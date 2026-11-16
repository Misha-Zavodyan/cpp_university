#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "io_status.h"
#include "io_array.h"

void print_array(char **a, int n, int max_print)
{
    int i, m;
    m = (n > max_print ? max_print : n);
    for (i = 0; i < m; i++)
    {
        if (a[i])
        {
            printf("%s\n", a[i]);
        }
    }
}

void free_array(char **a, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if (a[i])
        {
            free(a[i]);
            a[i] = 0;
        }
    }
}

int read_array(char **a, int n, const char *name)
{
    char buf[LEN];
    int i, j;
     FILE *fp;
    if (!(fp = fopen(name, "r")))
    {
        return ERROR_OPEN;
    }
    
    for (i = 0; i < n; i++)
    {
        if (!fgets(buf, LEN, fp))
        {
            fclose(fp);
            free_array(a, i);
            return ERROR_READ;
        }
        for (j = 0; buf[j]; j++)
        {
            if (buf[j] == '\n')
            {
                buf[j] = 0;
                break;
            }
        }
        a[i] = (char *) malloc((j + 1) * sizeof(char));
        if (!a[i])
        {
            fclose(fp);
            free_array(a, i);
            return -3;
        }
        strcpy(a[i], buf);
    }
    fclose(fp);
    return SUCCESS;
}

