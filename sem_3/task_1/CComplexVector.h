#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <cassert>
#define N 5      
class CComplexVector
{                                                 
 float Re[N];
 float Im[N];
  public:
  CComplexVector();
  CComplexVector(float Re[N],float Im[N]);
        
  CComplexVector operator+(const CComplexVector &x2) const;
  CComplexVector operator-(const CComplexVector &x2) const;
  float operator*(const CComplexVector &x2);
  friend std::ostream &operator<<(std::ostream &out, const
  CComplexVector &x1);
  float operator()(std::size_t i);
  float operator[](std::size_t i);

};
                         
 

#endif                            
