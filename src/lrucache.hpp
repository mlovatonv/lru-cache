#pragma once

#include <utility>

#include "cache.hpp"
#include "list.hpp"

#define HASH_TABLE_SIZE 1000

namespace ads {

template <typename t_key, typename t_value>
class lrucache : public cache<t_key, t_value> {
 private:
  typedef std::pair<t_key, t_value> pair;
  typedef list<pair> list;

  list ordered_list;
  list::node* hash_table[HASH_TABLE_SIZE];
  size_t hash(t_key key);
};

}  // namespace ads
