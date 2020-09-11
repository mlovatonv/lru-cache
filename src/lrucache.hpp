#pragma once

#include <utility>

#include "cache.hpp"
#include "list.hpp"

#define HASH_TABLE_SIZE 1000

namespace ads {

template <typename t_key, typename t_value>
class lrucache : public cache<t_key, t_value> {
 private:
  list<std::pair<t_key, t_value>> ordered_list;
  typename list<std::pair<t_key, t_value>>::node* hash_table[HASH_TABLE_SIZE];

  size_t hash(t_key key);
  void evict();
  void insert(t_key key, t_value value);
  void update(t_key key, t_value value);

 public:
  lrucache(size_t max_size) : cache<t_key, t_value>(max_size) {}
  t_value* get_value_from_key(t_key key);
  t_key* get_most_recent_key();
};

}  // namespace ads
