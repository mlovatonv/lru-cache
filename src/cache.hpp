#pragma once

#define size_t unsigned

namespace ads {

template <typename t_key, typename t_value>
class cache {
 private:
  size_t size;
  size_t max_size;
  virtual void evict() = 0;
  virtual void insert(t_key key, t_value value) = 0;
  virtual void update(t_key key, t_value value) = 0;

 public:
  cache(size_t max_size) : size(0), max_size(max_size) {}
  void insert_key_value_pair(t_key key, t_value value);
  virtual t_value* get_value_from_key(t_key key) = 0;
  virtual t_key* get_most_recent_key() = 0;
};

}  // namespace ads
