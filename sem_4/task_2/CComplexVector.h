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
#define eps 1e-20
#define N 5 

using namespace std;

class CFabric;

class CComplexVector
{                                                 
  public:
  double Re[N];
  double Im[N];
  string fn;
  CComplexVector(){memset(Re, 0, sizeof(Re));memset(Im, 0, sizeof(Im));}
  CComplexVector(double Re[N],double Im[N]);
  virtual ~CComplexVector(){cout << "MyClass Destructor" << endl;}
  double &operator[] (size_t i) {return Re[i];}
  double &operator() (size_t i) {return Im[i];}
  void Show(){cout  << "[";for(size_t i=0;i<N;i++){cout <<""<< Re[i]<< "+"<<Im[i]<<"i";if(i<(N-1)) cout <<", ";}cout  << "]\n";}       
  virtual void output( string FileName=NULL)=0;
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
	CComplexVector1(double Re[N],double Im[N]): CComplexVector( Re, Im){}
  ~CComplexVector1() {cout << endl << "ChildClass1 Destructor" << endl;}
  void output( string FileName);
  CComplexVector1 &operator= (const CComplexVector &b) {if (this != &b) {for (int i=0; i < N; i++) {Re[i] = b.Re[i];Im[i] = b.Re[i];}} return *this;}
};

class CComplexVector2 : public CComplexVector
{
  public:
  CComplexVector2(): CComplexVector(){}
	CComplexVector2(double Re[N],double Im[N]): CComplexVector( Re, Im){}
  ~CComplexVector2() {cout << endl << "ChildClass2 Destructor" << endl;}
  void output( string FileName);
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

CComplexVector1 operator-(const CComplexVector &x1, const CComplexVector &x2) ;
CComplexVector2 operator+(const CComplexVector &x1, const CComplexVector &x2) ;
                             
 

#endif                            
