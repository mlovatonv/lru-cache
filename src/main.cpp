#include <iostream>

#include "lrucache.cpp"

int main() {
  ads::lrucache<char, int> lc(3);
  lc.insert_key_value_pair('b', 2);
  lc.insert_key_value_pair('a', 1);
  lc.insert_key_value_pair('c', 3);
  std::cout << *lc.get_most_recent_key() << std::endl;
  std::cout << *lc.get_value_from_key('a') << std::endl;
  std::cout << *lc.get_most_recent_key() << std::endl;
  lc.insert_key_value_pair('d', 4);
  std::cout << lc.get_value_from_key('b') << std::endl;
  lc.insert_key_value_pair('a', 5);
  std::cout << *lc.get_value_from_key('a') << std::endl;
  return 0;
}
