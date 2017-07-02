#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <boost/assign/list_of.hpp>
#include <boost/range/algorithm.hpp>
#include <math.h>

void display_result(const std::vector<int> vec) {
    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

struct compare {
  bool operator() (int i,int j) {
    return ((i*10 + j) > (j*10 + 1));
  }
} myCompare;

int findLargest(std::vector<int>& vector)
{
  std::sort(vector.begin(), vector.end(), myCompare);

  display_result(vector);

  int decimal = pow(10,vector.size()-1);
  int total = 0;
  for (auto& it : vector)
  {
    std::cout << it << std::endl;
    std::cout << it * decimal << std::endl;
    total += it * decimal;
    std::cout << total << std::endl;
    decimal /= 10;
  }
  return total;
}

TEST(FindLargest, 21) {
  std::vector<int> vec {1,2};
    ASSERT_EQ(21, findLargest(vec));
}

TEST(FindLargest, 10) {
  std::vector<int> vec {1,0};
    ASSERT_EQ(10, findLargest(vec));
}

TEST(FindLargest, 0) {
  std::vector<int> vec {0,0,0,0};
    ASSERT_EQ(0, findLargest(vec));
}

TEST(FindLargest, 9710) {
  std::vector<int> vec {0,1,9,7};
    ASSERT_EQ(9710, findLargest(vec));
}

TEST(FindLargest, 99768211210) {
  std::vector<int> vec {10, 68, 97, 9, 21, 12};
    ASSERT_EQ(99768211210, findLargest(vec));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
