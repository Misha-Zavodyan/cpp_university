#include <iostream>   
#include <string>
#include "CComplexVector.h"
#define N 5
CComplexVector::CComplexVector()
{
  for(size_t i=0;i<N;i++)
   {
    this->Re[i]=0;
    this->Im[i]=0;
   }
}

CComplexVector::CComplexVector(float m[N],float n[N])
{
  for(size_t i=0;i<N;i++)
   {
    this->Re[i]=m[i];
    this->Im[i]=n[i];
   }
}

CComplexVector CComplexVector::operator+(const CComplexVector &x2) const
{
  CComplexVector res;
  for(size_t i=0;i<N;i++)
    {
      res.Re[i]=Re[i]+x2.Re[i];
      res.Im[i]=Im[i]+x2.Im[i];
    }
  return res;
}

CComplexVector CComplexVector::operator-(const CComplexVector &x2) const
{
  CComplexVector res;                                               
  for(size_t i=0;i<N;i++)
    {
     res.Re[i]=Re[i]-x2.Re[i];
     res.Im[i]=Im[i]-x2.Im[i];          
    }
  return res;
}

float CComplexVector::operator*(const CComplexVector &x2)
{
  float res=0;
  for(size_t i=0;i<N;i++)
    {res+=(Re[i]*x2.Re[i]-Im[i]*x2.Im[i]+Re[i]*x2.Im[i]-Im[i]*x2.Re[i]);
     
    }
  return res ;
}

std::ostream &operator<<(std::ostream &cout,const CComplexVector &x1)
{
  cout  << "[";
  for(size_t i=0;i<N;i++)
  {
    cout <<""<< x1.Re[i]<< "+"<<x1.Im[i]<<"i";
    if(i<(N-1)) cout <<", ";
  }
  cout  << "]\n";
  return cout;
}

float CComplexVector::operator()(std::size_t i)
{
  return Re[i];
}

float CComplexVector::operator[](std::size_t i)
{
  return Im[i];
}
