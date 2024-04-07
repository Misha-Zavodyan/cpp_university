#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <cstring>
#include <math.h>
#include <omp.h>
#include <time.h>
#include <chrono>
#include <memory>
#include <algorithm>
#define eps 1e-20
#define N 100000


using namespace std;

class CFabric;

class CComplexVector
{                                                 
  public:
  double Re[N];
  double Im[N];
  CComplexVector(){for(size_t i=0;i<N;i++){this->Re[i]=0;this->Im[i]=0;}}
  CComplexVector(double M);
  virtual ~CComplexVector(){cout << "";}
  CComplexVector(const CComplexVector &v)
  {
    for(size_t i=0;i<N;i++)
    {
      Re[i]=v.Re[i];
      Im[i]=v.Im[i];          
    }
  }
  CComplexVector(CComplexVector &&v)
  {
    for(size_t i=0;i<N;i++)
    {
      Re[i]=v.Re[i];
      Im[i]=v.Im[i];          
    }
  }
  double &operator[] (size_t i) {return Re[i];}
  double &operator() (size_t i) {return Im[i];}
  virtual CComplexVector* operator+( CComplexVector* x1);
  void Show(){cout  << "[";for(size_t i=0;i<N;i++){cout <<""<< Re[i]<< "+"<<Im[i]<<"i";if(i<(N-1)) cout <<", ";}cout  << "]\n";}       
  CComplexVector& operator=(const CComplexVector& vector);
  CComplexVector& operator=(CComplexVector&& vector);
  static int Input(const char *name, vector <CComplexVector *> &v, vector<CFabric *> &fabric);

};

class CFabric
{
	public:
	virtual CComplexVector *Create() = 0;
	virtual ~CFabric() {}; 
};

class CComplexVector1 : public CComplexVector
{
  public:
  CComplexVector1(): CComplexVector(){}
	CComplexVector1(double M): CComplexVector( M){}
  CComplexVector1(CComplexVector& v) : CComplexVector(v) {};
  ~CComplexVector1() {cout << "";}
  CComplexVector1(const CComplexVector1 &v) : CComplexVector(v) {};
  CComplexVector1(CComplexVector1&& v) : CComplexVector(v) {};
  CComplexVector* operator+( CComplexVector* x1);
  //void output( string FileName);
  CComplexVector1 &operator= (const CComplexVector &b) {if (this != &b) {for (int i=0; i < N; i++) {Re[i] = b.Re[i];Im[i] = b.Re[i];}} return *this;}
};

class CComplexVector2 : public CComplexVector
{
  public:
  CComplexVector2(): CComplexVector(){}
	CComplexVector2(double M): CComplexVector( M){}
  CComplexVector2(CComplexVector& v) : CComplexVector(v) {};
  ~CComplexVector2() {cout << "";}
  CComplexVector2(const CComplexVector2 &v) : CComplexVector(v) {};
  CComplexVector2(CComplexVector2&& v) : CComplexVector(v) {};
  CComplexVector* operator+( CComplexVector* x1);
  //void output( string FileName);
  CComplexVector2 &operator= (const CComplexVector &b) {if (this != &b) {for (int i=0; i < N; i++) {Re[i] = b.Re[i];Im[i] = b.Re[i];}} return *this;}
};

class CFabric1 : public CFabric
{
	public:
	virtual CComplexVector *Create(){return new CComplexVector1;}  
};

class CFabric2 : public CFabric
{
	public:
	virtual CComplexVector *Create(){return new CComplexVector2;}         
};

float operator*(const CComplexVector &x1,const CComplexVector &x2);
float operator/(const CComplexVector &x1,const CComplexVector &x2);                             
 

#endif                            
