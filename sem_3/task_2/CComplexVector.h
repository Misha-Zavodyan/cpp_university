#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <cassert>
     
class CComplexVector
{   
 size_t N;                                              
 double *Re ;
 double *Im ;
  public:
  CComplexVector();
  CComplexVector(std::size_t M);
  ~CComplexVector();
  double length();
       
  CComplexVector operator+(const CComplexVector &x2) const;
  CComplexVector operator-(const CComplexVector &x2) const;
  double operator*(const CComplexVector &x2);
  friend std::ostream &operator<<(std::ostream &out, const
  CComplexVector &x1);
  CComplexVector(const CComplexVector& x1);
  CComplexVector& operator=(const CComplexVector &x1);
  CComplexVector& operator=( CComplexVector &&x2);
  CComplexVector( CComplexVector&& x2);
  double operator()(std::size_t i);
  double operator[](std::size_t i);

};
                         
 

#endif                            
