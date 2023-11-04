#include <iostream>   
#include <string>
#include <cmath>
#include "CComplexVector.h"

CComplexVector::CComplexVector()
{
  this->N=0;
  Re = std::shared_ptr<double[]>(new double[0]);
  Im = std::shared_ptr<double[]>(new double[0]);
}

CComplexVector::CComplexVector(std::size_t M)
{
  this->N=M;
  this->Re = std::shared_ptr<double[]>(new double[N]);
  this->Im = std::shared_ptr<double[]>(new double[N]);
  for(size_t i=0;i<N;i++)
   { 
    Re.get()[i]=rand()%20;
    Im.get()[i]=rand()%20;
   }
}

CComplexVector::~CComplexVector()
{
  std::cout << "Destructor for " << *this << std::endl;
  N=0;
}

CComplexVector CComplexVector::operator+(const CComplexVector &x2) const
{
  CComplexVector res(N);
  for(size_t i=0;i<N;i++)
    {
      res.Re.get()[i]=Re.get()[i]+x2.Re.get()[i];
      res.Im.get()[i]=Im.get()[i]+x2.Im.get()[i];
    }
  return res;
}

CComplexVector CComplexVector::operator-(const CComplexVector &x2) const
{
  CComplexVector res(N);                                               
  for(size_t i=0;i<N;i++)
    {
     res.Re.get()[i]=Re.get()[i]-x2.Re.get()[i];
     res.Im.get()[i]=Im.get()[i]-x2.Im.get()[i];          
    }
  return res;
}
CComplexVector::CComplexVector(const CComplexVector& x1)
{ 
  N=x1.N;
  Re = std::shared_ptr<double[]>(new double[N]);
  Im = std::shared_ptr<double[]>(new double[N]);
  
  for(size_t i=0;i<N;i++){
    Re.get()[i]=x1.Re.get()[i];
    Im.get()[i]=x1.Im.get()[i];
  }
   std::cout << "Copy for " << x1 << std::endl;
}

CComplexVector& CComplexVector::operator=(const CComplexVector &x1)
{
   N=x1.N;
   Re = std::shared_ptr<double[]>(new double[N]);
   Im = std::shared_ptr<double[]>(new double[N]);

   for(size_t i=0;i<N;i++){
     Re.get()[i]=x1.Re.get()[i];
     Im.get()[i]=x1.Im.get()[i];
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
    {res+=fabs((Re.get()[i]*x2.Re.get()[i]-Im.get()[i]*x2.Im.get()[i]+Re.get()[i]*x2.Im.get()[i]-Im.get()[i]*x2.Re.get()[i]));
     
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
    cout <<""<< x1.Re.get()[i]<< "+"<<x1.Im.get()[i]<<"i";
    if(i<(M-1)) cout <<", ";
  }
  cout  << "]\n";
  return cout;
}

double CComplexVector::operator()(std::size_t i)
{
  return Re.get()[i];
}

double CComplexVector::operator[](std::size_t i)
{
  return Im.get()[i];
}
