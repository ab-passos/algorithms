/*
Find pair with given sum in the array
*/

#include <boost/assign/list_of.hpp>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Function to find a pair in an array with given sum using Hashing
void findPair(vector<int> vec, int sum)
{
    map<int, int> map;

    for(vector<int>::size_type i = 0; i != vec.size(); i++)
    {
        if (map.find(sum - vec[i]) != map.end())
        {
            std::cout << "Pair found at index " << map[sum - vec[i]] <<
                    " and " << i << "\n";
            return;
        }
        map[vec[i]] = i;
    }

    std::cout << "Pair not found" << "\n";
}

int main()
{
    std::vector<int> v = boost::assign::list_of(8)(7)(2)(5)(3)(1);
    int sum = 10;

    findPair(v, sum);
    return 0;
}
