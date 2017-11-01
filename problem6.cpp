#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <boost/assign/list_of.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/algorithm/string/join.hpp>
#include <math.h>

/*
void display_result(const std::vector<std::string> vec) {
    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}
*/
struct compare {
  bool operator() (int i,int j) {
    std::string ij = std::to_string(i) + std::to_string(j);
    std::string ji = std::to_string(j) + std::to_string(i);
    std::cout << "compare = " << ij.compare(ji) << std::endl;
    return ij.compare(ji);
  }

  bool operator() (std::string i, std::string j)
  {
    std::cout << "i: " << i << "; j: " << j << std::endl;
    std::string ij = i + j;
    std::string ji = j + i;
    std::cout << ij << "," << ji << std::endl;
    std::cout << ij.compare(ji) << std::endl;
    return ji.compare(ij);
  }
} myCompare;

std::string findLargest(std::vector<std::string>& vector)
{
  std::sort(vector.begin(), vector.end(), myCompare);

  std::string result = boost::algorithm::join(vector,"");

  return result;
}

TEST(FindLargest, 21) {
  std::vector<std::string> vec {"1","2"};
    ASSERT_EQ("21", findLargest(vec));
}

TEST(FindLargest, 321) {
  std::vector<std::string> vec {"1","3","2"};
    ASSERT_EQ("321", findLargest(vec));
}

TEST(FindLargest, 0) {
  std::vector<std::string> vec {"0","0","0","0"};
    ASSERT_EQ("0", findLargest(vec));
}

TEST(FindLargest, 9710) {
  std::vector<std::string> vec {"0","1","9","7"};
    ASSERT_EQ("9710", findLargest(vec));
}

TEST(FindLargest, 21110) {
  std::vector<std::string> vec {"11","10","2"};
    ASSERT_EQ("21110", findLargest(vec));
}

TEST(FindLargest, 99768211210) {
  std::vector<std::string> vec {"10", "68", "97", "9", "21", "12"};
    ASSERT_EQ("99768211210", findLargest(vec));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
