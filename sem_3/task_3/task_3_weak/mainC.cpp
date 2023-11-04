#include "CComplexVector.h"

using namespace std;

int main()
{  
  size_t M=0;      
  int iter=0,cs=0,corect=0;
  float res=0;
  cout<<"Enter vector length: ";
  cin>>M;
  CComplexVector CC1(M),CC2(M),CC3;
  cout<< "Assignment copying" <<"\n";
  CC3=CC1;
  cout<< "First vector" <<"\n";
  cout<<CC1<<"\n";
  cout<< "Second vector" <<"\n";
  cout<<CC2<<"\n";
  cout<< "first * second vector" <<"\n";
  cout<<CC1*CC2<<"\n";
  cout<< "first + second vector" <<"\n";
  cout<<CC3<<"\n";
  cout<< "Assignment with move" <<"\n";
  CC3=CC1-CC2;
  cout<< "first - second vector" <<"\n";
  cout<<CC3<<"\n";
  cout<< "first length" <<"\n";
  cout<<CC1.length()<<"\n";


  cout<<"Enter the number of autotests: ";
  cin>>iter;
  corect=iter;
  for(int i=0;i<iter;i++){
      CComplexVector C1(M),C2(M), CP(M),CM(M);
      CP=C1+C2;
      CM=C1-C2;
      cs=C1*C2;
      cout<<CP<<"\n";
      cout<<C1<<"\n";

      for(size_t k=0;k<M;k++){
          if(((CP.retI(k)-(C1.retI(k)+C2.retI(k)))>0.000001)||((CP.retR(k)-(C1.retR(k)+C2.retR(k)))>0.000001)){
             corect--;
          }  else
              if(((CM.retI(k)-(C1.retI(k)-C2.retI(k)))>0.000001)||((CM.retR(k)-(C1.retR(k)-C2.retR(k))>0.000001))){
                 corect--;
                 cout<<CM<<"\n";
              }

      }
      for(size_t h=0;h<M;h++)
        {res+=fabs(C1.retI(h)*C2.retI(h)-C1.retR(h)*C2.retR(h)+C1.retI(h)*C2.retR(h)-C1.retR(h)*C2.retI(h));

        }
      if((cs-res)>0.000001)
      { 
         corect--;
      } else if((C1.length()-sqrt(fabs(C1*C1)))>0.000001){corect--;}
      res=0;
  }
  cout<<"Number of successful autotests: "<<iter<<"\n";
 
  return 0;
}
