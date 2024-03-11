#include "CComplexVector.h"

 
using namespace std;

int main()
{  
  double t,a,b;    
  vector<CComplexVector *> v; 
  CComplexVector1 cl,child1;
  CComplexVector2 child2;
  vector<CFabric *> fabric;
  fabric.push_back(new CFabric1);
	fabric.push_back(new CFabric2);
	CComplexVector::Input("data.txt", v,fabric);
	cout << "File input test" << endl << endl;

	//for (size_t i = 0; i < v.size(); ++i) v[i]->Show();

  cout << "2+3: \n";
  //(*v[1]).Show();
  //(*v[2]).Show();
  t=clock();
  child2 = (*v[2]) + (*v[3]);
  t=(clock()-t);
  printf ("Elapsed = %.2f clock\n", t);
 // child2.Show();
  cout << "\n" << endl;

  cout << "2-3: \n";
  //(*v[2]).Show();
  //(*v[3]).Show();
  t=clock();
  child1 = (*v[2]) - (*v[3]);
  t=(clock()-t);
  printf ("Elapsed = %.2f clock\n", t);
 // child1.Show();
  cout << "\n" << endl;
  
  cout << "2*3: \n";
  //(*v[2]).Show();
  //(*v[3]).Show();
  t=clock();
  a = (*v[2])* (*v[3]);
  t=(clock()-t);
  printf ("Elapsed = %.2f clock\n", t);
 // child1.Show();
  cout << "\n" << endl;

  cout << "2/3: \n";
  t=clock();
  b = (*v[2])/ (*v[3]);
  t=(clock()-t);
  printf ("Elapsed = %.2f clock\n", t);
  cout << "\n" << endl;

  if (fabs(a-b)<eps*(fabs(a)+fabs(b)))
      cout << "* == /" << endl;

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
