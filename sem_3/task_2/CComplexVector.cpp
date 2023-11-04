#include <iostream>   
#include <string>
#include <cmath>
#include "CComplexVector.h"

CComplexVector::CComplexVector()
{
  this->N=0;
  Re = nullptr;
  Im = nullptr;
}

CComplexVector::CComplexVector(std::size_t M)
{
  this->N=M;
  this->Re = new double[N];
  this->Im = new double[N];
  for(size_t i=0;i<N;i++)
   { 
    Re[i]=rand()%20;
    Im[i]=rand()%20;
   }
}

CComplexVector::~CComplexVector()
{
  std::cout << "Destructor for " << *this << std::endl;
  delete[] Re;
  delete[] Im;
  N=0;
}

CComplexVector CComplexVector::operator+(const CComplexVector &x2) const
{
  CComplexVector res(N);
  for(size_t i=0;i<N;i++)
    {
      res.Re[i]=Re[i]+x2.Re[i];
      res.Im[i]=Im[i]+x2.Im[i];
    }
  return res;
}

CComplexVector CComplexVector::operator-(const CComplexVector &x2) const
{
  CComplexVector res(N);                                               
  for(size_t i=0;i<N;i++)
    {
     res.Re[i]=Re[i]-x2.Re[i];
     res.Im[i]=Im[i]-x2.Im[i];          
    }
  return res;
}
CComplexVector::CComplexVector(const CComplexVector& x1)
{ 
  N=x1.N;
  Re = new double[N];
  Im = new double[N];
  
  for(size_t i=0;i<N;i++){
    Re[i]=x1.Re[i];
    Im[i]=x1.Im[i];
  }
   std::cout << "Copy for " << x1 << std::endl;
}

CComplexVector& CComplexVector::operator=(const CComplexVector &x1)
{
   N=x1.N;
   Re = new double[N];
   Im = new double[N];

   for(size_t i=0;i<N;i++){
     Re[i]=x1.Re[i];
     Im[i]=x1.Im[i];
   }
   return *this;
}

CComplexVector::CComplexVector( CComplexVector&& x2)
{
  N=x2.N;
  Re = x2.Re;
  Im = x2.Im;
  x2.Re = nullptr;
  x2.Im = nullptr;
  x2.N=0;
}

CComplexVector& CComplexVector::operator=( CComplexVector &&x2)
{
  delete[] Im;
  delete[] Re;
  N=x2.N;
  Re = x2.Re;
  Im = x2.Im;
  x2.N=0;
  x2.Re = nullptr;
  x2.Im = nullptr;
  return *this;
}

double CComplexVector::operator*(const CComplexVector &x2)
{
  double res=0;
  for(size_t i=0;i<N;i++)
    {res+=fabs((Re[i]*x2.Re[i]-Im[i]*x2.Im[i]+Re[i]*x2.Im[i]-Im[i]*x2.Re[i]));
     
    }
  return res ;
}

double CComplexVector::length()
{
  double res=0;
  res=sqrt( fabs((*this)*(*this)) );
  return res ;
}

std::ostream &operator<<(std::ostream &cout,const CComplexVector &x1)
{
  size_t M = x1.N;
  cout  << "[";
  for(size_t i=0;i<M;i++)
  {
    cout <<""<< x1.Re[i]<< "+"<<x1.Im[i]<<"i";
    if(i<(M-1)) cout <<", ";
  }
  cout  << "]\n";
  return cout;
}

double CComplexVector::operator()(std::size_t i)
{
  return Re[i];
}

double CComplexVector::operator[](std::size_t i)
{
  return Im[i];
}
