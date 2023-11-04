#ifndef DATE_H
#define DATE_H
#include<memory>
#include <iosfwd>
#include <string>
#include <cmath>
#include <cassert>
#include <iostream>
     
class CComplexVector
{   
 size_t N;                                              
 std::shared_ptr<double[]> a;                                             
 std::shared_ptr<double[]> b; 
 std::weak_ptr<double[]> Re;
 std::weak_ptr<double[]> Im;
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
  double retR(std::size_t i);
  double retI(std::size_t i);

};
                         
 

#endif                            
