#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <gtest/gtest.h>

template<typename Container>
typename Container::value_type getSecond(const Container& c, std::random_access_iterator_tag)
{
  return c[2];
}

template<typename Container>
typename Container::value_type getSecond(const Container& c, std::bidirectional_iterator_tag)
{
  auto it = c.begin();
  std::advance(it, 2);
  return *it;
}

template<typename Container>
typename Container::value_type getSecond(const Container& c)
{
   auto tag = typename std::iterator_traits<
                    typename Container::iterator>::iterator_category{};
   return getSecond(c, tag);
}

int main()
{
  std::vector<int> v = {9, 10, 11, 23};
  std::vector<double> d = {9.1, 9.2, 9.3, 9.4};
  std::list<int> l = {1, 2, 3, 4};

  EXPECT_EQ(getSecond(v), 11);
  EXPECT_DOUBLE_EQ(getSecond(d), 9.3);
  EXPECT_EQ(getSecond(l), 3);

}
