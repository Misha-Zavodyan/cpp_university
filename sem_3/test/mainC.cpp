#include <iostream>
#include <list>
#include <iterator>


using namespace std;

int main()
{
    list<int> my;
    copy (my.begin(), my.end(), ostream_iterator<int>(cout, " "));

    return 0;
}