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
  if (this->head == nullptr) return;
  auto old_head = this->head;
  if (old_head->next == nullptr) {
    this->head = this->tail = nullptr;
  } else {
    this->head = old_head->next;
    this->head->prev = nullptr;
  }
  delete old_head;
}

template <typename t_content>
void list<t_content>::push_back(t_content content) {
  auto new_tail = new list<t_content>::node{content, nullptr, nullptr};
  auto old_tail = this->tail;
  this->tail = new_tail;
  if (old_tail == nullptr) {
    this->head = new_tail;
  } else {
    old_tail->next = new_tail;
    this->tail->prev = old_tail;
  }
}

template <typename t_content>
void list<t_content>::move_back(list<t_content>::node* new_tail) {
  if (new_tail == nullptr or this->tail == nullptr or this->tail == new_tail)
    return;

  auto old_tail = this->tail;
  this->tail = new_tail;
  old_tail->next = new_tail;
  if (new_tail->prev != nullptr) new_tail->prev->next = new_tail->next;
  if (new_tail->next != nullptr) {
    new_tail->next->prev = new_tail->prev;
    if (this->head == new_tail) this->head = new_tail->next;
    new_tail->next = nullptr;
  }
  new_tail->prev = old_tail;
}

}  // namespace ads
