#pragma once

namespace ads {

template <typename t_key, typename t_value>
class cache {
  private:
    unsigned size;
    unsigned max_size;
  public:
    cache(unsigned max_size) : size(0), max_size(max_size) {}
    unsigned get_size();
};

}  // namespace ads
