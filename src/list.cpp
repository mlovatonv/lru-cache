#include "list.hpp"

#include <memory>

namespace ads {

template <typename t_content>
list<t_content>::node* list<t_content>::front() {
  return this->head;
}

template <typename t_content>
list<t_content>::node* list<t_content>::back() {
  return this->tail;
}

template <typename t_content>
void list<t_content>::pop_front() {
  list<t_content>::node* old_head = this->head;
  this->head = this->head->next;
  this->head->prev = nullptr;
  free(old_head);
}

template <typename t_content>
void list<t_content>::push_back(t_content content) {
  list<t_content>::node* new_tail =
      new list<t_content>::node{content, nullptr, nullptr};
  list<t_content>::node* old_tail = this->tail;
  this->tail = new_tail;
  new_tail->prev = old_tail;
  old_tail->next = new_node;
}

template <typename t_content>
void list<t_content>::move_back(list<t_content>::node* new_tail) {
  list<t_content>::node* old_tail = this->tail;
  this->tail = new_tail;
  new_tail->prev->next = new_tail->next;
  new_tail->next->prev = new_tail->prev;
  old_tail->next = new_tail;
}

}  // namespace ads
