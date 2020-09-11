#include<iostream>

#include "lrucache.hpp"

namespace ads {

template <typename t_key, typename t_value>
void lrucache<t_key, t_value>::evict() {
  auto node = this->ordered_list.front();
  unsigned index = this->hash(node->content.first);
  this->hash_table[index] = nullptr;
  this->ordered_list.pop_front();
}

template <typename t_key, typename t_value>
void lrucache<t_key, t_value>::insert(t_key key, t_value value) {
  this->ordered_list.push_back(std::make_pair(key, value));
  auto node = ordered_list.back();
  unsigned index = this->hash(key);
  this->hash_table[index] = node;
}

template <typename t_key, typename t_value>
void lrucache<t_key, t_value>::update(t_key key, t_value value) {
  unsigned index = this->hash(key);
  auto node = this->hash_table[index];
  node->content.second = value;
  this->ordered_list.move_back(node);
}

template <typename t_key, typename t_value>
t_value* lrucache<t_key, t_value>::get_value_from_key(t_key key) {
  unsigned index = this->hash(key);
  auto node = this->hash_table[index];
  if (node == nullptr) return nullptr;
  this->ordered_list.move_back(node);
  return &node->content.second;
}

template <typename t_key, typename t_value>
t_key* lrucache<t_key, t_value>::get_most_recent_key() {
  auto node = this->ordered_list.back();
  if (node == nullptr) return nullptr;
  return &node->content.first;
}

template <typename t_key, typename t_value>
unsigned lrucache<t_key, t_value>::hash(t_key key) {
  return (unsigned)key % HASH_TABLE_SIZE;
}

}  // namespace ads
