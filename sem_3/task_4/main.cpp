#include "class.h"

using namespace std;

int main()
{  
  size_t M=0;  
  M++;    
  Darr myDarr;
  size_t j=0;
  //Big O notation test
  cout<<"Enter the number of Big O test: ";
  cin>> j;
  for (size_t i=0 ;i< j; ++i) {


    myDarr.resize_arr(0);
    for(size_t i=0;i<5;i++)
      {
          myDarr.push_back(rand()%20);
      }
    //cout <<myDarr;
    myDarr.find(100);
    myDarr.sort();

    cout <<"*2"<<endl;
    myDarr.resize_arr(0);
    for(size_t i=0;i<(2*5);i++)
      {
          myDarr.push_back(rand()%20);
      }
    myDarr.find(100);
    myDarr.sort();

    cout <<"*4"<<endl;
    myDarr.resize_arr(0);
    for(size_t i=0;i<(4*5);i++)
      {
          myDarr.push_back(rand()%20);
      }
    myDarr.find(100);
    myDarr.sort();
    cout <<endl;
  }
  j=0;


  // cout<<"Enter the number of autotests: ";
  // cin>> j;
  for (size_t i=0 ;i< j; ++i) {



      myDarr.resize_arr(0);
      for(size_t i=0;i<21;i++)
        {
           myDarr.push_back(rand()%20);
        }

   //myDarr.print();
   myDarr.push_back(10);
   myDarr.push_back(2);
   myDarr.push_back(11);
   myDarr.push_back(21);
   myDarr.push_back(12);
   myDarr.push_back(23);
   myDarr.push_back(14);
   myDarr.push_back(24);
   myDarr.push_back(15);
   myDarr.push_back(25);
   myDarr.push_back(16);
   myDarr.push_back(26);
   myDarr.push_back(17);
   myDarr.push_back(27);
   myDarr.push_back(18);
   myDarr.push_back(28);
   myDarr.push_back(19);
   myDarr.push_back(29);
   cout <<myDarr;
  //*(myDarr.retur(10))=3;
  *(myDarr[10]) = -40;
   myDarr.sort();
  cout <<myDarr;
  myDarr.delet(1);
  myDarr.delet(10);
  myDarr.insert(56, 10);
  cout <<myDarr;
  myDarr.delet(100);
  cout <<myDarr;
  myDarr.resize_arr(2);
  cout<<endl;
    cout <<myDarr;
   myDarr.resize_arr(21);
     cout <<myDarr;
   myDarr.find(100);
     myDarr.find(100,2,11);
     
   



  
  cout <<myDarr;
  }
  return 0;
}
