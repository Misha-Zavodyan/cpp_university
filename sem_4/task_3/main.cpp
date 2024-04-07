#include "CComplexVector.h"

 
using namespace std;

int main()
{  
  double t,a,b,M=1;    
  vector<CComplexVector *> v; 
  CComplexVector1 cl,child1;
  CComplexVector2 child2;
  CComplexVector *ss1=new CComplexVector(M),*ss2;
  vector<CFabric *> fabric;
  fabric.push_back(new CFabric1);
	fabric.push_back(new CFabric2);
	CComplexVector::Input("data.txt", v,fabric);
	CComplexVector2* w2=new CComplexVector2(*v[0]), *w3=new CComplexVector2(*v[1]);
 // CComplexVector1* f2(M), f3(M);

  
  
  

  ss1 = *w2 + w3;
  ss2 = (*v[0])+v[1];
 
  
  // cout << "2*3: \n";
  // t=clock();
  // a = (*v[2])* (*v[3]);
  // t=(clock()-t);
  // printf ("Elapsed = %.2f clock\n", t);
  // cout << "\n" << endl;

  // cout << "2/3: \n";
  // t=clock();
  // b = (*v[2])/ (*v[3]);
  // t=(clock()-t);
  // printf ("Elapsed = %.2f clock\n", t);
  // cout << "\n" << endl;

  // if (fabs(a-b)<eps*(fabs(a)+fabs(b)))
  //     cout << "* == /" << endl;

  if ((fabs(child1[1]-child2[1])<eps)&&
  (fabs(child1[3]-child2[3])<eps) &&
  (fabs(child1[4]-child2[4])<eps))
      cout << "+ == -" << endl;
        

  // for (size_t i = 0; i < v.size(); i ++)
  // {
  //   (*v[i]).output(v[i]->fn);
  //   delete v[i];
  // }

	return 0;
}
