#include "CComplexVector.h"
using namespace std;

CComplexVector::CComplexVector(double M)
{
  (void)M;
  for(size_t i=0;i<N;i++)
   {
    this->Re[i]=rand();
    this->Im[i]=rand();
   }
}

int CComplexVector::Input(const char *name, vector <CComplexVector *> &v, vector<CFabric *> &fabric)
{
  ifstream f(name);
	string str;
	while (getline(f, str))
	{
		stringstream ss(str); istream_iterator<string> it;
		it = ss;
		if (it != istream_iterator<string>())
		{
      
			if (fabs(stod(*it) - 1) < eps)
			{
				CComplexVector *w = fabric[0] -> Create(); size_t i; ++it;
        ++it;
				for (i = 0; i < N*2 && it != istream_iterator<string>(); ++it) 
        {
          if(i%2==0)
            (*w)[i/2] = rand(); 
          else 
            (*w)(i/2) = rand();
          i++;
        }
				v.push_back(w);
			}
			if (fabs(stod(*it) - 2) < eps)
			{
				CComplexVector *w = fabric[1] -> Create(); size_t i; ++it; 
        ++it;
				for (i = 0; i < N*2 && it != istream_iterator<string>(); ++it)
        {
          if(i%2==0)
            (*w)[i/2] = rand(); 
          else 
            (*w)(i/2) = rand();
          i++;
        }
				v.push_back(w);
			}
		}
	}
	return 0;	         
}


CComplexVector* CComplexVector1::operator+( CComplexVector *x1) 
{
  
  CComplexVector1* res=new CComplexVector1;
  auto start = chrono::high_resolution_clock::now();
   #pragma omp parallel for                                            
    for(size_t i=0;i<N;i++)
      for(size_t j=0;j<40000;j++)
      {
        res->Re[i]=Re[i]+x1->Re[i];
        res->Im[i]=Im[i]+x1->Im[i];          
      }
    auto end = chrono::high_resolution_clock::now();

    std::cout << "parallel in: " << chrono::duration<double>(end - start).count() << " s\n" << endl;
    return res; 
}

CComplexVector* CComplexVector2::operator+( CComplexVector *x1) 
{
  
  CComplexVector2* res=new CComplexVector2;                                               
  auto start = chrono::high_resolution_clock::now();                                           
  for(size_t i=0;i<N;i++)
    for(size_t j=0;j<40000;j++)
    {
      res->Re[i]=Re[i]+x1->Re[i];
      res->Im[i]=Im[i]+x1->Im[i];          
    }
  auto end = chrono::high_resolution_clock::now();

  std::cout << "unparallel in: " << chrono::duration<double>(end - start).count() << " s\n" << endl;
  return res;
}

CComplexVector* CComplexVector::operator+( CComplexVector *x1) 
{
  CComplexVector *res;
  auto start = chrono::high_resolution_clock::now();
   #pragma omp parallel for                                            
    for(size_t i=0;i<N;i++)
      for(size_t j=0;j<40000;j++)
      {
        res->Re[i]=Re[i]+x1->Re[i];
        res->Im[i]=Im[i]+x1->Im[i];          
      }
    auto end = chrono::high_resolution_clock::now();

    std::cout << "parallel in: " << chrono::duration<double>(end - start).count() << " s\n" << endl;
    return res; 
}

CComplexVector& CComplexVector::operator=(const CComplexVector& vector)
{
  if (this == &vector)
    return *this;

  for(size_t i=0;i<N;i++)
  {
    Re[i]=vector.Re[i];
    Im[i]=vector.Im[i];          
  }

  return *this;
}

CComplexVector& CComplexVector :: operator=(CComplexVector&& vector)
{
  if (this == &vector)
    return *this;

  
  for(size_t i=0;i<N;i++)
  {
    Re[i]=vector.Re[i];
    Im[i]=vector.Im[i];          
  }

  return *this;
}

float operator*(const CComplexVector &x1,const CComplexVector &x2)
{
  float res=0;
  #pragma omp parallel  reduction (+: res)
  {
  # pragma omp for
    for(size_t i=0;i<N;i++)
      {
        res+=(x1.Re[i]*x2.Re[i]-x1.Im[i]*x2.Im[i]+x1.Re[i]*x2.Im[i]-x1.Im[i]*x2.Re[i]);
      }
  }
  return res ;
}

float operator/(const CComplexVector &x1,const CComplexVector &x2)
{
  float res=0;
    for(size_t i=0;i<N;i++)
      {
        res+=(x1.Re[i]*x2.Re[i]-x1.Im[i]*x2.Im[i]+x1.Re[i]*x2.Im[i]-x1.Im[i]*x2.Re[i]);
      }
  return res ;
}