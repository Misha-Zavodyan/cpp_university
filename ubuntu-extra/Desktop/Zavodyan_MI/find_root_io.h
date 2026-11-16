#ifndef LEN
#define LEN 1235
#define eps 2.20e-16
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include <math.h>

enum io_status
{
ERROR_OPEN = -5,
ERROR_ARGUMENT,
ERROR_MEMORY,
ERROR_READ,
ERROR_UNKNOWN,
SUCCESS
};

struct _node;
typedef struct _node
{
  char * s;
  struct _node * next;
} node;

int get_length(node* first);
void delet_list(node* first);
int read_list(const char *name, node** head);
void print_list(node* first,int p);

int function_1(node *head);
int function_2(node *head);
int function_3(node *head);
int function_4(node *head);
int function_5(node *head);
int function_6(node *head);
int function_7(node *head);
node* function_8(node *head); 
node* function_9(node *head); 
node* function_10(node *head);


#endif  