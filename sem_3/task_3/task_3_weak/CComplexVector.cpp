#include "CComplexVector.h"

CComplexVector::CComplexVector()
{
  this->N=0;
  a = std::shared_ptr<double[]>(new double[0]);
  Re = a;
  b = std::shared_ptr<double[]>(new double[0]);
  Im = b;
}

CComplexVector::CComplexVector(std::size_t M)
{
  this->N=M;

  a = std::shared_ptr<double[]>(new double[N]);
  Re = a;
  b = std::shared_ptr<double[]>(new double[N]);
  Im = b;
  for(size_t i=0;i<N;i++)
   { 
      Re.lock().get()[i]=rand()%20;
      Im.lock().get()[i]=rand()%20;
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
      res.Re.lock().get()[i]=Re.lock().get()[i]+x2.Re.lock().get()[i];
      res.Im.lock().get()[i]=Im.lock().get()[i]+x2.Im.lock().get()[i];
    }
  return res;
}

CComplexVector CComplexVector::operator-(const CComplexVector &x2) const
{
  CComplexVector res(N);                                               
  for(size_t i=0;i<N;i++)
    {
     res.Re.lock().get()[i]=Re.lock().get()[i]-x2.Re.lock().get()[i];
     res.Im.lock().get()[i]=Im.lock().get()[i]-x2.Im.lock().get()[i];
    }
  return res;
}
CComplexVector::CComplexVector(const CComplexVector& x1)
{ 
  N=x1.N;
  a = std::shared_ptr<double[]>(new double[N]);
  Re = a;
  b = std::shared_ptr<double[]>(new double[N]);
  Im = b;
  
  for(size_t i=0;i<N;i++){
    Re.lock().get()[i]=x1.Re.lock().get()[i];
    Im.lock().get()[i]=x1.Im.lock().get()[i];
  }
   std::cout << "Copy for " << x1 << std::endl;
}

CComplexVector& CComplexVector::operator=(const CComplexVector &x1)
{
   N=x1.N;
   a = std::shared_ptr<double[]>(new double[N]);
   Re = a;
   b = std::shared_ptr<double[]>(new double[N]);
   Im = b;

   for(size_t i=0;i<N;i++){
     Re.lock().get()[i]=x1.Re.lock().get()[i];
     Im.lock().get()[i]=x1.Im.lock().get()[i];
   }
   return *this;
}

CComplexVector::CComplexVector( CComplexVector&& x2)
{
  N=x2.N;
  Re.lock() = x2.Re.lock();
  Im.lock() = x2.Im.lock();
//  x2.Re.lock() = nullptr;
//  x2.Im.lock() = nullptr;
  x2.N=0;
}

CComplexVector& CComplexVector::operator=( CComplexVector &&x2)
{
  N=x2.N;
  this->Re.lock() = x2.Re.lock();
  this->Im.lock() = x2.Im.lock();
  std::cout <<  Re.lock().get()[0] << std::endl;

  x2.N=0;
  //  x2.Re.reset();
  //  x2.Im.reset();
  std::cout <<  Im.lock().get()[0] << std::endl;
  return *this;
}

std::ostream &operator<<(std::ostream &cout,const CComplexVector &x1)
{
  size_t M = x1.N;
  cout  << "[";
  for(size_t i=0;i<M;i++)
  {
    cout <<""<< x1.Re.lock().get()[i]<< "+"<<x1.Im.lock().get()[i]<<"i";
    if(i<(M-1)) cout <<", ";
  }
  cout  << "]\n";
  return cout;
}

double CComplexVector::operator*(const CComplexVector &x2)
{
  double res=0;
  for(size_t i=0;i<N;i++)
    {res+=fabs((Re.lock().get()[i]*x2.Re.lock().get()[i]-Im.lock().get()[i]*x2.Im.lock().get()[i]+Re.lock().get()[i]*x2.Im.lock().get()[i]-Im.lock().get()[i]*x2.Re.lock().get()[i]));
     
    }
  return res ;
}

double CComplexVector::length()
{
  double res=0;
  res=sqrt( fabs((*this)*(*this)) );
  return res ;
}

double CComplexVector::retR(std::size_t i)
{
  return Re.lock().get()[i];
}

double CComplexVector::retI(std::size_t i)
{
  return Im.lock().get()[i];
}
