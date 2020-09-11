#pragma once

namespace ads {

template <typename t_content>
class list {
 public:
  struct node {
    t_content content;
    node* next;
    node* prev;
  };

 private:
  node* head;
  node* tail;

 public:
  node* front();
  node* back();
  void pop_front();
  void push_back(t_content content);
  void move_back(node* new_tail);
};

}  // namespace ads
