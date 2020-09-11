#include "list.hpp"

#include <memory>

namespace ads {

template <typename t_content>
typename list<t_content>::node* list<t_content>::front() {
  return this->head;
}

template <typename t_content>
typename list<t_content>::node* list<t_content>::back() {
  return this->tail;
}

template <typename t_content>
void list<t_content>::pop_front() {
  if (!this->head) return;
  list<t_content>::node* old_head = this->head;
  this->head = this->head->next;
  if (this->head)
    this->head->prev = nullptr;
  else
    this->tail = nullptr;
  delete old_head;
}

template <typename t_content>
void list<t_content>::push_back(t_content content) {
  list<t_content>::node* new_tail =
      new list<t_content>::node{content, nullptr, nullptr};
  list<t_content>::node* old_tail = this->tail;
  if (!this->head) this->head = new_tail;
  this->tail = new_tail;
  new_tail->prev = old_tail;
  if (old_tail) old_tail->next = new_tail;
}

template <typename t_content>
void list<t_content>::move_back(list<t_content>::node* new_tail) {
  list<t_content>::node* old_tail = this->tail;
  this->tail = new_tail;
  if (new_tail->prev) new_tail->prev->next = new_tail->next;
  if (new_tail->next) new_tail->next->prev = new_tail->prev;
  if (old_tail) old_tail->next = new_tail;
}

}  // namespace ads
