#include "cache.hpp"

namespace ads {

template <typename t_key, typename t_value>
unsigned cache<t_key, t_value>::get_size() {
  return this->size;
}

}  // namespace ads
