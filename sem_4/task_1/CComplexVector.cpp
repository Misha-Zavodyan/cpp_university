#include "CComplexVector.h"
#define N 5
using namespace std;

CComplexVector::CComplexVector(double m[N],double n[N])
{
  for(size_t i=0;i<N;i++)
   {
    this->Re[i]=m[i];
    this->Im[i]=n[i];
   }
}

int CComplexVector::Input(const char *name, vector <CComplexVector *> &v)
{
	ifstream f(name); string str;
	while (getline(f, str))
	{
		stringstream ss(str); istream_iterator<string> it;
		it = ss;
		if (it != istream_iterator<string>())
		{
      
			if (fabs(stod(*it) - 1) < eps)
			{
				CComplexVector1 *w = new CComplexVector1; size_t i; ++it;
        w->fn= *it;++it;
				for (i = 0; i < N*2 && it != istream_iterator<string>(); ++it) 
        {
          if(i%2==0)
            (*w)[i/2] = stod(*it); 
          else 
            (*w)(i/2) = stod(*it);
          i++;
        }
				v.push_back(w);
			}
			if (fabs(stod(*it) - 2) < eps)
			{
				CComplexVector2 *w = new CComplexVector2; size_t i; ++it; 
        w->fn= *it;++it;
				for (i = 0; i < N && it != istream_iterator<string>(); ++it)
        {
          if(i%2==0)
            (*w)[i/2] = stod(*it); 
          else 
            (*w)(i/2) = stod(*it);
          i++;
        }
				v.push_back(w);
			}
		}
	}
	return 0;	         
}

void CComplexVector1 :: output( string FileName)
{
  ofstream out(FileName.c_str(), std :: ios_base :: app);    
  {out  << "[";for(size_t i=0;i<N;i++){out <<""<< Re[i]<< "+"<<Im[i]<<"i";if(i<(N-1)) out <<", ";}out  << "]\n";}
  out << endl;
}

void CComplexVector2 :: output( string FileName)
{
  ofstream out(FileName.c_str(), ios_base :: app);
  {out  << "[";for(size_t i=0;i<N;i++){out <<""<< Re[i]<< "+"<<Im[i]<<"i";if(i<(N-1)) out <<", \n";}out  << "]\n";}
      
  out << endl;
}

CComplexVector1 operator-(const CComplexVector &x1, const CComplexVector &x2) 
{
  CComplexVector1 res;                                               
  for(size_t i=0;i<N;i++)
    {
     res.Re[i]=x1.Re[i]-x2.Re[i];
     res.Im[i]=x1.Im[i]-x2.Im[i];          
    }
    res.output("2.txt");
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
    res.output("2.txt");
  return res;
}