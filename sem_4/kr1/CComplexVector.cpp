#include "CComplexVector.h"
using namespace std;

CComplexVector::CComplexVector(double m[N])
{
  for(size_t i=0;i<N;i++)
   {
    this->Re[i]=m[i];
   }
}

int CComplexVector::Input(const char *name, vector <CComplexVector *> &v)
{
	ifstream f(name); string str;
  double tr;
  size_t i;
	while (getline(f, str))
	{
		stringstream ss(str); istream_iterator<string> it;
    
    //cout<< (stod(*it))<<endl;
		it = ss;
    //cout<< *it<<endl;
    tr=stod(*it);
      for (i = 0; i < 4 ; it++,i++){}
      tr+=stod(*it);
      for (i = 4; i <9 ; it++,i++){}
      tr+=stod(*it);
    cout<< tr<<endl;
    ss=stringstream(str);
    it=ss;
    //cout<< (stod(*it))<<endl;
		if (it != istream_iterator<string>())
		{      
			if (tr > eps)
			{
				CComplexVector1 *w = new CComplexVector1;  
				//cout << "\n|" << *it << "|\n";
				for (i = 0; i < N*2 && it != istream_iterator<string>(); ++it) 
        {
          //cout << *it<<' '<< i/2 << "|\n";
            (*w)[i] = stod(*it);
            i++; 
        }
				v.push_back(w);
			}
			if (tr < eps)
			{
				CComplexVector2 *w = new CComplexVector2;
				//cout << "\n|" << *it << "|\n"; 
				for (i = 0; i < N && it != istream_iterator<string>(); ++it)
        {
            (*w)[i] = stod(*it);
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
    out  << "Class1 \n";
    for(size_t i=0;i<N;i++)
    {
      out << Re[i]<< " ";
      if(i%3==2)
        out <<"\n";
    }   
}

void CComplexVector2 :: output( string FileName)
{
    ofstream out(FileName.c_str(), std :: ios_base :: app);    
    out  << "Class2 \n";
    for(size_t i=0;i<N;i++)
    {
      out << Re[i]<< " ";
      if(i%3==2) 
        out <<"\n";
    }   
}
