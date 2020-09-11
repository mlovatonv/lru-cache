#pragma once

#define HASH_TABLE_SIZE 1000

#include <utility>

#include "cache.cpp"

namespace ads {

template <typename t_key, typename t_value>
class lrucache : public cache<t_key, t_value> {
  public:
    lrucache(unsigned max_size) : cache<t_key, t_value>(max_size) {}
};

}  // namespace ads
