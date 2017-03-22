/*
remove duplicates
*/
#include <boost/range/adaptor/transformed.hpp>
#include <boost/range/algorithm/copy.hpp>
#include <boost/assign.hpp>
#include <iterator>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void removeDuplicates(std::vector<int>& vec)
{
  std::vector<int> copy;
  map<int, int> map;

  for(vector<int>::iterator it=vec.begin(); it!=vec.end(); ++it)
  {
    if (map.find(*it) == map.end())
    {
      copy.push_back(*it);
    }

    map[*it] = 1;
  }
  vec = copy;
}

int main(int argc, const char* argv[])
{
    using namespace boost::assign;

    std::vector<int> input;
    input += 1,2,3,1,2,3,4,4,5,6;

    removeDuplicates(input);

    for (int i = 0 ; i < input.size(); i++)
            cout << input[i] << " ";
    cout << "\n";
    return 0;
}
