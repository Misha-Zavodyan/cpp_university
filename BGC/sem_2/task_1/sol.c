#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include "io_status.h"
#include "sol.h"
#define LEN 1234

int removeEscapeChars(char *s)
{
    char *src = s;
    char *dest = s;

    while (*src) 
    {
       if (*src == '\\') 
        {
            src++;
            *dest = *src;
            dest++;
            src++;
        } 
        else 
        {
            *dest = *src;
            dest++;
            src++;
        }
    }
    *dest = '\0';
    return 0;
}

char* find_last_occurrence(const char* buffer, const char* s_) 
{
    char* last_occurrence = NULL;
    char* occurrence = strstr(buffer, s_);
    
    while (occurrence != NULL) 
    {
        last_occurrence = occurrence;
        occurrence = strstr(occurrence + 1, s_);
    }
    
    return last_occurrence;
}

int f1(const char *fileNameA, const char *fileNameB, const char *s) 
{
    FILE *fileA = fopen(fileNameA, "r");
    FILE *fileB = fopen(fileNameB, "w");
    char s_[LEN];
    char buffer[LEN];
    char *ans;
    int count = 0;
    
    if (!fileA) 
    {
        return ERROR_OPEN; 
    }
    
    if (!fileB) 
    {
        fclose(fileA);
        return ERROR_WRITE; 
    }
    
    strcpy(s_, s);
    switch(removeEscapeChars(s_))
    {
        case SUCCESS:
            break;
        default:
            fclose(fileA);
            fclose(fileB);
            return -3;
    }
    
    if (strlen(s) > 0 && s[strlen(s)-1] == '\\') 
    {
        fclose(fileA);
        fclose(fileB);
        return ERROR_READ; 
    }
    
    while (fgets(buffer, sizeof(buffer), fileA) != NULL)
      {
        int i;
        for (i = 0; buffer[i]; i++)
        {
            if (buffer[i] == '\n')
            {
                buffer[i] = 0;
                break;
            }
       }
    
    if (s_[0] == '^')
    {
      char *temp_s_ = s_ + 1; 
    ans = strstr(buffer, temp_s_);
     if (ans == buffer)
     {
        fprintf(fileB, "%s\n", buffer);
                count++;
     }
    }
    
    else 
    
    {
      
    ans = strstr(buffer, s_);
     if (ans != 0)
      {
        fprintf(fileB, "%s\n", buffer);
                count++;
      }
    }
    }
    
 if (!feof(fileA))
    {
        fclose(fileA);
        fclose(fileB);
        return ERROR_READ;
    }
    
    fclose(fileA);
    fclose(fileB);
    return count;
}

int f2(const char *fileNameA, const char *fileNameB, const char *s) 
{
    FILE *fileA = fopen(fileNameA, "r");
    FILE *fileB = fopen(fileNameB, "w");
    char s_[LEN];
    char buffer[LEN];
    char *ans;
    int count = 0;
    
    if (!fileA) 
    {
        return ERROR_OPEN; 
    }
    
    if (!fileB) 
    {
        fclose(fileA);
        return ERROR_WRITE; 
    }
    
    strcpy(s_, s);
    if (s_[strlen(s_) - 1] == '$' && s_[strlen(s_) - 2] != '\\')
    {
     s_[strlen(s_) - 1] = '\0';
    }

    switch(removeEscapeChars(s_))
    {
        case SUCCESS:
            break;
        default:
            fclose(fileA);
            fclose(fileB);
            return -3;
    }
    
    
    if (strlen(s) > 0 && s[strlen(s)-1] == '\\') 
    {
        fclose(fileA);
        fclose(fileB);
        return ERROR_READ; 
    }
    
    while (fgets(buffer, sizeof(buffer), fileA) != NULL)
      {
        int i;
        for (i = 0; buffer[i]; i++)
        {
            if (buffer[i] == '\n')
            {
                buffer[i] = 0;
                break;
            }
       }
    
    if (s[strlen(s) - 1] == '$' && s[strlen(s) - 2] != '\\') 
    {
    ans = find_last_occurrence(buffer, s_);
          if (ans != NULL && (*(ans + strlen(s_)) == '\0'))
            {
              fprintf(fileB, "%s\n", buffer);
                      count++;
            }
    }
    
    else 
    {
    ans = strstr(buffer, s_);
     if (ans != 0)
      {
        fprintf(fileB, "%s\n", buffer);
                count++;
      }
    }
    }
 if (!feof(fileA))
    {
        fclose(fileA);
        fclose(fileB);
        return ERROR_READ;
    }
    
    fclose(fileA);
    fclose(fileB);
    return count;
}


int f5(char *fileNameA, char *fileNameB, char *s, char *t) 
{
    FILE *fileA = fopen(fileNameA, "r");
    FILE *fileB = fopen(fileNameB, "w");
    char buffer[1234];
    int count = 0;
    int match = 0;
    char t_[1234];
    char temp_s[1234];
    char *wordA;
    char *saveptr1 = NULL, *saveptr2 = NULL;
    strcpy(t_, t);
    
    if (!fileA) 
    {
        return ERROR_OPEN; 
    }
    
    if (!fileB) 
    {
        fclose(fileA);
        return ERROR_WRITE; 
    }
    
    while (fgets(buffer, sizeof(buffer), fileA)) 
    {
    char temp_buffer[1234];
    int i;
    match = 0;
    strcpy(temp_buffer, buffer);
    
        for (i = 0; temp_buffer[i]; i++)
        {
            if (temp_buffer[i] == '\n')
            {
                temp_buffer[i] = 0;
                break;
            }
       }
      
        wordA = strtok_r(temp_buffer, t_, &saveptr1);
        strcpy(temp_s, s);
        while (wordA != NULL) 
        {
            char *wordS = strtok_r(temp_s, t, &saveptr2);
            while (wordS != NULL) 
            {
                if (strcmp(wordA, wordS) == 0) 
                {
                    fprintf(fileB, "%s", buffer);
                    count++;
                    match = 1;
                    break;
                }
                wordS = strtok_r(NULL, t, &saveptr2);
            }
            if (match)
            {
              break;
            }
            wordA = strtok_r(NULL, t_, &saveptr1);
        }
    }
    
      if (!feof(fileA))
    {
        fclose(fileA);
        fclose(fileB);
        return ERROR_READ;
    }
    
    fclose(fileA);
    fclose(fileB);
    return count;
}

int f3(char *fileNameA, char *fileNameB, char *s, char *t) 
{
    FILE *fileA = fopen(fileNameA, "r");
    FILE *fileB = fopen(fileNameB, "w");
    char buffer[1234];
    int count = 0;
    char t_[1234];
    char s_[1234];
    char *wordA;
    char *saveptr1 = NULL;
    int match = 0;
     char *ans;
     strcpy(t_, t);
      strcpy(s_, s);
      
    if (!fileA) 
    {
        return ERROR_OPEN; 
    }
    
    if (!fileB) 
    {
        fclose(fileA);
        return ERROR_WRITE; 
    }
    
    if (s[0] == '\\' && s[1] == '<')
    {
    char *temp_s = s + 2; 
    strcpy(s_, temp_s);
    match = 1;
    }
    
    switch(removeEscapeChars(s_))
    {
        case SUCCESS:
            break;
        default:
            fclose(fileA);
            fclose(fileB);
            return -3;
    }

      if (strlen(s) > 0 && s[strlen(s)-1] == '\\') 
    {
        fclose(fileA);
        fclose(fileB);
        return ERROR_READ; 
    }
    
    while (fgets(buffer, sizeof(buffer), fileA) != NULL) 
    {
      char temp_buffer[1234];
      int i;
      strcpy(temp_buffer, buffer);
    
        for (i = 0; temp_buffer[i]; i++)
        {
            if (temp_buffer[i] == '\n')
            {
                temp_buffer[i] = 0;
                break;
            }
       }
       
    wordA = strtok_r(temp_buffer, t_, &saveptr1);
     while (wordA != NULL) 
     {
     
     if (match == 0)
        {
        ans = strstr(wordA, s_);
         if (ans != 0)
           {
              fprintf(fileB, "%s", buffer);
              count++;
              break;
           }
          }
          else 
          {
            ans = strstr(wordA, s_);
            if (ans == wordA)
           {
              fprintf(fileB, "%s", buffer);
              count++;
              break;
           }
          }
            wordA = strtok_r(NULL, t_, &saveptr1);
      }
      
      }
  
      if (!feof(fileA))
    {
        fclose(fileA);
        fclose(fileB);
        return ERROR_READ;
    }
    
    fclose(fileA);
    fclose(fileB);
    return count;
}

int f4(char *fileNameA, char *fileNameB, char *s, char *t) 
{
    FILE *fileA = fopen(fileNameA, "r");
    FILE *fileB = fopen(fileNameB, "w");
    char buffer[1234];
    int count = 0;
    char t_[1234];
    char s_[1234];
    char *wordA;
    char *saveptr1 = NULL;
    int match = 0;
     char *ans;
     strcpy(t_, t);
      strcpy(s_, s);
    if (!fileA) 
    {
        return ERROR_OPEN; 
    }
    
    if (!fileB) 
    {
        fclose(fileA);
        return ERROR_WRITE; 
    }
    
    if (s[strlen(s) - 2] == '\\' && s[strlen(s)-1] == '>')
    {
      s_[strlen(s) -2] = '\0';
      s_[strlen(s) -1] = '\0';
      match = 1;
    }
    
    switch(removeEscapeChars(s_))
    {
        case SUCCESS:
            break;
        default:
            fclose(fileA);
            fclose(fileB);
            return -3;
    }
    
      if (strlen(s) > 0 && s[strlen(s)-1] == '\\') 
    {
        fclose(fileA);
        fclose(fileB);
        return ERROR_READ; 
    }
    
    
    while (fgets(buffer, sizeof(buffer), fileA) != NULL) 
    {
      char temp_buffer[1234];
      int i;
      strcpy(temp_buffer, buffer);
    
        for (i = 0; temp_buffer[i]; i++)
        {
            if (temp_buffer[i] == '\n')
            {
                temp_buffer[i] = 0;
                break;
            }
       }
       
     wordA = strtok_r(temp_buffer, t_, &saveptr1);
     while (wordA != NULL) 
     {
     
     if (match)
        {
         ans = find_last_occurrence(wordA, s_);
          if (ans != NULL && (*(ans + strlen(s_)) == '\0'))
            {
              fprintf(fileB, "%s", buffer);
                      count++;
              break;
           }
        }
          else 
          {
            ans = strstr(wordA, s_);
            if (ans != NULL)
           {
              fprintf(fileB, "%s", buffer);
              count++;
              break;
           }
          }
            wordA = strtok_r(NULL, t_, &saveptr1);
      }
      
      }
    
      if (!feof(fileA))
    {
        fclose(fileA);
        fclose(fileB);
        return ERROR_READ;
    }
    
    fclose(fileA);
    fclose(fileB);
    return count;
}
