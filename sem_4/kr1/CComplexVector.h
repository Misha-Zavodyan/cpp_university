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
#define N 9

using namespace std;

class CComplexVector
{                                                 
  public:
  double Re[N];
  CComplexVector(){memset(Re, 0, sizeof(Re));}
  CComplexVector(double Re[N]);
  virtual ~CComplexVector(){cout << "MyClass Destructor" << endl;}
  double &operator[] (size_t i) {return Re[i];}
  //void Show(){cout  << "[";for(size_t i=0;i<N;i++){cout <<""<< Re[i]<< "+"<<Im[i]<<"i";if(i<(N-1)) cout <<", ";}cout  << "]\n";}       
  virtual void output( string FileName=NULL)=0;
  static int Input(const char *name, vector <CComplexVector *> &v);

};

class CComplexVector1 : public CComplexVector
{
  public:
  CComplexVector1(): CComplexVector(){}
	CComplexVector1(double Re[N]): CComplexVector( Re){}
  ~CComplexVector1() {cout << endl << "ChildClass1 Destructor" << endl;}
  void output( string FileName);
  CComplexVector1 &operator= (const CComplexVector &b) {if (this != &b) {for (int i=0; i < N; i++) {Re[i] = b.Re[i];}} return *this;}
};

class CComplexVector2 : public CComplexVector
{
  public:
  CComplexVector2(): CComplexVector(){}
	CComplexVector2(double Re[N]): CComplexVector( Re){}
  ~CComplexVector2() {cout << endl << "ChildClass2 Destructor" << endl;}
  void output( string FileName);
  CComplexVector2 &operator= (const CComplexVector &b) {if (this != &b) {for (int i=0; i < N; i++) {Re[i] = b.Re[i];}} return *this;}
};
                             
 

#endif                            
