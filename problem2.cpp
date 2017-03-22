/*
Given an array of integers, check if array contains a sub-array having 0 sum.
Also, prints end-points of all such sub-arrays.
*/

#include <iostream>
#include <vector>
#include <boost/assign/list_of.hpp>
#include <boost/unordered_map.hpp>
using namespace std;

bool subArraySumZero(const vector<int>& vec)
{
  typedef boost::unordered::unordered_map<int, int> mymap;
  mymap umap;

  umap[0] = -1;

  int sum = 0;

  for(vector<int>::size_type i = 0; i != vec.size(); i++)
  {
    sum += vec[i];

    if(umap.find(sum) != umap.end())
    {
       boost::unordered::unordered_map<int, int>::iterator it =
              umap.find(sum);

              while (it != umap.end() && it->first == sum)
              {
                  cout << "Subarray [" << (it->second + 1) << ".." << i <<
                                "]\n";
                  it++;
              }
    }

    umap.insert(pair<int, int>(sum, i));
  }
  return true;
}

int main()
{
    std::vector<int> v = boost::assign::list_of(3)(4)(-7)(3)(1)(3)(1)(-4)(-2)(-2);
    subArraySumZero(v);

    return 0;
}
