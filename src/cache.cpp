#include "cache.hpp"

namespace ads {

template <typename t_key, typename t_value>
void cache<t_key, t_value>::insert_key_value_pair(t_key key, t_value value) {
  if (this->size == this->max_size) {
    this->evict();
    --this->size;
  }
  if (this->get_value_from_key(key) == nullptr) {
    ++this->size;
    this->insert(key, value);
  } else {
    this->update(key, value);
  }
}

}  // namespace ads
