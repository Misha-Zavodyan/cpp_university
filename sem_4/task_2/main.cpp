#include "CComplexVector.h"
#define N 5
 
using namespace std;

int main()
{      
  vector<CComplexVector *> v; CComplexVector1 cl,child1;CComplexVector2 child2;
  vector<CFabric *> fabric;
  fabric.push_back(new CFabric1);
	fabric.push_back(new CFabric2);
	CComplexVector::Input("data.txt", v,fabric);
	cout << "File input test" << endl << endl;

	for (size_t i = 0; i < v.size(); ++i) v[i]->Show();

  cout << "1+2: \n";
  (*v[1]).Show();
  (*v[2]).Show();
  child2 = (*v[1]) + (*v[2]);
  child2.Show();
  cout << "\n" << endl;

  cout << "2-3: \n";
  (*v[2]).Show();
  (*v[3]).Show();
  child1 = (*v[2]) - (*v[3]);
  child1.Show();
  cout << "\n" << endl;
        

  for (size_t i = 0; i < v.size(); i ++)
  {
    (*v[i]).output(v[i]->fn);
    delete v[i];
  }

	return 0;
}
