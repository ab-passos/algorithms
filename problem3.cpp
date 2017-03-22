/*
Rearrange even and odd numbers in an array in linear time such that all even numbers comes before all odd numbers
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/assign/list_of.hpp>
#include <boost/unordered_map.hpp>
using namespace std;

void rearrange(std::vector<int>& vec)
{
  int pivot=1, j=0;
  for(vector<int>::size_type i = 0; i != vec.size(); i++)
  {
    if(vec[i] % 2 != 0)
    {
      std::iter_swap(vec.begin()+i, vec.begin()+j);
      j++;
    }
  }
}

int main()
{
    std::vector<int> v = boost::assign::list_of(3)(4)(2)(5)(1)(6);
    rearrange(v);
    for (int i = 0 ; i < v.size(); i++)
            cout << v[i] << " ";
    cout << "\n";

    return 0;
}
