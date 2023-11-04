#include <iostream>   

#include "CComplexVector.h"
#define N 5
 
using namespace std;

int main()
{        
  float m[5]={1,2,3,4,5};
  float n[5]={6,7,8,9,4};
  float m_Im[5]={0,0,0,0,0};
  float n_Im[5]={0,0,0,0,0};
  int iter=0,cs=0,corect=0;
  float res=0;
  CComplexVector CC1(n,m),CC2(m,n), CC3;
  CC3=CC1+CC2;
  cout<< "First vector" <<"\n";
  cout<<CC1<<"\n";
  cout<< "Second vector" <<"\n";
  cout<<CC2<<"\n";
  cout<< "first * second vector" <<"\n";
  cout<<CC1*CC2<<"\n";
  cout<< "first + second vector" <<"\n";
  cout<<CC3<<"\n";
  cout<< "first - second vector" <<"\n";
  cout<<CC1-CC2<<"\n";


  cout<<"Enter the number of autotests: ";
  cin>>iter;
  corect=iter;

  for(int i=0;i<iter;i++){
      for(size_t j=0;j<N;j++){
         m[j] = std::rand()%20;
         m_Im[j] = std::rand()%20;
         n[j] = std::rand()%20;
         n_Im[j] = std::rand()%20;
      }
      CComplexVector C1(m,m_Im),C2(n,n_Im), CP,CM;
      CP=C1+C2;
      CM=C1-C2;
      cs=C1*C2;
      for(size_t k=0;k<N;k++){
          if(((CP(k)-(C1(k)+C2(k)))>0.000001)||((CP[k]-(C1[k]+C2[k]))>0.000001)){
             corect--;
             cout<<C1(0)<<"\n";
             cout<<C2[0]<<"\n";
             cout<<CP(0)<<"\n";
          }  else
              if(((CM(k)-(C1(k)-C2(k)))>0.000001)||((CM[k]-(C1[k]-C2[k])>0.000001))){
                 corect--;
                 cout<<CP(0)<<"\n";
              }

      }
      for(size_t h=0;h<N;h++)
        {res+=(C1(h)*C2(h)-C1[h]*C2[h]+C1(h)*C2[h]-C1[h]*C2(h));

        }
      if((cs-res)>0.000001){ corect--; cout<<55<<"\n";}
      res=0;
  }
  cout<<"Number of successful autotests: "<<corect<<"\n";
 
  return 0;
}
