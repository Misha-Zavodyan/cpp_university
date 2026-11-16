#ifndef LEN
#define LEN 1234
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

enum io_status
{
ERROR_OPEN = -5,
ERROR_ARGUMENT,
ERROR_MEMORY,
ERROR_READ,
ERROR_UNKNOWN,
SUCCESS
};

int up_strcmp(const char *a ,const char *b);
int down_strcmp(const char *a, const char *b);
int up_len(const char *a,const char *b);
int down_len(const char *a, const char *b);
void delete_array(char *a[],int n);
void print_array(char *a[],int n, int p);
int read_array(char *a[],int n, char * name);
int check (char**a,int n, int (*cmp)(const char *, const char *));
int sort1 (char**a,char *x,int n, int (*cmp)(const char *, const char *));
void sort2 (char**a,char**b,char**c,int n,int m, int (*cmp)(const char *, const char *));
int sort3 (char**a,char *x,int n, int (*cmp)(const char *, const char *));
void sort4 (char**a,int n, int (*cmp)(const char *, const char *));
void sort5 (char**a,int n, int (*cmp)(const char *, const char *));
void sort6 (char**a,int n, int (*cmp)(const char *, const char *));
void sort8 (char**a,char**b,int n, int (*cmp)(const char *, const char *));
#endif  