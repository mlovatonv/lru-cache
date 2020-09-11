#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <lrucache.cpp>

TEST(lrucachetest, list_should_work) {
  using namespace ads;
  list<int> l;

  l.push_back(1);
  l.push_back(2);
  l.push_back(3);

  EXPECT_EQ(l.front()->content, 1);
  EXPECT_EQ(l.front()->prev, nullptr);
  EXPECT_EQ(l.back()->content, 3);
  EXPECT_EQ(l.back()->next, nullptr);

  l.pop_front();

  EXPECT_EQ(l.front()->content, 2);
  EXPECT_EQ(l.front()->next, l.back());
  EXPECT_EQ(l.front()->prev, nullptr);
  EXPECT_EQ(l.back()->content, 3);
  EXPECT_EQ(l.back()->next, nullptr);
  EXPECT_EQ(l.back()->prev, l.front());

  l.move_back(l.front());

  EXPECT_EQ(l.front()->content, 3);
  EXPECT_EQ(l.front()->next, l.back());
  EXPECT_EQ(l.front()->prev, nullptr);
  EXPECT_EQ(l.back()->content, 2);
  EXPECT_EQ(l.back()->next, nullptr);
  EXPECT_EQ(l.back()->prev, l.front());

  l.pop_front();
  l.pop_front();
  l.pop_front(); // extra pop_front

  EXPECT_EQ(l.front(), nullptr);
  EXPECT_EQ(l.back(), nullptr);
}

TEST(lrucachetest, lrucache_should_work) {
  using namespace ads;
  lrucache<char, short> lc(3);

  lc.insert_key_value_pair('b', 2);
  lc.insert_key_value_pair('a', 1);
  lc.insert_key_value_pair('c', 3);

  EXPECT_EQ(*lc.get_most_recent_key(), 'c');
  EXPECT_EQ(*lc.get_value_from_key('a'), 1);
  EXPECT_EQ(*lc.get_most_recent_key(), 'a');

  lc.insert_key_value_pair('d', 4);

  EXPECT_EQ(lc.get_value_from_key('b'), nullptr);
  EXPECT_EQ(*lc.get_value_from_key('a'), 1);
  EXPECT_EQ(*lc.get_value_from_key('d'), 4);
  EXPECT_EQ(*lc.get_value_from_key('c'), 3);
  
  lc.insert_key_value_pair('a', 5);

  EXPECT_EQ(*lc.get_value_from_key('a'), 5);
  EXPECT_EQ(*lc.get_value_from_key('d'), 4);
  EXPECT_EQ(*lc.get_value_from_key('c'), 3);

  lc.insert_key_value_pair('x', 9);
  lc.insert_key_value_pair('a', 6);
  lc.insert_key_value_pair('z', 3);

  EXPECT_EQ(*lc.get_most_recent_key(), 'z');
  EXPECT_EQ(lc.get_value_from_key('b'), nullptr);
  EXPECT_EQ(lc.get_value_from_key('c'), nullptr);
  EXPECT_EQ(lc.get_value_from_key('d'), nullptr);
  EXPECT_EQ(*lc.get_most_recent_key(), 'z');
  
  EXPECT_EQ(*lc.get_value_from_key('a'), 6);
  EXPECT_EQ(*lc.get_value_from_key('z'), 3);
  EXPECT_EQ(*lc.get_value_from_key('x'), 9);
  EXPECT_EQ(*lc.get_most_recent_key(), 'x');
}
