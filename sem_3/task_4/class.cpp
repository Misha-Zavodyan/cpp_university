#include "class.h"

Darr::Darr()
{
  this->N=0;
  this->mylist.begin()=mylist.end();
}

Darr::Darr(size_t M)
{
  this->N=M;
  array<double,Con> zeroarr;
  for(size_t l=0;l<Con;++l){
      zeroarr[l]=0;
  }

  for(size_t j=0;j<(M/Con);++j){
    this->mylist.push_back(zeroarr); 
  }
  if(M%Con>0){ this->mylist.push_back(zeroarr);}
}

double Darr::push_back(double x)
{
  if(N%Con==0){
    mylist.push_back({x,0,0,0,0});
  } else {
    mylist.back()[N%Con]=x;
  }
  N++;
  return 0;
}

double Darr::insert(double x,size_t k)
{
  
  list <array<double,Con>>::iterator i=mylist.begin();
  if (k/Con!=0){
    advance(i, k/Con-1);
  } else {
    advance(i, (k/Con));
    array<double,Con> zeroarr;
    for(size_t l=0;l<Con;++l){
        zeroarr[l]=0;
    }
    mylist.push_back(zeroarr);
  }
  
  double tmp;
  size_t j=(k-1)%Con;
  for(;i!=mylist.end();i++){
    for(;j<Con;j++){
      tmp=(*i)[j];
      (*i)[j]=x;
      if(j!=4){
        x=(*i)[j+1];
        (*i)[j+1]=tmp;
      } else {
        list <array<double,Con>>::iterator t=i;t++;
        if(t!=mylist.end()){
          x=(*t)[0];
          (*t)[0]=tmp;
        }
      }
    }
    j=0;
  }
  N++;
  return 0;
}

double* Darr::operator[](std::size_t k)
{
  list <array<double,Con>>::iterator i=mylist.begin();
  if (k/Con!=0){
    advance(i, k/Con-1);
  } else {
    advance(i, (k/Con));
  }
  
  return &((*i)[(k-1)%Con]);
}

double Darr::delet(size_t k) 
{
    if(k>(N+1)){cerr << "Error delet k \n";return -1;}
  list <array<double,Con>>::iterator i=mylist.begin();
  if (k/Con!=0){
    advance(i, k/Con-1);
  } else {
    advance(i, (k/Con));
  }
  
  size_t j=(k-1)%Con;
  for(;i!=mylist.end();i++){
    for(;j<Con;j++){
      if(j!=4){
        (*i)[j]=(*i)[j+1];
      } else {
        list <array<double,Con>>::iterator t=i;t++;
        if(t!=mylist.end()){
          (*i)[j]=(*t)[0];
        }
      }
    }
    j=0;
  }
  N--;
  if (N%Con==0){
        mylist.pop_back();
  }
  return 0;
}

double Darr::size_arr(void)
{
  return N;
}
double Darr::resize_arr(size_t M)
{
  if(M>N){
    if((M/Con-N/Con)!=0){
      for(size_t i=0;i<(M/Con-N/Con);++i){
        mylist.push_back({0,0,0,0,0});
      }
    }
  } else if(M<N){
    if((N/Con-M/Con)!=0){
      for(size_t i=0;i<(N/Con-M/Con);++i){
        mylist.pop_back();
      }
    }
  }
  
  
  this->N=M;
  return 0;
}

double Darr::find(double x, size_t beg,size_t en)
{
  
  if(en==0) en=N;
  list <array<double,Con>>::iterator i=mylist.begin();
  if (beg!=0){
    if (beg/Con!=0){
      advance(i, beg/Con-1);
    } else {
      advance(i, (beg/Con));    
    }
  }

  clock_t begin = clock();
  size_t j=0;
  if (beg!=0){j=(beg-1)%Con;}
  for(;beg<en;++i){
    for(;j<Con;++j){
      if((abs((*i)[j]-x))<0.0000001) {
        cout<<x << " in array \n";
        clock_t end = clock();
        double elapsed_secs = double(end - begin) ;
        cout << "Find run time = " << elapsed_secs << " ms, array length: "<< this->N <<"\n";
        return 1;
      }
      ++beg;
        }
      j=0;
      }
    cout<<x << " not in array \n";

  clock_t end = clock();
  double elapsed_secs = double(end - begin) ;
  cout << "Find run time = " << elapsed_secs << " ms, array length: "<< this->N <<"\n";
  beg=0;en=0;
  return 0;
}

double Darr::sort(void) 
{
  list <array<double,Con>>::iterator i;

  double tmp;
  size_t l=0;
  clock_t begin = clock();
  for(size_t k=N-1;k!=0;--k) {
    l=0;
    if(l<k){
      i=mylist.begin();
      for(;i!=mylist.end();i++){
        for(size_t j=0;j<Con;j++){  
          if(j!=4){
            if((*i)[j]>(*i)[j+1]){
              tmp=(*i)[j];
              (*i)[j]=(*i)[j+1];
              (*i)[j+1]=tmp;
            }
          } else {
            list <array<double,Con>>::iterator t=i;t++;
            if(t!=mylist.end()){
              if((*i)[j]>(*t)[0]){
                tmp=(*i)[j];
                (*i)[j]=(*t)[0];
                (*t)[0]=tmp;
              }
            }
          }
        }  
      }
      l++;
    }
  }

  clock_t end = clock();
  double elapsed_secs = double(end - begin);
  cout << "Sort run time = " << elapsed_secs << " ms, array length: "<< this->N <<"\n";
  
  return 0;
}

std::ostream &operator<<(std::ostream &cout, Darr &x1)
{
  for(list <array<double,Con>>::iterator i= x1.mylist.begin();i!=x1.mylist.end();i++){
    for(size_t j=0;j<Con;j++){
      cout<< (*i)[j]<<" ";
    }
  }
  cout <<"   N:" << x1.N<<" ";
  cout <<"\n";
  return cout;
}
