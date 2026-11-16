#include <stdio.h>
#include <stdlib.h>
#define LEN 1234
int main(int argc,char *argv[])
{

  FILE* fin,*fout;
  int i,j,k,l,kl,tabul,len,lenn,restr,notins=0,fixkl=1;
  char bufs[LEN],* s,* r,* t;
  int *sbuf;
  

  i=0;    
  len=0;
  if (argc!=6)
  {
    printf ("use a .txt b.txt s r t\n");
    return -1;
  }
  
  if (!(fin=fopen(argv[1],"r")))
  {
    printf ("Can't read %s\n", argv[1]);
    return -2;
  }

  if (!(fout=fopen(argv[2],"w")))
  {
    printf ("Can't write %s\n", argv[2]);
    return -2;
  }
  s=argv[3];
  r=argv[4];
  t=argv[5];
  lenn=0;
  i=0;
  while(s[i]!='\0')
  {
    i++;
    lenn++;
  }
  
  sbuf = (int*)malloc((lenn+1)* sizeof(int));
  sbuf[len]='\0';
  i=0;
  len=0;
  while(s[i]!='\0')
  {
    sbuf[i]=-1;
    k=0;
    len++; 
    while(t[k]!='\0' && t[k]!='\n')
    { 
        
      if(s[i]==t[k])
      {
        sbuf[i]=-2;
        if(((i-1)>=0) && (sbuf[i-1]!=-2))
        {
          sbuf[i-1]=len-1;
        }
        len=0;
        break;
      }
      k++;
    }
    i++;
  }
  if(sbuf[i-1]!=-2)
    sbuf[i-1]=len;

  // printf("%s",s);
  // i=0;
  // while(s[i]!='\0')
  // {
  //   printf("%d ",sbuf[i]);
  //   i++;
  // }
  // printf("\n");
  k=0;
  len=2;
  
  while(fgets(bufs,LEN,fin)!=NULL)
  {
//     printf("\n %s",bufs);
    i=0;
    j=0;
    restr=0;
    notins=0;
    kl=0;
    fixkl=1;

    while(bufs[i]!='\0' && bufs[i]!='\n')
    {
//       printf(" %c\n",bufs[i]);
      
      k=0;
      tabul=0;
      while(t[k]!='\0' && t[k]!='\n')
      {
//         printf("t: %c %c\n",bufs[i],t[k]);
        
        if(bufs[i]==t[k])
        {
          tabul=1;
          
          
          if((j>0)&&(j==sbuf[j+kl-1])&&(!notins))
          {
            restr=1;
            printf("!!!!!! whil %s i:%d l:%d kl:%d %c %c fixkl:%d j:%d\n",bufs,i,l,kl,bufs[i],s[j+l+kl],fixkl,j);
          }
          j=0;
          notins=0;
          fixkl=1;
          kl=0;
          break;
        }
        k++;
      }
      //printf("%d",lenn);
      if(!tabul)
      {
        l=0;
        
        while(sbuf[j+l+kl]!='\0'&&(j+l+kl<lenn))
        {
          printf("%s i:%d l:%d kl:%d %c %c fixkl:%d j:%d\n",bufs,i,l,kl,bufs[i],s[j+l+kl],fixkl,j);
          if(bufs[i]==s[j+l+kl])
          {
            j++;
            fixkl=0;
            break;
          }
          else
          {
            if(fixkl)
            {
              while(sbuf[kl]!='\0')
              {
                if(sbuf[kl]==-2)
                {
                  kl++;
                  l--;
                  
                  break;
                }
                kl++;
              }
              // if(kl==lenn)
              //   break;
            }
            else
            {
              
                j=0;
              // l=0;
              break;
              }
              
            }
          }
          l++;
        }
        // if(bufs[i]==s[j])
        // {
        //   j++;
        // }
        // else
        // {
        //   j=0;
        //   notins=1;
        // }
        
      }
      
      i++;
    }
    if((j>0)&&(j==sbuf[j+kl-1])&&(!notins))
    {
      restr=1;
      printf("!!! end%s i:%d l:%d kl:%d %c %c fixkl:%d j:%d\n",bufs,i,l,kl,bufs[i],s[j+l+kl],fixkl,j);
    }
    if(restr)
    {
      fprintf(fout, "%s\n", r);
    }
    else
    {
      fprintf(fout, "%s", bufs);
    }
    
  }
  

free(sbuf);
fclose(fin);
fclose(fout);
return 0;
}
