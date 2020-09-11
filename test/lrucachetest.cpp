#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <lrucache.cpp>

TEST(lrucachetest, should_work) {
  using namespace ads;
  lrucache<char, int> lc(3);

  lc.insert_key_value_pair('b', 2);
  lc.insert_key_value_pair('a', 1);
  lc.insert_key_value_pair('c', 3);

  EXPECT_EQ(*lc.get_most_recent_key(), 'c');
  EXPECT_EQ(*lc.get_value_from_key('a'), 1);
  EXPECT_EQ(*lc.get_most_recent_key(), 'a');

  lc.insert_key_value_pair('d', 4);

  EXPECT_EQ(lc.get_value_from_key('b'), nullptr);

  lc.insert_key_value_pair('a', 5);

  EXPECT_EQ(*lc.get_value_from_key('a'), 5);
}
