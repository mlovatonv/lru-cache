#include<iostream>

#include "lrucache.hpp"

int main() {
  ads::lrucache<char, int> lc(3);
  std::cout << lc.get_size() << std::endl;
  return 0;
}
