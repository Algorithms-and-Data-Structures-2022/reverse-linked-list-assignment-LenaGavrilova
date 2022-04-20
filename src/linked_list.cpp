#include "assignment/linked_list.hpp"

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    if (size_ > 0) {
      Node* curr_node = front_;
      Node* prev_node = nullptr;

      while (curr_node != back_) {
        Node* next = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next;
      }
      curr_node->next = prev_node;

      Node* back_node = back_;
      back_ = front_;
      front_ = back_node;
    }
  }

  /*
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    if (size_ > 0) {
      reverse_recursive_helper(front_, nullptr);
      Node* back_node = back_;
      back_ = front_;
      front_ = back_node;
    }
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    Node* node = curr->next;
    curr->next = prev;

    if (node != nullptr) {
      reverse_recursive_helper(node, curr);
    }
  }

}  // namespace assignment
