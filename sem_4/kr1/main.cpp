#include "CComplexVector.h"
 
using namespace std;

int main()
{      
   vector<CComplexVector *> v; CComplexVector1 cl;
	CComplexVector::Input("data.txt", v);
	ofstream out("2.txt", ios_base :: trunc);
	
   for (size_t i = 0; i < v.size(); i ++)
    {
			//cout<<"12"<<endl;
        (*v[i]).output("2.txt");
        delete v[i];
    }

	return 0;
}
