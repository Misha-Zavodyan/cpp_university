#include "find_root_io.h"



int get_length(node* first)
{
  node* curr;
  int i=0;
  for(curr=first;curr;curr=curr->next)
    i++;

  return i;
}

void delet_list(node* first)
{
  node* curr,*next;
  for(curr=first;curr;curr=next)
  {
    next=curr->next;
    free(curr->s);
    free(curr);
  }
}

int read_list(const char *name, node** head)
{
  char buf[LEN];
  FILE *fp;
  node *first,*curr,*next;
  int i;

  fp=fopen(name,"r");
  if(!fp) return ERROR_OPEN;
  
  if(!fgets(buf,LEN,fp))
  {
    fclose(fp);
    return ERROR_READ;
  }

  first=(node*)malloc(sizeof(node));
  if(!first)
  {
    fclose(fp);
    return ERROR_MEMORY;
  }

  for (i=0;buf[i];i++)
  {
    if(buf[i]=='\n')
    {
      buf[i]=0;
      break;
    }
  }

  first->s=(char*)malloc((i+1)*sizeof(char));
  if(!first->s)
  {
    free(first);
    fclose(fp);
    return ERROR_MEMORY;
  }

  strcpy(first->s,buf);
  first->next=0;
  curr=first;

  while(fgets(buf,LEN,fp))
  {
    next=(node*)malloc(sizeof(node));
    if(!next)
    {
      delet_list(first);
      fclose(fp);
      return ERROR_MEMORY;
    }
    for (i=0;buf[i];i++)
    {
      if(buf[i]=='\n')
      {
        buf[i]=0;
        break;
      }
    }
    next->s=(char*)malloc((i+1)*sizeof(char));
    if(!next->s)
    {
      delet_list(first);
      free(next);
      fclose(fp);
      return ERROR_MEMORY;
    }

    strcpy(next->s,buf);
    next->next=0;
    curr->next=next;
    curr=next;
  }  

  if(!feof(fp))
  {
    delet_list(first);
    fclose(fp);
    return ERROR_READ;
  }

  fclose(fp);
  *head=first;
  return SUCCESS;
}

void print_list(node* first,int p)
{
  int i;
  node* curr;

  curr=first;
  for (i=0;i<p;i++)
  {
    printf("%s\n",curr->s);
    curr=curr->next;
    if(curr==0)
    {
      break;
    }
  }
}

int function_1(node *head)
{
  if (head == NULL)
    return 0;

  int maxCount = 1;
  char *maxString = head->s;

  node *current = head->next;
  while (current != NULL) {
    int cmp = strcmp(current->s, maxString);
    if (cmp > 0) {
      maxString = current->s;
      maxCount = 1;
    } else if (cmp == 0) {
      maxCount++;
    }
    current = current->next;
  }

  return maxCount;
}

int function_2(node *head) 
{
    if (head == NULL || head->next == NULL)
        return 0;

    int count = 0;
    node *prev = head;
    node *current = head->next;

    while (current != NULL) 
    {
        if (strcmp(current->s, prev->s) > 0)
            count++;
        prev = current;
        current = current->next;
    }

    return count;
}

int function_3(node *head) 
{
    if (head == NULL || head->next == NULL)
        return 0;

    int count = 0;
    node *prev = head;
    node *current = head->next;
    node *next = current->next;

    while (next != NULL) 
    {
        if (strcmp(current->s, prev->s) >= 0 && strcmp(current->s, next->s) >= 0)
            count++;
        prev = current;
        current = next;
        next = next->next;
    }

    return count;
}

int function_4(node *head) 
{
  if (head == NULL || head->next == NULL || head->next->next == NULL)
    return 0;

  int maxDistance = 0;
  int distance = 0;
  node *prev = head;
  node *current = head->next;
  node *next = current->next;

  while (next != NULL) 
  {
    if (strcmp(current->s, prev->s) >= 0 && strcmp(current->s, next->s) >= 0) 
    {
      distance = 1;
      while (next != NULL && strcmp(next->s, current->s) == 0) 
      {
        distance++;
        prev = current;
        current = next;
        next = next->next;
      }
      if (next != NULL && strcmp(next->s, current->s) < 0) 
      {
        if (distance > maxDistance) 
        {
          maxDistance = distance;
        }
      }
    }
    prev = current;
    current = next;
    if (next != NULL)
      next = next->next;
  }

  return maxDistance;
}

int function_5(node *head) 
{
  if (head == NULL)
    return 0;

  int maxLength = 1;
  int currentLength = 1;
  node *current = head;
  node *next = head->next;

  while (next != NULL) 
  {
    if (strcmp(next->s, current->s) > 0) 
    {
      currentLength++;
      if (currentLength > maxLength)
        maxLength = currentLength;
    } 
    else 
    {
      currentLength = 1;
    }
    current = next;
    next = next->next;
  }

  return maxLength;
}

int function_6(node *head) 
{
  if (head == NULL)
    return 0;

  int count = 0;
  node *current = head;
  node *next = head->next;

  while (next != NULL) 
  {
    if (strcmp(next->s, current->s) != 0)
      count++;
    current = next;
    next = next->next;
  }

  return count + 1;
}


int function_7(node *head) 
{
  if (head == NULL)
    return 0;

  int maxDistance = 0;
  int distance = 0;
  node *current = head;
  node *next = head->next;

  while (next != NULL) 
  {
    if (strcmp(next->s, current->s) != 0) {
      if (distance > maxDistance)
        maxDistance = distance;
      distance = 0;
    } else {
      distance++;
    }
    current = next;
    next = next->next;
  }

  return maxDistance;
}

node* function_8(node *head)  
{
  if (head == NULL || head->next == NULL) 
  {
    return head;
  }

  node* prev = head;
  node* curr = head->next;

  while (curr != NULL) 
  {
    if (strcmp(curr->s, prev->s) <= 0) 
    {
      node* temp = curr;
      curr = curr->next;
      free(temp->s);
      free(temp);
      prev->next = curr;
    } 
    else 
    {
      prev = curr;
      curr = curr->next;
    }
  }

  return head;
}

node* function_9(node* head) 
{
  if (head == NULL || head->next == NULL || head->next->next == NULL) 
  {
    return head;
  }

  node* prev = head;
  node* curr = head->next;
  node* next = curr->next;

  while (next != NULL) 
  {
    if (strcmp(curr->s, prev->s) >= 0 && strcmp(curr->s, next->s) >= 0) 
    {
      node* temp = curr;
      curr = next;
      next = next->next;
      free(temp->s);
      free(temp);
      prev->next = curr;
    } 
    else 
    {
      prev = curr;
      curr = next;
      next = next->next;
    }
  }

  if (strcmp(curr->s, prev->s) >= 0) 
  {
    free(curr->s);
    free(curr);
    prev->next = NULL;
  }

  return head;
}

node* function_10(node* head) 
{
  if (head == NULL || head->next == NULL) 
  {
    return head;
  }

  node* prev = head;
  node* curr = head->next;

  while (curr != NULL && strcmp(curr->s, prev->s) < 0) 
  {
    node* temp = curr;
    curr = curr->next;
    free(temp->s);
    free(temp);
  }

  head->next = curr;

  while (curr != NULL && curr->next != NULL) 
  {
    if (strcmp(curr->next->s, curr->s) >= 0) 
    {
      curr = curr->next;
    } 
    else 
    {
      node* temp = curr->next;
      while (temp != NULL && strcmp(temp->s, curr->s) < 0) 
      {
        node* next = temp->next;
        free(temp->s);
        free(temp);
        temp = next;
      }
      curr->next = temp;
      curr = temp;
    }
  }

  return head;
}