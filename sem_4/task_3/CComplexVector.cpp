#include "CComplexVector.h"
using namespace std;

CComplexVector::CComplexVector(double m[N],double n[N])
{
  for(size_t i=0;i<N;i++)
   {
    this->Re[i]=m[i];
    this->Im[i]=n[i];
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


CComplexVector1 operator-(const CComplexVector &x1, const CComplexVector &x2) 
{
  CComplexVector1 res;
   # pragma omp for                                            
    for(size_t i=0;i<N;i++)
      {
      res.Re[i]=x1.Re[i]+x2.Re[i];
      res.Im[i]=x1.Im[i]+x2.Im[i];          
      }
      //res.output("1.txt");
  //}    
    return res;
  
}

CComplexVector2 operator+(const CComplexVector &x1, const CComplexVector &x2) 
{
  CComplexVector2 res;                                               
  for(size_t i=0;i<N;i++)
    {
     res.Re[i]=x1.Re[i]+x2.Re[i];
     res.Im[i]=x1.Im[i]+x2.Im[i];          
    }
    //res.output("2.txt");
  return res;
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