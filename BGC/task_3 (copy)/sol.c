#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "io_status.h"
#include "io_array.h"
#include "sol.h"

int f1(char **a, int n, char *x, int (*cmp)(char *, char *)) 
{
    int low = 0, high = n, mid = 0;
    while (low < high)
    {
        mid = low + (high - low) / 2;
        if ((*cmp)(a[mid], x) < 0)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

void f2(char **a, int n, char **b, int m, char **c, int (*cmp)(char *, char *))
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n && j < m) 
    {
        if ((*cmp)(a[i], b[j]) < 0)
        {
            c[k] = a[i];
            i++;
        }
        else 
        {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < n)
    {
        c[k] = a[i];
        i++;
        k++;
    }

    while (j < m)
    {
        c[k] = b[j];
        j++;
        k++;
    }
}

int f3(char** a, int n, char* x, int (*cmp)(char*, char*))
{
    int i = 0, j = n - 1;
    char* tmp;
    
    while (i <= j) 
    {
        while (i < n && ((*cmp)(a[i], x) < 0)) 
        {
            i++;
        }
        while (j >= 0 && ((*cmp)(a[j], x) > 0)) 
        {
            j--;
        }
        if (i <= j) 
        {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }

    return i;
}

void f4(char** a, int n, int (*cmp)(char*, char*))
{
    char* tmp;
    int i = 0, j = 0;
    
    for (i = 0; i < n - 1; i++) 
    {
        for(j = 0; j < n - i - 1; j++) 
        {
            if ((*cmp)(a[j], a[j + 1]) > 0) 
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

void f5(char** a, int n, int (*cmp)(char*, char*))
{
    int i = 0, j = 0;
    int minIndex;
    char* tmp;

    for (i = 0; i < n - 1; i++) 
    {
        minIndex = i;
        
        for (j = i + 1; j < n; j++) 
        {
            if ((*cmp)(a[j], a[minIndex]) < 0) 
            {
                minIndex = j;
            }
        }
        
        tmp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = tmp;
    }
}


void f6(char** a, int n, int (*cmp)(char*, char*)) 
{
    int i = 0, j = 0;
    char* x;
    int sorted = 1;

    for (i = 1; i < n; i++) 
    {
        x = a[i];
        j = i - 1;
        
        while (j >= 0 && (*cmp)(a[j], x) > 0)
        {
            a[j + 1] = a[j];
            j--;
            sorted = 0;
        }
        
        a[j + 1] = x;
    }

    if (sorted) return;
}


void f7(char** a, int n, int (*cmp)(char*, char*)) 
{
    int i = 0, j = 0;
    char* x;
    int left = 0;
    int right = 0;
    int mid = 0;

    for (i = 1; i < n; i++) 
    {
        x = a[i];        
        left = 0;
        right = i - 1;
        
        while (left <= right) 
        {
            mid = left + (right - left) / 2;
            
            if ((*cmp)(a[mid], x) > 0) 
            {
                right = mid - 1;
            } else 
            {
                left = mid + 1;
            }
        }
        
        for (j = i - 1; j >= left; j--) 
        {
            a[j + 1] = a[j];
        }        
        a[left] = x;
    }
}

void f8(char** a, char** b, int n, int (*cmp)(char*, char*))
{
    int left = 0;
    int right = 0;
    int end = 0;
    int len = 0, i = 0;
    for (len = 1; len < n; len *= 2)
    {
        for (i = 0; i < n; i += 2 * len)
        {
            left = i;
            right = (i + len) < n ? (i + len) : n;
            end = (i + 2 * len) < n ? (i + 2 * len) : n;
            f2(a + left, right - left, a + right, end - right, b + left, cmp);
        }
        for (i = 0; i < n; i++)
        {
            a[i] = b[i];
        }
    }
}

void f9(char** a, int n, int (*cmp)(char*, char*))
{
    int start = 0;
    int end = n - 1;
    int i = 0;
    char* x = NULL;
    char* tmp = NULL;
    int left, right;
    while (start < end)
    {
        x = a[(start + end) / 2];
        i = 0;
        left = start;
        right = end;
        while (left <= right)
        {
            while ((*cmp)(a[left], x) < 0)
            {
                left++;
            }
            while ((*cmp)(a[right], x) > 0)
            {
                right--;
            }
            if (left <= right)
            {
                tmp = a[left];
                a[left] = a[right];
                a[right] = tmp;
                left++;
                right--;
            }
        }
        i = left;
        if (i - start < end - i)
        {
            f9(a + start, i - start, cmp);
            start = i;
        }
        else
        {
            f9(a + i, end - i + 1, cmp);
            end = i - 1;
        }
    }
}

void f10(char** a, int n, int (*cmp)(char*, char*))
{
    int parent, son, left, right, largest;
    int i, k;
    
    for (k = 1; k < n; k++)
    {
        parent = (k - 1) / 2;
        son = k;
        while (parent >= 0 && (*cmp)(a[son], a[parent]) > 0)
        {
            swap(&a[son], &a[parent]);
            son = parent;
            parent = (parent - 1) / 2;
        }
    }
    
    for (k = n - 1; k > 0; k--)
    {
        swap(&a[0], &a[k]);
        i = 0;
        while (2 * i + 1 < k)
        {
            left = 2 * i + 1;
            right = 2 * i + 2;
            largest = (right < k && (*cmp)(a[right], a[left]) < 0) ? right : left;
            if ((*cmp)(a[i], a[largest]) < 0)
            {
                swap(&a[i], &a[largest]);
                i = largest;
            }
            else
            {
                break;
            }
        }
    }
}

void swap(char** a, char** b)
{
    char* tmp = NULL;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int count_elements(char** a, int n, int (*cmp)(char*, char*))
{
int i;
    int count = 0;
    for (i = 1; i < n; i++)
    {
        if ((*cmp)(a[i], a[i-1]) < 0) 
        {
            count++;
        }
    }
    return count;
}

int cmp_1(char *a, char *b)
{
  if (strcmp(a,b) > 0) return 1;
  if (strcmp(a,b) < 0) return -1;
  return 0;
}

int cmp_2(char *a, char *b) 
{
  if (strcmp(a,b) > 0) return -1;
  if (strcmp(a,b) < 0) return 1;
  return 0;
}

int cmp_3(char *a, char *b) 
{
 if (strlen(a) >  strlen(b))  return 1;
 if (strlen(a) <  strlen(b))  return -1;
  return 0;
}

int cmp_4(char *a, char *b) 
{
 if (strlen(a) >  strlen(b))  return -1;
 if (strlen(a) <  strlen(b))  return 1;
  return 0;
}

